#include <stdio.h>
#include <stdlib.h>
#include "naglowki.h"

void inicjowanie_tablic(sciezka ** ptab, int dlugosc_l_wierz, bool ** pczy_przetworzone, double suma_odleglosci)
{
		*ptab = (sciezka*)malloc(dlugosc_l_wierz *sizeof(sciezka));
		*pczy_przetworzone = (bool*)malloc(dlugosc_l_wierz * sizeof(bool));

		for (int idx_tab = 0; idx_tab < dlugosc_l_wierz; idx_tab++)
		{
			(*ptab)[idx_tab].dystans = suma_odleglosci+1;
			(*ptab)[idx_tab].poprzednik = -1;
			(*pczy_przetworzone)[idx_tab] = false;
		}
}

void wyznaczanie_sciezek(sciezka * tab, int dlugosc_l_wierz, bool * czy_przetworzone, wierzcholek * tab_wierz)
{
	int idx_sprawdzanego, idx_szukanego, idx_sasiada;

	tab[wierzcholek_startowy(dlugosc_l_wierz)].dystans = 0;

	for (int licznik_wierz = 0; licznik_wierz < dlugosc_l_wierz; licznik_wierz++)
	{
		for (idx_sprawdzanego = 0; czy_przetworzone[idx_sprawdzanego]; idx_sprawdzanego++);
		for (idx_szukanego = idx_sprawdzanego++; idx_sprawdzanego < dlugosc_l_wierz; idx_sprawdzanego++)
		{
			if (!czy_przetworzone[idx_sprawdzanego] && (tab[idx_sprawdzanego].dystans < tab[idx_szukanego].dystans))
				idx_szukanego = idx_sprawdzanego;
		}
		czy_przetworzone[idx_szukanego] = true;

		krawedz * tmp;
		for (tmp = tab_wierz[idx_szukanego].pkrawedzie; tmp; tmp = tmp->pnext)
		{
			idx_sasiada = tmp->pkoncowy->wartosc;
			if (!czy_przetworzone[idx_sasiada] && (tab[idx_sasiada].dystans > tab[idx_szukanego].dystans + tmp->waga))
			{
				tab[idx_sasiada].dystans = tab[idx_szukanego].dystans + tmp->waga;
				tab[idx_sasiada].poprzednik = idx_szukanego;
			}
		}
	}
}

void zapis_sciezek(int *** tab_sciezek, sciezka * tab, int dlugosc_l_wierz)
{
	podaj_nazwe2();
	const char * nazwa =  nazwa_pliku();
	int idx_aktualny, idx_poprzednika,ptr, licznik;
	FILE * plik = fopen(nazwa, "w");
	if (plik)
	{
		*tab_sciezek = (int**)malloc(dlugosc_l_wierz * sizeof(int *));

		for (idx_aktualny = 0; idx_aktualny < dlugosc_l_wierz; idx_aktualny++)
		{
			licznik = 0;

			for (idx_poprzednika = idx_aktualny; idx_poprzednika > -1; idx_poprzednika = tab[idx_poprzednika].poprzednik)
				licznik++;

			if (licznik - 1)
			{
				(*tab_sciezek)[idx_aktualny] = (int*)malloc(licznik * sizeof(int));
				ptr = licznik - 1;
				for (idx_poprzednika = idx_aktualny; idx_poprzednika > -1; idx_poprzednika = tab[idx_poprzednika].poprzednik)
				{

					(*tab_sciezek)[idx_aktualny][ptr--] = idx_poprzednika;
				}
			}
			else
			{
				licznik = 1;
				(*tab_sciezek)[idx_aktualny] = (int*)malloc(sizeof(int));
				(*tab_sciezek)[idx_aktualny][0] = -1;
			}
			zapis_sciezek_do_pliku(plik, idx_aktualny, licznik, *tab_sciezek, tab);
			wyswietlanie_sciezek(idx_aktualny, licznik, *tab_sciezek, tab);
		}
		fclose(plik);
	}
	else
		blad();
}

void usun_tablice(sciezka ** ptab, bool ** pczy_przetworzone)
{
	free(*ptab);
	free(*pczy_przetworzone);
}

void usun_sciezki(int *** tab_sciezek, int dlugosc_l_wierz)
{
	for (int idx_tab = 0; idx_tab < dlugosc_l_wierz; idx_tab++)
	{
		free((*tab_sciezek)[idx_tab]);
	}
	free(*tab_sciezek);
}
