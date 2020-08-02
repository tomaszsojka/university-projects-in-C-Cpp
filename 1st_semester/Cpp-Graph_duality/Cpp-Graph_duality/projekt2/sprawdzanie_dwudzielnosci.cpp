#include <iostream>
#include "pliki_i_przelaczniki.h"



bool sprawdzanie_dwudzielnosci(wierzcholek * phead_listy_wierz, wierzcholek * phead_kolejki)
{
	for (phead_listy_wierz; phead_listy_wierz; phead_listy_wierz = phead_listy_wierz->pnext)
		if (phead_listy_wierz->odwiedzony == false) // jesli wierzcholek jest nieodwiedzony
		{
			phead_listy_wierz->kolor = 1;			//koloruje go na bialo (wartosc ustawaiam na 1)
			phead_listy_wierz->odwiedzony = true;
			dodawanie_na_koniec_kolejki(phead_kolejki, phead_listy_wierz); // dodaje do kolejki element o wartosciach phead_listy_wierz(kolor, odwiedzony, pkrawedzie)
			while (phead_kolejki) //dopoki cos jest w kolejce
			{
				auto glowny = zwracanie_poczatku_kolejki(phead_kolejki); // wyciagam wierzcholek z kolejki 
				
				for (auto tmp_kraw = glowny->pkrawedzie; tmp_kraw; tmp_kraw = tmp_kraw->pnext) // przesuwam sie po krawedziach wierzcholka
				{
					auto sasiad = tmp_kraw->pkoncowy; // koncowy wierzcholek krawedzi
					if (sasiad->kolor == glowny->kolor) // jesli kolory wierzcholkow krawedzi sa takie same, usuwam kolejke i zwracam false
					{
						while (phead_kolejki)
							usuwanie_z_poczatku_kolejki(phead_kolejki);
						return false;
					}
					if (sasiad->odwiedzony == false) // jesli sasaid nie jest odwiedzony, koloruje go na kolor odwrotny do glownego i oznaczam jako odwiedzony
					{
						sasiad->kolor = -glowny->kolor;
						sasiad->odwiedzony = true;
						dodawanie_na_koniec_kolejki(phead_kolejki, sasiad); // dodaje sasiada do kolejki
					}
				}
				usuwanie_z_poczatku_kolejki(phead_kolejki);	//usuwam jeden wierzcholek z poczatku kolejki
			}
		}
	return true;
}
