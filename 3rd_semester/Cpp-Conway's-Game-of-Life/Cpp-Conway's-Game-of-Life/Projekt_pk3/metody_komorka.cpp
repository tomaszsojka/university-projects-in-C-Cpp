#include <iostream>
#include "klasa_element_planszy.h"
#include "klasa_dane_planszy.h"
#include "klasa_plansza.h"
#include "klasa_sasiedzi.h"
#include "klasa_komorka.h"
#include "klasa_element_listy_sasiadow.h"
#include "komunkiaty_wyjatki.h"

void komorka::ozyw_zabij_lub_zostaw()
{
	try
	{
		if (pglowa)
		{
			auto tmp_lista = pglowa;
			auto tmp = ob->get_pocz();
			auto tmp_za = tmp->getl();
			while (tmp_lista)  //dopoki tmp_lista wskazuje na el listy (elementow planszy jest tyle samo)
			{
				int liczba_s = tmp_lista->get_l_sasiadow();
				if (!tmp->get_czy_zyje()) //komorka nie zyla przed zmiana - jesli ma 3 s to ozywa
				{
					if (liczba_s == 3)
						tmp->set_czy_zyje(true);
				}
				else
					if (liczba_s < 2 || liczba_s > 3) // komorka zyla przed zmiana - jesli s<2 || s>3 to ginie
						tmp->set_czy_zyje(false);

				tmp_lista = tmp_lista->getn(); // przesuwam sie po liscie 
				przesun_wezykiem_w_dol(tmp, tmp_za); // przesuwam siê w dol po planszy
			}
			usun_liste_sasiadow();
		}
	}
	catch (std::string ex)
	{
		wyswietl_komunikat(ex);
	}
}

