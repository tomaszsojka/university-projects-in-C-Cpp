#include <stdio.h>
#include <stdlib.h>
#include "naglowki.h"

bool czy_istnieje(const char *nazwa)
{
	FILE *plik = fopen(nazwa, "r");
	if (plik)
	{
		fclose(plik);
		return true;
	}
	return false;
}

void wierzcholki_i_krawedzie(const char * nazwa, graf * pgraf_dane, dane ** pphead_dane_kraw, double * suma_odleglosci)
{
	int liczba1, liczba2, licznik = 0, max = 0;
	double waga;
	FILE * plik = fopen(nazwa, "r");
	if (plik)
	{
		while (!feof(plik))
		{
			fscanf(plik, "%d", &liczba1);
			licznik++;
			if (liczba1 > max)
				max = liczba1;
			fscanf(plik, "%d", &liczba2);
			if (liczba2 > max)
				max = liczba2;
			while (!fscanf(plik, "%lf", &waga))
			{
				getc(plik);
			}
			*suma_odleglosci += waga;
			dodawanie_na_kon_listy_danych(pphead_dane_kraw, liczba1, liczba2, waga);
		}
		pgraf_dane->liczba_krawedzi = licznik;
		pgraf_dane->dlugosc_l_wierzcholkow = max + 1;
		fclose(plik);
	}
	else
		blad();
}

void zapis_sciezek_do_pliku(FILE* plik, int idx_aktualny, int ilosc_przystankow, int ** tab_sciezek, sciezka * tab)
{
	fprintf(plik, "%3d : ", idx_aktualny);
	if (tab_sciezek[idx_aktualny][0] != -1)
	{
		for (int idx_kol = 0; idx_kol < ilosc_przystankow; idx_kol++)
		{
			if (idx_kol != ilosc_przystankow - 1)
				fprintf(plik, "%d->", tab_sciezek[idx_aktualny][idx_kol]);
			else
				fprintf(plik, "%d", tab_sciezek[idx_aktualny][idx_kol]);
		}
		fprintf(plik, " , koszt dojscia: %3.2lf\n", tab[idx_aktualny].dystans);
	}
	else
	{
		if (tab[idx_aktualny].dystans != 0)
			fprintf(plik, "Brak polaczenia\n");
		else
			fprintf(plik, "Wierzcholek startowy\n");
	}
}

