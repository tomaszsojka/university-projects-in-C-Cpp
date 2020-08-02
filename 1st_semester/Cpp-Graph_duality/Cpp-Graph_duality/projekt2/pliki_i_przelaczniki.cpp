#include<iostream>
#include <string>
#include <fstream>
#include "pliki_i_przelaczniki.h"
#include <iomanip>

using namespace std;

//przelaczniki
bool odczytaj_argumenty(int ile, char * argumenty[], string & nazwa_pliku_wejsciowego, string & nazwa_pliku_wyjsciowego) // !!!!
{
	const string ETYKIETA_NAZWA_WEJSCIOWA("-i");
	const string ETYKIETA_NAZWA_WYJSCIOWA("-o");
	const int FLAGA_NAZWA_WEJSCIOWA = 1;
	const int FLAGA_NAZWA_WYJSCIOWA = FLAGA_NAZWA_WEJSCIOWA << 1;

	const int POPRAWNY_WYNIK = FLAGA_NAZWA_WEJSCIOWA | FLAGA_NAZWA_WYJSCIOWA;

	int wynik = 0;
	for (int i = 1;i < ile - 1; i++)
	{
		string arg(argumenty[i]);
		if (arg == ETYKIETA_NAZWA_WEJSCIOWA)
		{
			nazwa_pliku_wejsciowego = argumenty[i + 1];
			wynik |= FLAGA_NAZWA_WEJSCIOWA;
		}
		if (arg == ETYKIETA_NAZWA_WYJSCIOWA)
		{
			nazwa_pliku_wyjsciowego = argumenty[i + 1];
			wynik |= FLAGA_NAZWA_WYJSCIOWA;
		}
	}

	if (wynik == POPRAWNY_WYNIK)
		return true;
	else
		return false;
}

//pliki
bool sprawdzenie_czy_pusta(const string & linia)
{
	int dlugosc = linia.length();
	for (int i = 0; i < dlugosc; i++)
	{
		if (linia[i] != '\t' && linia[i] != ' ')
			return false;
	}
	return true;
}
int ilosc_wierzcholkow(const string &nazwa)
{
	int liczba, max = 0;
	ifstream plik(nazwa);
	if (plik)
	{
		while (plik >> liczba)
		{
			if (liczba > max)
				max = liczba;
		}
		plik.close();
		return max + 1;
	}
	else
		return 0;
}
int ilosc_krawedzi(const string &nazwa)
{
	string linia;
	int licznik = 0;
	ifstream plik(nazwa);
	if (plik)
	{
		while (getline(plik, linia))
			if (!linia.empty() && sprawdzenie_czy_pusta(linia) == false)
				licznik++;
		plik.close();
		return licznik;
	}
	else
		return 0;
}
void czytanie_krawedzi(const string &nazwa, element_listy * &phead_lista_kraw_z_pliku) 
{
	ifstream plik(nazwa);
	if (plik)
	{
		int wartosc;
		while(plik>>wartosc)
			dodawanie_na_koniec_listy(phead_lista_kraw_z_pliku, wartosc); // wczytywanie do listy z krawedziami ()
		plik.close();
	}
	else
		usuwanie_listy(phead_lista_kraw_z_pliku);
}
void zapisywanie_krawedzi_i_dwudzielnosci(const string &nazwa, element_listy * phead_listy_kraw_z_pliku, wierzcholek * phead_lista_wierz, wierzcholek * phead_kolejki)
{
	ofstream plik(nazwa);
	if (plik)
	{
		int n = 6; // setw
		plik <<setw(2*n)<< "Graf :" << endl<<endl;// wypisywanie grafu do pliku

		int licznik = 0;
		while(phead_listy_kraw_z_pliku)			// liczba wierzcholkow krawedzi jest parzysta wiec bedzie sie poprawnie wypisywalo wypisywalo
		{							
				plik << setw(n) << phead_listy_kraw_z_pliku->wartosc;
				if (licznik % 2 != 0)				// co dwa wierzcholki koniec linii
				plik << endl;
				licznik++;
				phead_listy_kraw_z_pliku = phead_listy_kraw_z_pliku->pnext;
		}

		if (sprawdzanie_dwudzielnosci(phead_lista_wierz, phead_kolejki) == true) // jesli graf jest dwudzielny
		{
			plik << endl << " jest dwudzielny" << endl<<endl;
		// wypisywanie wierzcholkow w grupach
			
			licznik = 0; // elementy listy wierzcholkow nie maja numeru , wiec wprowadzam licznik
			auto tmp_wierz = phead_lista_wierz;
			plik << "grupa 1 : ";
			while(tmp_wierz) 
			{
				if (tmp_wierz->kolor == 1)
					plik << setw(n/3) << licznik;
				tmp_wierz = tmp_wierz->pnext;
				licznik++;
			}

			licznik = 0;
			tmp_wierz = phead_lista_wierz;
			plik << endl<< "grupa 2 : ";
			while(tmp_wierz)
			{
				if (tmp_wierz->kolor == -1)
					plik << setw(n / 3) << licznik;
				tmp_wierz = tmp_wierz->pnext;
				licznik++;
			}
		}
		else
			plik <<endl << "nie jest dwudzielny"<<endl;
			
		plik.close();
	}
}
bool czy_plik_istnieje(const string &nazwa) 
{
	fstream plik(nazwa);
	if (!plik)
		return false;
	else
		return true;

}

//bledy i komunikacja z uzytkownikiem
void blad(int ile, char * argumenty[], string & nazwa_pliku_wejsciowego, string & nazwa_pliku_wyjsciowego)
{
	if (odczytaj_argumenty(ile, argumenty, nazwa_pliku_wejsciowego, nazwa_pliku_wejsciowego) == false)
	{
		cout << " Bledne parametry, aby poprawnie uruchomic program wpisz w dowolnej kolejnosci: " << endl<<endl;
		cout << "    -i nazwa_pliku_z_grafem -o nazwa_pliku_do_zapisu " << endl;
		cout << "lub -o nazwa_pliku_do_zapisu -i nazwa_pliku_z_grafem " << endl;
	
	}
	else if (czy_plik_istnieje(nazwa_pliku_wejsciowego) == false  || ilosc_wierzcholkow(nazwa_pliku_wejsciowego) == 0)
		cout << "Brak pliku, niepoprawne rozszerzenie lub plik pusty !"<<endl;
	
}