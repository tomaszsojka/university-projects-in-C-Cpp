#include <iostream>
#include "operatory.h"
#include "klasa_element_planszy.h"
#include "klasa_dane_planszy.h"
#include "klasa_wyswietl.h"

#include "klasa_wypelnij.h"
#include "klasa_wspolrzedne.h"
#include <string>
#include <fstream>
#include "komunkiaty_wyjatki.h"

std::ostream & operator<<(std::ostream & s, element_planszy * ob)
{
	try
	{
		if (ob->get_czy_zyje())
		{
			return s << " O ";
		}
		else
			return s << " . ";
	}
	catch (std::string ex)
	{
		wyswietl_komunikat(ex);
	}
}


std::ostream & operator<<(std::ostream &s, wyswietl  &ob)
{
	try
	{
		if (ob.get_pocz())
		{
			element_planszy * tmp = ob.get_pocz();
			while (tmp)
			{
				s << tmp;
				if (tmp->getp())
					tmp = tmp->getp();
				else
				{
					s << std::endl;
					if (tmp->getd())
					{
						tmp = tmp->getd();
						while (tmp->getl())
							tmp = tmp->getl();
					}
					else
						tmp = nullptr;
				}
			}
		}	
	}
	catch (std::string ex)
	{
		wyswietl_komunikat(ex);
	}
	return s;
}

std::ifstream & operator>>(std::ifstream & plik, wspolrzedne & ob)
{

	if (plik)
	{
		try
		{
			int idx = 0;
			int l, roz;
			if (plik >> roz)
				ob.set_roz(roz);
			ob.stworz_tab_wsp(); // tworze tablice o podanym rozmiarze ^2 *2 (tylke zeby sie zmiescily wsp wszystkich pkt r x r )
			while (plik >> l)
			{
				ob.set_el_punktow(idx, l);
				idx++;
			}
			plik.close();

		}
		catch (std::string ex)
		{
			wyswietl_komunikat(ex);
		}
		return plik;
	}
	else
		throw kom_brak_pliku();
}
	


std::ofstream & operator<<(std::ofstream & plik, wyswietl & ob)
{
	if (plik)
	{
		try
		{
			if (ob.get_pocz())
			{
				element_planszy * tmp = ob.get_pocz();
				while (tmp)
				{
					plik << tmp;
					if (tmp->getp())
						tmp = tmp->getp();
					else
					{
						plik << std::endl;
						if (tmp->getd())
						{
							tmp = tmp->getd();
							while (tmp->getl())
								tmp = tmp->getl();
						}
						else
							tmp = nullptr;
					}
				}
				plik.close();
				return plik;
			}
		}
		catch (std::string ex)
		{
			wyswietl_komunikat(ex);
		}
	}
	else
		throw kom_brak_pliku();
}






