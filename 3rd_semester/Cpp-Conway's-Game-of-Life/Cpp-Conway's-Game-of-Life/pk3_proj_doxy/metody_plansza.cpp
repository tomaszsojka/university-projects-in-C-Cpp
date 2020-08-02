
#include <iostream>
#include "klasa_element_planszy.h"
#include "klasa_dane_planszy.h"
#include "klasa_plansza.h"
#include "komunkiaty_wyjatki.h"


plansza::~plansza() 
{
	if (ppoczatkowy)
	{
		usun_plansze();
	}
}

element_planszy * plansza::stworz_element(element_planszy * pp, element_planszy *pl, element_planszy *pd, element_planszy *pg)
{
	element_planszy * nowy = new element_planszy();
	try
	{
		//nowy->getp()->getp(); //////
		nowy->setp(pp);
		nowy->setl(pl);
		nowy->setd(pd);
		nowy->setg(pg);
	}
	catch (std::string ex)
	{
		wyswietl_komunikat(ex);
	}
	return nowy;
}

void plansza::stworz_podstawowa_plansze()
{
	if (rozmiar) // jesli plansza ma byc o rozmiarze 0, to nic sie nie tworzy
	{
		try
		{
			ppoczatkowy = stworz_element(nullptr, nullptr, nullptr, nullptr);
			auto tmp_w_dol = ppoczatkowy;
			for (int j = 0; j < rozmiar - 1; j++)
			{
				tmp_w_dol->setd(stworz_element(nullptr, nullptr, nullptr, tmp_w_dol));
				tmp_w_dol = tmp_w_dol->getd();
			}
			tmp_w_dol = ppoczatkowy;
			auto tmp_w_prawo = ppoczatkowy;
			auto tmp_prawy_w_dol = ppoczatkowy;



			for (int i = 0; i < rozmiar - 1; i++) // x-1 bo bez poczatkowy
			{
				tmp_w_prawo->setp(stworz_element(nullptr, tmp_w_prawo, nullptr, nullptr));
				tmp_prawy_w_dol = tmp_w_prawo->getp();
				for (int j = 0;j < rozmiar - 1;j++)
				{
					tmp_prawy_w_dol->setd(stworz_element(nullptr, tmp_w_dol->getd(), nullptr, tmp_prawy_w_dol));
					tmp_w_dol->getd()->setp(tmp_prawy_w_dol->getd());

					tmp_prawy_w_dol = tmp_prawy_w_dol->getd();
					tmp_w_dol = tmp_w_dol->getd();
				}
				tmp_w_prawo = tmp_w_prawo->getp();
				tmp_w_dol = tmp_w_prawo;
			}
		}
		catch (std::string ex)
		{
			wyswietl_komunikat(ex);
		}
	}
}

void plansza::rozszerz_plansze_w_prawo(element_planszy * el )
{
	if (el && !el->getp()) // na wszelki wypadek jakby el nie byl na prawej krawedzi planszy
	{
		try
		{
			auto tmp_w_dol = el;
			while (tmp_w_dol->getg())
			{
				tmp_w_dol = tmp_w_dol->getg();
			}
			tmp_w_dol->setp(stworz_element(nullptr, tmp_w_dol, nullptr, nullptr));
			auto tmp_prawy_w_dol = tmp_w_dol->getp();
			while (tmp_w_dol->getd())
			{
				tmp_prawy_w_dol->setd(stworz_element(nullptr, tmp_w_dol->getd(), nullptr, tmp_prawy_w_dol));
				tmp_w_dol->getd()->setp(tmp_prawy_w_dol->getd());
				tmp_w_dol = tmp_w_dol->getd();
				tmp_prawy_w_dol = tmp_prawy_w_dol->getd();
			}
		}
		catch (std::string ex)
		{
			wyswietl_komunikat(ex);
		}
	}
}

void plansza::rozszerz_plansze_w_lewo(element_planszy * el)
{
	if (el && !el->getl())
	{
		try
		{
			auto tmp_w_dol = el;
			while (tmp_w_dol->getg())
			{
				tmp_w_dol = tmp_w_dol->getg();
			}
			tmp_w_dol->setl(stworz_element(tmp_w_dol, nullptr, nullptr, nullptr));
			auto tmp_lewy_w_dol = tmp_w_dol->getl();

			ppoczatkowy = tmp_lewy_w_dol; // ustawiam go na lewym gornym rogu
			while (tmp_w_dol->getd())
			{
				tmp_lewy_w_dol->setd(stworz_element(tmp_w_dol->getd(), nullptr, nullptr, tmp_lewy_w_dol));
				tmp_w_dol->getd()->setl(tmp_lewy_w_dol->getd());
				tmp_w_dol = tmp_w_dol->getd();
				tmp_lewy_w_dol = tmp_lewy_w_dol->getd();
			}
		}
		catch (std::string ex)
		{
			wyswietl_komunikat(ex);
		}
	}
}

void plansza::rozszerz_plansze_w_dol(element_planszy * el)
{
	if (el && !el->getd())
	{
		try
		{
			auto tmp_w_prawo = el;
			while (tmp_w_prawo->getl())
			{
				tmp_w_prawo = tmp_w_prawo->getl();
			}
			tmp_w_prawo->setd(stworz_element(nullptr, nullptr, nullptr, tmp_w_prawo));
			auto tmp_dolny_w_prawo = tmp_w_prawo->getd();
			while (tmp_w_prawo->getp())
			{
				tmp_dolny_w_prawo->setp(stworz_element(nullptr, tmp_dolny_w_prawo, nullptr, tmp_w_prawo->getp()));
				tmp_w_prawo->getp()->setd(tmp_dolny_w_prawo->getp());
				tmp_w_prawo = tmp_w_prawo->getp();
				tmp_dolny_w_prawo = tmp_dolny_w_prawo->getp();
			}
		}
		catch (std::string ex)
		{
			wyswietl_komunikat(ex);
		}
	}
}

void plansza::rozszerz_plansze_w_gore(element_planszy * el)
{
	if (el && !el->getg())
	{
		try
		{
			auto tmp_w_prawo = el;
			while (tmp_w_prawo->getl())
			{
				tmp_w_prawo = tmp_w_prawo->getl();
			}
			tmp_w_prawo->setg(stworz_element(nullptr, nullptr, tmp_w_prawo, nullptr));
			auto tmp_gorny_w_prawo = tmp_w_prawo->getg();

			ppoczatkowy = tmp_gorny_w_prawo;
			while (tmp_w_prawo->getp())
			{
				tmp_gorny_w_prawo->setp(stworz_element(nullptr, tmp_gorny_w_prawo, tmp_w_prawo->getp(), nullptr));
				tmp_w_prawo->getp()->setg(tmp_gorny_w_prawo->getp());
				tmp_w_prawo = tmp_w_prawo->getp();
				tmp_gorny_w_prawo = tmp_gorny_w_prawo->getp();
			}
		}
		catch (std::string ex)
		{
			wyswietl_komunikat(ex);
		}
	}
}

void plansza::usun_plansze()
{
	try
	{
		auto tmp = ppoczatkowy;
		while (ppoczatkowy)
		{
			tmp = ppoczatkowy;
			if (ppoczatkowy->getp())
			{
				ppoczatkowy = ppoczatkowy->getp();
				ppoczatkowy->setl(nullptr);
				if (ppoczatkowy->getp())
					ppoczatkowy->setd(nullptr);
				delete tmp;
			}
			else if (ppoczatkowy->getd())
			{
				ppoczatkowy = ppoczatkowy->getd();
				ppoczatkowy->setg(nullptr);
				if (ppoczatkowy->getl() || ppoczatkowy->getp())
					ppoczatkowy->setd(nullptr);
				delete tmp;
			}
			else if (ppoczatkowy->getl())
			{
				ppoczatkowy = ppoczatkowy->getl();

				ppoczatkowy->setp(nullptr);
				if (ppoczatkowy->getl())
					ppoczatkowy->setd(nullptr);
				delete tmp;
			}
			else
				ppoczatkowy = nullptr;
		}
	}
	catch (std::string ex)
	{
		wyswietl_komunikat(ex);
	}
}

plansza::operator int()
{
	int wiersze = 0, kolumny = 0;
	auto tmp = ppoczatkowy;
	while (tmp->getp())
	{
		tmp = tmp->getp();
		kolumny++;
	
	}
	while (tmp->getd())
	{
		tmp = tmp->getd();
		wiersze++;
	}
	return kolumny*wiersze;
}


