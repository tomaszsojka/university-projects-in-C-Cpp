#include <stdio.h>
#include <stdlib.h>
#include "naglowki.h"


void podaj_nazwe1()
{
	printf("Podaj nazwe pliku wejsciowego (nie zapomnij o rozszerzeniu) : \n");
}

char * nazwa_pliku()
{
	int licznik = 1, clear = 0; // licznik +1 dla '\0'
	char * nazwa = (char *)malloc(sizeof(char) * licznik);
	
	while ((clear = getchar()) != '\n' && clear != EOF)
	{
		nazwa[licznik - 1] = clear;
		licznik++;
		nazwa = (char *)realloc(nazwa, sizeof(char) * licznik);
	}
	nazwa[licznik - 1] = '\0';
	return  nazwa;
}



int wierzcholek_startowy(int max_nr_w_plus_1)
{
	printf("Podaj numer wierzcholka startowego : ");
	int nr_w, clear;
	while (1)
	{
		if (scanf("%d", &nr_w) && nr_w >=0 && nr_w < max_nr_w_plus_1)
		{
			getchar();
			return nr_w;
		}
		else
		{
			while ((clear = getchar()) != '\n' && clear != EOF) {}
			printf("Podaj nr wierzcholka!");
		}
	}
	return -1;

}

void podaj_nazwe2()
{
	printf("Podaj nazwe pliku wyjsciowego, gdzie zostana zapisane sciezki : \n");
}

void wyswietlanie_sciezek(int idx_aktualny, int ilosc_przystankow, int ** tab_sciezek, sciezka * tab)
{
	printf("%3d : ", idx_aktualny);
	if (tab_sciezek[idx_aktualny][0] != -1)
	{
		for (int idx_kol = 0; idx_kol < ilosc_przystankow; idx_kol++)
		{
			if(idx_kol != ilosc_przystankow-1)
			printf("%d->", tab_sciezek[idx_aktualny][idx_kol]);
			else
				printf("%d", tab_sciezek[idx_aktualny][idx_kol]);
		}
		printf(" , koszt dojscia: %3.2lf\n", tab[idx_aktualny].dystans);
	}
	else
	{
		if (tab[idx_aktualny].dystans != 0)
			printf("Brak polaczenia\n");
		else
			printf("Wierzcholek startowy\n");
	}
}

void brak_pliku()
{
	printf("Nie odnaleziono pliku o podanej nazwie");
}

void blad()
{
	printf("Cos poszlo nie tak przy otwieraniu pliku");
}