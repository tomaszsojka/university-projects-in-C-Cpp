#include <stdio.h>
#include <stdlib.h>
#include "naglowki.h"



typedef struct elem 
{
	int liczba;
	struct elem *prev;
}t_elem;

t_elem *push(t_elem *ost_element, int wartosc)
{
	if (!ost_element) // to samo co ost_element == NULL 
	{
		ost_element = (t_elem*)malloc(sizeof(t_elem));
		ost_element->liczba = wartosc;
		ost_element->prev = NULL;
	}
	else
	{
		t_elem *nowy_element;
		nowy_element = (t_elem*)malloc(sizeof(t_elem));
		nowy_element->liczba = wartosc;
		nowy_element->prev = ost_element;
		ost_element = nowy_element;
	}
	return ost_element;
}

void pop(t_elem *stos, int wartosc)
{
	t_elem *temp = stos;
	stos = stos->prev;
	temp->prev = NULL;
	free(temp);
}

void empty(t_elem *stos)
{
	if (stos->prev == NULL) printf("Stos jest pusty \n");
	else printf("Stos zawiera elementy \n");
}

void print(t_elem *stos)
{

}

int main()
{
	t_elem * wsk_na_ost_el_stosu = NULL;
	int a = 0, wartosc;
	while (a<5)
	{
		printf("Co chcesz zrobic? \n 1 - doadaj element \n 2 - usun element \n 3 - wypisz elementy \n  4 - sprawdz czy stos jest pusty \n");
		scanf("%d", &a);
		switch (a)
		{
		case 1:
			printf("Wprowadz dane liczbowa do stosu: ");
			scanf("%d", &wartosc);
			wsk_na_ost_el_stosu = push(wsk_na_ost_el_stosu, wartosc);
			break;
		case 2:
			push(&stack, wartosc);
			break;
		case 3:
			//print(&stack);
			break;
		case 4:
			//empty(&stack);
			break;
		}
	}
	return 0;
}

/*
int main(void)
{
	podaj_nazwe1();
	const char * nazwa =  nazwa_pliku();
	if (czy_istnieje(nazwa))
	{
		double suma_odleglosci = 0;
		graf wymiary_grafu = { 0,0 };
		dane * dane_kraw = NULL;
		wierzcholki_i_krawedzie(nazwa, &wymiary_grafu, &dane_kraw, &suma_odleglosci);

		wierzcholek * tab_list_s = NULL;
		tworzenie_listy_sasiedztwa(wymiary_grafu, dane_kraw, &tab_list_s);

		sciezka *  tab = NULL;
		bool * czy_przetworzone = NULL;
		inicjowanie_tablic(&tab, wymiary_grafu.dlugosc_l_wierzcholkow, &czy_przetworzone, suma_odleglosci);
		wyznaczanie_sciezek(tab, wymiary_grafu.dlugosc_l_wierzcholkow, czy_przetworzone, tab_list_s);

		int ** sciezki = NULL;
		zapis_sciezek(&sciezki, tab, wymiary_grafu.dlugosc_l_wierzcholkow);

		usun_liste_danych(&dane_kraw);
		usun_liste_sasiedztwa(&tab_list_s, wymiary_grafu.dlugosc_l_wierzcholkow);
		usun_tablice(&tab, &czy_przetworzone);
		usun_sciezki(&sciezki, wymiary_grafu.dlugosc_l_wierzcholkow);
	}
	else
		brak_pliku();
	return 0;
}*/