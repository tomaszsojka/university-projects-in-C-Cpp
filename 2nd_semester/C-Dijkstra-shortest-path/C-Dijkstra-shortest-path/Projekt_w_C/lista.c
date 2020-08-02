#include <stdio.h>
#include <stdlib.h>
#include "naglowki.h"

void dodawanie_na_kon_listy_danych(dane ** pphead, int w_pocz, int w_kon, double dlugosc)
{
	dane * nowy = (dane*)malloc(sizeof(dane));
	nowy->w_poczatkowy = w_pocz;
	nowy->w_koncowy = w_kon;
	nowy->waga = dlugosc;
	nowy->pnext = NULL;
	if (!(*pphead))
		*pphead = nowy;
	else
	{
		dane * tmp = *pphead;
		while (tmp->pnext)
			tmp = tmp->pnext;
		tmp->pnext = nowy;
	}
}

void tworzenie_listy_sasiedztwa(graf graf_dane, dane * phead_danych_kraw, wierzcholek ** ptab_wierz) 
{
	int wp, idx_wierz;
	*ptab_wierz = (wierzcholek*)malloc(graf_dane.dlugosc_l_wierzcholkow * sizeof(wierzcholek));
	for (idx_wierz = 0;idx_wierz < graf_dane.dlugosc_l_wierzcholkow ; idx_wierz++)
	{
		(*ptab_wierz)[idx_wierz].pkrawedzie = NULL;
		(*ptab_wierz)[idx_wierz].wartosc = idx_wierz;
		
	}
	for (idx_wierz = 0; idx_wierz < graf_dane.liczba_krawedzi; idx_wierz++)
	{
		wp = phead_danych_kraw->w_poczatkowy;
		(*ptab_wierz)[wp].pkrawedzie = dodawanie_na_pocz_listy_kraw((*ptab_wierz)[wp].pkrawedzie , phead_danych_kraw->waga);
		(*ptab_wierz)[wp].pkrawedzie->pkoncowy = &(*ptab_wierz)[phead_danych_kraw->w_koncowy];

		phead_danych_kraw = phead_danych_kraw->pnext;
	}
}



krawedz * dodawanie_na_pocz_listy_kraw(krawedz * phead, double dlugosc)
{
		krawedz * tmp = (krawedz*)malloc(sizeof(krawedz));
		tmp->pnext = phead;
		tmp->waga = dlugosc;
		tmp->pkoncowy = NULL;
		return phead = tmp;
}

void usun_liste_danych(dane ** pphead)
{
	while (*pphead)
	{
		dane *tmp = *pphead;
		*pphead = (*pphead)->pnext;
		free(tmp);
	}
}
void usun_liste_kraw(krawedz ** pphead)
{
	while (*pphead)
	{
		(*pphead)->pkoncowy = NULL;
		krawedz *tmp = *pphead;
		*pphead = (*pphead)->pnext;
		free(tmp);
	}
}

void usun_liste_sasiedztwa(wierzcholek ** ptab_wierz, int dlugosc_l_wierz)
{
	for (int idx_wierz = 0; idx_wierz < dlugosc_l_wierz; idx_wierz++)
	{
		usun_liste_kraw(&(*ptab_wierz)[idx_wierz].pkrawedzie);
	}
	free(*ptab_wierz);
}