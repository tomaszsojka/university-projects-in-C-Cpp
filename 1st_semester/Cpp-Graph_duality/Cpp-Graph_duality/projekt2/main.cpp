#include <iostream>
#include "pliki_i_przelaczniki.h"
#include <string>
#include <fstream>


using namespace std;

int main(int argc, char* argv[] )
{
	string nazwa_pliku_wejsciowego, nazwa_pliku_wyjsciowego;

	if (odczytaj_argumenty(argc, argv, nazwa_pliku_wejsciowego, nazwa_pliku_wyjsciowego) == false || czy_plik_istnieje(nazwa_pliku_wejsciowego) == false || ilosc_wierzcholkow(nazwa_pliku_wejsciowego) == 0)
	{
		blad(argc, argv, nazwa_pliku_wejsciowego, nazwa_pliku_wyjsciowego);
		return 0;
	}
	
	int liczba_wierz , liczba_kraw;
	liczba_wierz = ilosc_wierzcholkow(nazwa_pliku_wejsciowego);  // liczba wierzcholkow w pliku
	liczba_kraw = ilosc_krawedzi(nazwa_pliku_wejsciowego);       // liczba krawedzi w pliku


	element_listy * lista_kraw_z_pliku_glowa = 0;  //wskaznik na liste, ktora tworze z krawedzi z pliku
	czytanie_krawedzi(nazwa_pliku_wejsciowego, lista_kraw_z_pliku_glowa); //sczytywanie krawedzi z pliku i zapisywanie wierzcholkow do listy
	

	wierzcholek * wierzcholek_glowa = 0; // wskaznik na liste wierzcholkow
	tworzenie_listy_sasiedztwa(liczba_wierz, liczba_kraw, wierzcholek_glowa, lista_kraw_z_pliku_glowa); // tworzenie listy sasiedztwa

	
	wierzcholek * kolejka_glowa = 0; // wskaznik na kolejke do przeszukiwania grafu
	zapisywanie_krawedzi_i_dwudzielnosci(nazwa_pliku_wyjsciowego, lista_kraw_z_pliku_glowa, wierzcholek_glowa, kolejka_glowa);

	usuwanie_listy_sasiedztwa(wierzcholek_glowa);
	usuwanie_listy(lista_kraw_z_pliku_glowa);
        

    return 0;
}