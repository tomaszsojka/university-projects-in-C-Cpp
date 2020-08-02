#include <iostream>
#include "klasa_element_planszy.h"
#include "klasa_dane_planszy.h"
#include "klasa_plansza.h"
#include "klasa_sasiedzi.h"
#include "klasa_element_listy_sasiadow.h"
#include "komunkiaty_wyjatki.h"




sasiedzi::sasiedzi() : pglowa(nullptr)
{
}
sasiedzi::~sasiedzi()
{
	if (pglowa)
		usun_liste_sasiadow();
}
void sasiedzi::rozszerz_w_dobra_strone() 
{
	try
	{
		if (ob->get_pocz()) // jesli ob wskazuje na jakas plansze
		{
			auto tmp = ob->get_pocz();
			auto tmp_poczatkowy = tmp;
			if (tmp->get_czy_zyje())	// sprawdzam najpierw pierwszy element, gdyby plansza miala tylko jeden element
				ob->rozszerz_plansze_w_gore(tmp);
			while (tmp->getp())	// dopoki moge przesuwam sie w prawo , zaczynam sprawdzanie od getp(), bo pierwszy sprawdzilem i dzieki temu sprawdze do ostatniego
			{
				if (tmp->getp()->get_czy_zyje() && !tmp->getp()->getg()) // jesli jest zywa komorka(musze rozszerzyc) i jeszcze nie jest rozszerzone
					ob->rozszerz_plansze_w_gore(tmp->getp());
				tmp = tmp->getp();
			}
			while (tmp->getd())
			{
				if (tmp->get_czy_zyje() && !tmp->getp())
					ob->rozszerz_plansze_w_prawo(tmp);
				tmp = tmp->getd();
			}
			if (tmp->get_czy_zyje() && !tmp->getp())
				ob->rozszerz_plansze_w_prawo(tmp);
			while (tmp->getl())
			{
				if (tmp->get_czy_zyje() && !tmp->getd())
					ob->rozszerz_plansze_w_dol(tmp);
				tmp = tmp->getl();
			}
			if (tmp->get_czy_zyje() && !tmp->getd())
				ob->rozszerz_plansze_w_dol(tmp);
			while (tmp != tmp_poczatkowy) // tmp_poczatkowy stoi na miejsu wczesniejszego ppoczatkowego, ktory mogl sie przesunac gdy plansza zostala rozszerzona  gore lub w prawo
			{
				if (tmp->get_czy_zyje() && !tmp->getl())
					ob->rozszerz_plansze_w_lewo(tmp);
				tmp = tmp->getg();
			}
			if (tmp->get_czy_zyje() && !tmp->getl())
				ob->rozszerz_plansze_w_lewo(tmp);
		}
	}
	catch (std::string ex)
	{
		wyswietl_komunikat(ex);
	}
}
element_listy_sasiadow * sasiedzi::operator+=(int l_s)
{
	if (!pglowa) //lista pusta
		pglowa = new element_listy_sasiadow(nullptr, l_s);
	else //juz cos jest
	{
		auto tmp = pglowa;
		while (tmp->getn())
			tmp = tmp->getn(); // przesuwanie do konca listy
		tmp->setn(new element_listy_sasiadow(nullptr, l_s));
	}
	return pglowa;
}
void sasiedzi::dodaj_na_koniec_listy_sasiadow(int l_s)
{
	try
	{
		(*this) += l_s; // uzycie przeciazonego operatora, dodaje element na koniec listy sasiadow
	}
	catch (std::string ex)
	{
		wyswietl_komunikat(ex);
	}
}
void sasiedzi::usun_liste_sasiadow()
{
	try
	{
		while (pglowa)
		{
			auto tmp = pglowa;
			pglowa = pglowa->getn();
			delete tmp;
		}
	}
	catch (std::string ex)
	{
		wyswietl_komunikat(ex);
	}
}
int sasiedzi::sprawdz_czy_krawedz(element_planszy * el)
{
	
	int jaka_pozycja = -1;
	try
	{
		if (ob  && el) // wskaznik ob wskazuje na jakas plansze, element nie wskazuje na nullptr 
		{
			if (!el->getp()) // prawa krawedz
			{
				jaka_pozycja = 0;
				if (!el->getd()) // prawy dolny rog
					jaka_pozycja += 10;
				else if (!el->getg()) // p g rog
					jaka_pozycja += 20;
			}
			else if (!el->getl()) // lewa krawedz
			{
				jaka_pozycja = 1;
				if (!el->getd()) // l d rog
					jaka_pozycja += 10;
				else if (!el->getg()) // l g rog
					jaka_pozycja += 20;
			}
			else if (!el->getd()) // dolna krawedz
				jaka_pozycja = 2;
			else if (!el->getg()) // gorna krawedz
				jaka_pozycja = 3;
		}
	}
	catch (std::string ex)
	{
		wyswietl_komunikat(ex);
	}
	return jaka_pozycja;
}
void sasiedzi::przesun_wezykiem_w_dol(element_planszy * &el, element_planszy * &el_za)
{
	try
	{
		if (el->getp() && el_za == el->getl())
		{
			el_za = el;
			el = el->getp();
		}
		else if (el->getl() && el_za == el->getp())
		{
			el_za = el;
			el = el->getl();

		}
		else if (el->getd() && (!el->getp() || !el->getl()))
		{
			el = el->getd();
			if (!el->getp())
				el_za = el->getp();
			else
				el_za = el->getl();
		}
		else
			el = nullptr;
	}
	catch (std::string ex)
	{
		wyswietl_komunikat(ex);
	}
}

void sasiedzi::policz_sasiadow()
{
	try
	{
		if (ob->get_pocz())
		{
			int licznik = 0, czy_na_krawedzi = -1;
			rozszerz_w_dobra_strone();
			auto tmp = ob->get_pocz();
			auto tmp_dla_sasiadow = tmp;
			auto tmp_za = tmp->getl();

			while (tmp)
			{
				czy_na_krawedzi = sprawdz_czy_krawedz(tmp);

				switch (czy_na_krawedzi)
				{
				case 0:	//na prawej krawedzi
					for (int i = 0; i < 5; i++)
					{
						if (i == 0)
							tmp_dla_sasiadow = tmp_dla_sasiadow->getg();
						else if (i == 1)
							tmp_dla_sasiadow = tmp_dla_sasiadow->getl();
						else if (i == 2 || i == 3)
							tmp_dla_sasiadow = tmp_dla_sasiadow->getd();
						else if (i == 4)
							tmp_dla_sasiadow = tmp_dla_sasiadow->getp();
						if (tmp_dla_sasiadow->get_czy_zyje())
							licznik++;
					}
					break;
				case 1:	//na lewej krawedzi
					for (int i = 0; i < 5; i++)
					{
						if (i == 0)
							tmp_dla_sasiadow = tmp_dla_sasiadow->getg();
						else if (i == 1)
							tmp_dla_sasiadow = tmp_dla_sasiadow->getp();
						else if (i == 2 || i == 3)
							tmp_dla_sasiadow = tmp_dla_sasiadow->getd();
						else if (i == 4)
							tmp_dla_sasiadow = tmp_dla_sasiadow->getl();
						if (tmp_dla_sasiadow->get_czy_zyje())
							licznik++;
					}
					break;
				case 2:	//na dole
					for (int i = 0; i < 5; i++)
					{
						if (i == 0)
							tmp_dla_sasiadow = tmp_dla_sasiadow->getp();
						else if (i == 1)
							tmp_dla_sasiadow = tmp_dla_sasiadow->getg();
						else if (i == 2 || i == 3)
							tmp_dla_sasiadow = tmp_dla_sasiadow->getl();
						else if (i == 4)
							tmp_dla_sasiadow = tmp_dla_sasiadow->getd();
						if (tmp_dla_sasiadow->get_czy_zyje())
							licznik++;
					}
					break;
				case 3:	//na gorze
					for (int i = 0; i < 5; i++)
					{
						if (i == 0)
							tmp_dla_sasiadow = tmp_dla_sasiadow->getp();
						else if (i == 1)
							tmp_dla_sasiadow = tmp_dla_sasiadow->getd();
						else if (i == 2 || i == 3)
							tmp_dla_sasiadow = tmp_dla_sasiadow->getl();
						else if (i == 4)
							tmp_dla_sasiadow = tmp_dla_sasiadow->getg();
						if (tmp_dla_sasiadow->get_czy_zyje())
							licznik++;
					}
					break;
				case 10: //prawy dolny rog
					for (int i = 0; i < 3; i++)
					{
						if (i == 0)
							tmp_dla_sasiadow = tmp_dla_sasiadow->getl();
						else if (i == 1)
							tmp_dla_sasiadow = tmp_dla_sasiadow->getg();
						else if (i == 2)
							tmp_dla_sasiadow = tmp_dla_sasiadow->getp();
						if (tmp_dla_sasiadow->get_czy_zyje())
							licznik++;
					}
					break;
				case 20:	//prawy gorny rog
					for (int i = 0; i < 3; i++)
					{
						if (i == 0)
							tmp_dla_sasiadow = tmp_dla_sasiadow->getl();
						else if (i == 1)
							tmp_dla_sasiadow = tmp_dla_sasiadow->getd();
						else if (i == 2)
							tmp_dla_sasiadow = tmp_dla_sasiadow->getp();
						if (tmp_dla_sasiadow->get_czy_zyje())
							licznik++;
					}
					break;
				case 11:	//lewy dolny rog
					for (int i = 0; i < 3; i++)
					{
						if (i == 0)
							tmp_dla_sasiadow = tmp_dla_sasiadow->getp();
						else if (i == 1)
							tmp_dla_sasiadow = tmp_dla_sasiadow->getg();
						else if (i == 2)
							tmp_dla_sasiadow = tmp_dla_sasiadow->getl();
						if (tmp_dla_sasiadow->get_czy_zyje())
							licznik++;
					}
					break;
				case 21:	//lewy gorny rog
					for (int i = 0; i < 3; i++)
					{
						if (i == 0)
							tmp_dla_sasiadow = tmp_dla_sasiadow->getp();
						else if (i == 1)
							tmp_dla_sasiadow = tmp_dla_sasiadow->getd();
						else if (i == 2)
							tmp_dla_sasiadow = tmp_dla_sasiadow->getl();
						if (tmp_dla_sasiadow->get_czy_zyje())
							licznik++;
					}
					break;
				default:
					for (int i = 0; i < 8; i++)
					{
						if (i == 0 || i == 6 || i == 7)
							tmp_dla_sasiadow = tmp_dla_sasiadow->getp();
						else if (i == 1)
							tmp_dla_sasiadow = tmp_dla_sasiadow->getd();
						else if (i == 2 || i == 3)
							tmp_dla_sasiadow = tmp_dla_sasiadow->getl();
						else if (i == 4 || i == 5)
							tmp_dla_sasiadow = tmp_dla_sasiadow->getg();
						if (tmp_dla_sasiadow->get_czy_zyje())
							licznik++;
					}
					break;
				}
				dodaj_na_koniec_listy_sasiadow(licznik);
				przesun_wezykiem_w_dol(tmp, tmp_za);
				tmp_dla_sasiadow = tmp;
				licznik = 0;
			}
		}
	}
	catch (std::string ex)
	{
		wyswietl_komunikat(ex);
	}
}