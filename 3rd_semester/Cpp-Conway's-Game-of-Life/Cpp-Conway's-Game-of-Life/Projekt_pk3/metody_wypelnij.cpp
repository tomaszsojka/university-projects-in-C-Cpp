#include <iostream>
#include "klasa_element_planszy.h"
#include "klasa_dane_planszy.h"
#include "klasa_wypelnij.h"
#include "komunkiaty_wyjatki.h"

wypelnij::wypelnij() : punkty(nullptr)
{}


wypelnij::~wypelnij()
{
	if(punkty)
	usun_tab_wsp();

}

int * wypelnij::get_punkty()
{
	if (this)
		return punkty;
	else
	{
		throw kom_brak_ob_wypelnij();
		return nullptr;
	}
}

int wypelnij::get_el_punktow(int idx)
{
	if (this)
		return punkty[idx];
	else
	{
		throw kom_brak_ob_wypelnij();
		return -1;
	}
}

void wypelnij::set_punkty(int * p)
{
	if (this)
		punkty = p;
	else
		throw kom_brak_ob_wypelnij();
}

void wypelnij::set_el_punktow(int idx, int liczba)
{
	if(this)
	punkty[idx] = liczba;
	else
		throw kom_brak_ob_wypelnij();
}

void wypelnij::stworz_tab_wsp() // dodaj warunek na nic
{
	
	punkty = new int[2 * rozmiar * rozmiar]; //ilosc punktow *2, bo dwie wspolrzedne
	for (int i = 0; i < 2 * rozmiar * rozmiar; i++)
	{
		punkty[i] = -1;
	}
}

void wypelnij::usun_tab_wsp()
{
	if (punkty) // zabezpieczenie przed kilkukrotnym usunieciem 
	{
		delete[] punkty;
		punkty = nullptr;
	}
}

void wypelnij::wypelnij_plansze()
{
	try
	{
		if (punkty && ppoczatkowy) // jesli punkty wskazuje na cos i ppoczatkowy wskazuje na jakas plansze 
		{
			auto tmp = ppoczatkowy;
			int idx = 0,idx_jednow;
			while (idx < 2 * rozmiar * rozmiar && punkty[idx] != -1)
			{
				idx_jednow = punkty[idx];
				idx++;
				if (punkty[idx] != -1)
				{
					idx_jednow += punkty[idx] * rozmiar;
					tmp = (*this)[idx_jednow]; // uzycie przeciazonego operatora tablicowego
					tmp->set_czy_zyje(true);
				}
				else 
					throw kom_brak_wsp_y();
				idx++;
				tmp = ppoczatkowy;
			}
		}
	}
	catch (std::string ex)
	{
		wyswietl_komunikat(ex);
	}
}

element_planszy * wypelnij::operator[](size_t el)
{
	int idx = 0;
	auto tmp = ppoczatkowy;

	while (tmp && idx < el)
	{
		if (tmp->getp())
		{
			tmp = tmp->getp();
			idx++;
		}
		else
		{
			if (tmp->getd())
			{
				tmp = tmp->getd();
				while (tmp->getl())
					tmp = tmp->getl();
				idx++;
			}
			else
				tmp = nullptr;
		}
	}
	if (!tmp)
		throw kom_wsp_spoza_planszy();
	else if (idx == el)//jestem w dobrym miejscu
		return tmp;
}



