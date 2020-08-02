#include <iostream>
#include "pliki_i_przelaczniki.h"


//lista sasiedztwa
void tworzenie_listy_sasiedztwa(int liczba_wierz, int liczba_kraw, wierzcholek * &phead_listy_wierz, element_listy * phead_listy_kraw_z_pliku) 
{

	for (int i = liczba_wierz-1; i >= 0; i--)
	{
		phead_listy_wierz = new wierzcholek{ 0, false,phead_listy_wierz,nullptr };

	}
	
	for (int i = 0; i < liczba_kraw; i ++)
	{
		auto wierz_tmp = phead_listy_wierz;
		auto wierz_tmp2 = phead_listy_wierz;

		for (int k = 0; k < phead_listy_kraw_z_pliku->wartosc; k++)//przesuwam sie po liscie wierzcholkow
		{
			wierz_tmp = wierz_tmp->pnext;

		}

		wierz_tmp->pkrawedzie = new krawedz{ phead_listy_wierz, wierz_tmp->pkrawedzie };

		for (int j = 0; j < phead_listy_kraw_z_pliku->pnext->wartosc; j++) // przesuwam wskaznik koncowy krawedzi, tyle razy ile wynosi nr wierzcholka poczatkowego
		{
			wierz_tmp->pkrawedzie->pkoncowy = wierz_tmp->pkrawedzie->pkoncowy->pnext;
		}

		for (int l = 0;l < phead_listy_kraw_z_pliku->pnext->wartosc;l++)
		{
			wierz_tmp2 = wierz_tmp2->pnext;
		}
		wierz_tmp2->pkrawedzie = new krawedz{ phead_listy_wierz, wierz_tmp2->pkrawedzie };
		for (int m = 0;m < phead_listy_kraw_z_pliku->wartosc; m++)
		{
			wierz_tmp2->pkrawedzie->pkoncowy = wierz_tmp2->pkrawedzie->pkoncowy->pnext;
		}
		phead_listy_kraw_z_pliku = phead_listy_kraw_z_pliku->pnext->pnext;
	}
}
void usuwanie_listy_krawedzi(krawedz * &phead_listy_kraw) 
{
	while (phead_listy_kraw) 
	{
		
		auto tmp = phead_listy_kraw;
		tmp->pkoncowy = nullptr;
		phead_listy_kraw = phead_listy_kraw->pnext;
		delete tmp;
	}
} 
void usuwanie_listy_sasiedztwa(wierzcholek * &phead_listy_wierz) 
{
		while (phead_listy_wierz) //dopoki pelement na cos wskazuje
		{
			usuwanie_listy_krawedzi(phead_listy_wierz->pkrawedzie );// usuwanie listy krawedzi
			auto tmp = phead_listy_wierz;
			phead_listy_wierz = phead_listy_wierz->pnext;
			delete tmp;
		}
}

//lista krawedzi z pliku
void dodawanie_na_koniec_listy(element_listy * &phead_listy_kraw_z_pliku, int wartosc) // lista z krawedziami z pliku
{
	if (!phead_listy_kraw_z_pliku)
		phead_listy_kraw_z_pliku = new element_listy{ wartosc, nullptr };
	else
	{
		auto tmp = phead_listy_kraw_z_pliku;
		while (tmp->pnext)
			tmp = tmp->pnext;
		tmp->pnext = new element_listy{ wartosc,nullptr };

	}
}
void usuwanie_listy(element_listy * &phead_listy) // usuwa cala liste 
{
	while(phead_listy) 
	{
		auto tmp = phead_listy;
		phead_listy = phead_listy->pnext;
		delete tmp;
	}
}

//kolejka
void dodawanie_na_koniec_kolejki(wierzcholek * &phead_kolejki, wierzcholek * phead_listy_wierz) // 
{
	if (!phead_kolejki) // nowy element kolejki ma kolor , odwiedzony i pkrawedzie jak phead_listy_wierzcholka
		phead_kolejki = new wierzcholek{ phead_listy_wierz->kolor, phead_listy_wierz->odwiedzony, nullptr, phead_listy_wierz->pkrawedzie };
	else
	{
		auto tmp = phead_kolejki;
		while (tmp->pnext) // przesuwam sie na koniec kolejki
			tmp = tmp->pnext;
		tmp->pnext = new wierzcholek{ phead_listy_wierz->kolor, phead_listy_wierz->odwiedzony, nullptr, phead_listy_wierz->pkrawedzie };
	}
}
void usuwanie_z_poczatku_kolejki(wierzcholek * &phead_kolejki)
{
	if (phead_kolejki) // usuwa jeden element // while i usunie wszystkie 
	{
		auto tmp = phead_kolejki;
		phead_kolejki = phead_kolejki->pnext;
		tmp->pkrawedzie = nullptr;
		delete tmp;
	}
}
wierzcholek * zwracanie_poczatku_kolejki(wierzcholek * phead_kolejki) // zwraca jeden element

{
	if (phead_kolejki) 
		return phead_kolejki;
	else    
		return nullptr;
}






