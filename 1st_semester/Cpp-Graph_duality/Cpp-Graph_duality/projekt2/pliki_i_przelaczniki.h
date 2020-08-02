
/** @file pliki_i_przelaczniki.h */

#ifndef PLIKI_I_PRZELACZNIKI_H
#define PLIKI_I_PRZELACZNIKI_H

#include "struktury_i_listy.h"


/** 
 * Funkcja do czytania parametrow.
 * @param ile ilosc potrzebnych parametrow 
 * @param argumenty tablica przechowujaca parametry
 * @param[out] nazwa_pliku_wejsciowego  plik z ktorego czytam krawedzie 
 * @param[out] nazwa_pliku_wyjsciowego plik do ktorego zapisuje sprawdzany graf, wynik przeszukiwania i jesli graf okaze sie byc dwudzielnym, dwie grupy wierzcholkow
 * @return true kiedy parametry zostaly wprowadzone poprawnie, false kiedy parametry nie zostaly wprowadzone lub zostaly wprowadzone niepoprawnie
 * @date 25.01.2018
 * @author Tomasz Sojka
 */
bool odczytaj_argumenty(int ile, char * argumenty[], std::string & nazwa_pliku_wejsciowego, std::string & nazwa_pliku_wyjsciowego);

/**
* Funkcja do wyszukiwania w pliku wierzcholka o najwyzszym numerze , potrzebna, aby lista wierzcholkow przy tworzeniu listy sasiedztwa byla odpowiedniej dlugosci
* @param nazwa nazwa pliku z grafem
* @return max+1, czyli maksymalny numer wierzcholka + 1 (poniewaz moze istniec wierzcholek 0)
* @date 25.01.2018
* @author Tomasz Sojka
*/
int ilosc_wierzcholkow(const std::string & nazwa);

/**
* Funkcja do zliczania ilosci krawedzi zapisanych w pliku, potrzebna przy tworzeniu listy sasiedztwa. Funkcja ignoruje puste linie, lub linie zawierajace tylko biale znaki 
* @param nazwa nazwa pliku z grafem
* @return licznik - ilosc linii zawierajacych krawedzi 
* @date 25.01.2018
* @author Tomasz Sojka
*/
int ilosc_krawedzi(const std::string & nazwa);

/**
* Funkcja sczytuje wierzcholki krawedzi zapisanych w pliku i zapisuje je na koniec listy jednokierunkowej, zeby pozniej wyciagac je od poczatku w dobrej kolejnosci
* @param nazwa nazwa pliku z grafem
* @param phead_kolejka glowa listy jednokierunkowej
* @return nic
* @date 25.01.2018
* @author Tomasz Sojka
*/
void czytanie_krawedzi(const std::string &nazwa, element_listy * &phead_listy_kraw_z_pliku);

/**
* Funkcja zapisuje wynik do pliku (krawedzi grafu, wynik sprawdzania dwudzielnosci i jesli graf okazal sie byc dwudzielnym, dwie grupy wierzcholkow )
* @param nazwa nazwa pliku do zapisu (jesli plik nie istnieje, zostanie utworzony)
* @param phead_listy_kraw_z_pliku glowa listy jednokierunkowej, z ktorej funkcja czyta krawedzi
* @param phead_listy_wierz glowa listy wierzcholkow tworzacej liste sasiedztwa
* @param phead_kolejki glowa kolejki do przechodzenia listy sasiedztwa
* @return nic
* @date 25.01.2018
* @author Tomasz Sojka
*/
void zapisywanie_krawedzi_i_dwudzielnosci(const std::string &nazwa, element_listy * phead_listy_kraw_z_pliku, wierzcholek * phead_listy_z_wierz, wierzcholek * phead_kolejki);

/**
* Funkcja sprawdza dwudzielnosc grafu poprzez przechodzenie go i kolorowanie wierzcholkow (ustawianie wartosci kolor ze struktury wierzcholek na 1 lub -1)
* @param phead_listy_wierz glowa listy wierzcholkow tworzacej liste sasiedztwa
* @param phead_kolejki glowa kolejki do przechodzenia listy sasiedztwa
* @return true kiedy udalo sie sprawdzic wszystkie wierzcholki i zadna krawedz nie ma wierzcholkow o tym samym kolorze, false, gdy sie nie udalo
* @date 25.01.2018
* @author Tomasz Sojka
*/
bool sprawdzanie_dwudzielnosci(wierzcholek * phead_listy_wierz, wierzcholek * phead_kolejka);

/**
* Funkcja sprawdza, czy podany plik istnieje
* @param nazwa nazwa pliku z grafem
* @return true jesli plik istnieje, false, gdy plik nie istnieje
* @date 25.01.2018
* @author Tomasz Sojka
*/
bool czy_plik_istnieje(const std::string &nazwa);

/**
* Funkcja bledu, wyswietlajaca odpowiedni komunikat, w zaleznosci od bledu
* @param ile ilosc potrzebnych parametrow
* @param argumenty tablica przechowujaca parametry
* @param nazwa_pliku_wejsciowego plik z grafem
* @param nazwa_pliku_wyjsciwego plik do zapisu
* @return nic
* @date 25.01.2018
* @author Tomasz Sojka
*/
void blad(int ile, char * argumenty[], std::string & nazwa_pliku_wejsciowego, std::string & nazwa_pliku_wyjsciowego);
#endif