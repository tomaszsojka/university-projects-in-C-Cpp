#include <iostream>
#include "klasa_dane_planszy.h"
#include "klasa_wypelnij.h"
#include "klasa_wspolrzedne.h"
#include <string>
#include <fstream>

#include "operatory.h"
#include "komunkiaty_wyjatki.h"

void wspolrzedne::podaj_rozmiar_planszy()
{
	int clear = 0;
	std::cout << "Podaj rozmiar poczatkowej planszy kwadratowej, tak aby zmiescily sie wszystkie komorki do ozywienia : " << std::endl;
	while (clear != 'K')
	{
		std::cin >> rozmiar;
		if (!std::cin || rozmiar < 0)
		{
			std::cout << "Podaj rozmiar jeszcze raz" << std::endl;
			if (!std::cin)
			{
				std::cin.clear(); // czyszczenie flag bledu
				while ((clear = getchar()) != '\n' && clear != EOF);
			}

		}
		else
			clear = 'K';
	}
}
void wspolrzedne::wypelnij_tab_wsp()
{
	podaj_rozmiar_planszy();
	stworz_tab_wsp();
	int idx = 0, c = 0, K = 75, k = 107, tmp;	
	std::cout << "Aby zakonczyc wpisywanie wspolrzednych punkow nacisnij k lub K i zatwierdz ENTERem" << std::endl;
	stany stan = podaj;
	while (c!= K) 
	{
		switch (stan)
		{
		case podaj:
			if (!(idx % 2)) // jesli jest parzysty indeks
				std::cout << "Podaj pierwsza wspolrzedna komorki do ozywienia : " << std::endl;
			else
				std::cout << "Podaj druga wspolrzedna komorki do ozywienia : " << std::endl;

			std::cin >> tmp;
			if (!std::cin)
			{
				stan = nie_liczba;
			}
			else if (tmp < 0 || tmp >= rozmiar)
			{
				stan = spoza_zakresu;
			}
			else
			{
				punkty[idx] = tmp;
				idx++;
				if (idx >= 2 * rozmiar * rozmiar) // jesli ozywiono wszystkie bakterie
					stan = wyjdz;
			}
			break;
		case nie_liczba:
			std::cin.clear(); // czyszczenie flag bledu
			while ((c = getchar()) != '\n' && c != EOF && c != K && c != k); // czyszczenie niepoprawnych danych i endl, chyba, ze bylo k , to koniec wpisywania punktow
			if (c == K || c == k)
			{
				while ((c = getchar()) != '\n' && c != EOF); // czyszczenie do konca
				stan = wyjdz;
			}
			else
			{
				std::cout << "Podany index nie jest liczba naturalna!" << std::endl;
				stan = podaj;
			}
			break;
		case spoza_zakresu:
			std::cout << "Podany index jest jest spoza zakresu planszy!" << std::endl;
			stan = podaj;
			break;
		case wyjdz:
			c = K;
			std::cout << "Koniec wpisywania wspolrzednych do ozywienia" << std::endl;
			break;
		}
	}
}
void wspolrzedne::wypelnij_tab_wsp_z_pliku()
{
	std::string nazwa_pliku;
	int idx = 0;
	std::cout << "Podaj nazwe pliku z wspolrzednymi komorek do ozywienia. "<<std::endl 
		<<"Pierwsza liczba z pliku bedzie interpretowana jako rozmiar poczatkowej planszy kwadratowej. " << std::endl
		<<"Wspolrzedne sa pobierane w kolejnosci x->y (napierw kolumna)." << std::endl  ;
	std::cin >> nazwa_pliku;
	getchar();
	try
	{
		std::ifstream plik(nazwa_pliku);
		plik >> *this;
	}
	catch(std::string ex)
	{
		wyswietl_komunikat(ex);
	}
}