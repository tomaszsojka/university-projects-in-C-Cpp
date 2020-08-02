/** @file struktury_i_listy.h */
#ifndef STRUKTURY_I_LISTY_H
#define STRUKTURY_I_LISTY_H

struct wierzcholek;

/** struktura reprezentujaca w liscie sasiedztwa polaczenia wierzcholkow grafu z wierzcholkami koncowymi krawedzi  */
struct krawedz
{
	/** wierzcholek koncowy krawedzi */
	wierzcholek * pkoncowy;
	/** nastepna krawedz w liscie krawedzi  */
	krawedz * pnext;
};

/** struktura reprezentuje wierzcholki grafu  w liscie sasiedztwa*/
struct wierzcholek
{
	/** wartosc do sprawdzania dwudzielnosci, na poczatku wierzcholki sa niezakolorowane (wartosc jest rowna 0) */
	int kolor = 0;
	/** wartosc do sprawdzania dwudzielnosci, na poczatku wszystkie nieodwiedzone */
	bool odwiedzony = false;

	/** kolejny wierzcholek w liscie wierzcholkow */
	wierzcholek * pnext;
	/** wskaznik na pierwszy element listy krawedzi , ktorych poczatkiem jest ten wierzcholek*/
	krawedz * pkrawedzie;

};

/** struktura uzyta do przechowania krawedzi z pliku
i jako kolejka do przeszukiwania listy sasiedztwa */
struct element_listy
{
	/** wartosc wierzcholka  */
	int wartosc;
	/** wskaznik na nastepny wierzcholek  */
	element_listy * pnext;
};

/**
* Funkcja tworzy liste sasiedztwa
* @param liczba_wierz najwiekszy numer wieszcholka + 1 (moze istniec wierzcholek z numerem 0)
* @param liczba_kraw ilosc krawedzi grafu
* @param phead_listy_wierz glowa listy wierzcholkow tworzacej liste sasiedztwa
* @param phead_listy_kraw_z_pliku glowa listy jednokierunkowej, z ktorej funkcja bierze krawedzi
* @return nic
* @date 25.01.2018
* @author Tomasz Sojka
*/
void tworzenie_listy_sasiedztwa(int liczba_wierz, int liczba_kraw, wierzcholek * &phead_listy_wierz, element_listy * phead_listy_kraw_z_pliku);

/**
* Funkcja usuwa liste krawedzi podwieszona pod wierzcholek z listy sasiedztwa
* @param phead_listy_kraw glowa listy krawedzi 
* @return nic
* @date 25.01.2018
* @author Tomasz Sojka
*/
void usuwanie_listy_krawedzi(krawedz * &phead_listy_kraw);

/**
* Funkcja usuwa liste sasiedztwa
* @param phead_listy_wierz glowa listy wierzcholkow tworzacej liste sasiedztwa
* @return nic
* @date 25.01.2018
* @author Tomasz Sojka
*/
void usuwanie_listy_sasiedztwa(wierzcholek * &phead_listy_wierz);

/**
* Funkcja dodaje liczby calkowite(numery wierzcholkow) na koniec listy 
* @param phead_listy_kraw_z_pliku glowa listy jednokierunkowej, na ktora sa zapisywane wierzcholki
* @param wartosc numer dodawanego wierzcholka
* @return nic
* @date 25.01.2018
* @author Tomasz Sojka
*/
void dodawanie_na_koniec_listy(element_listy * &phead_listy_kraw_z_pliku, int wartosc);

/**
* Funkcja usuwa cala liste
* @param phead_listy glowa listy jednokierunkowej, na ktorej sa zapisane wierzcholki
* @return nic
* @date 25.01.2018
* @author Tomasz Sojka
*/
void usuwanie_listy(element_listy * &phead_listy);

/**
* Funkcja dodaje na koniec kolejki jeden element i przypisuje mu wszystkie dane(poza pnext) struktury wierzcholek, jakie posiada phead_listy_wierz
* @param phead_kolejki glowa listy jednokierunkowej (kolejki), na ktora sa zapisywane wierzcholki
* @param phead_listy_wierz glowa listy wierzcholkow
* @return nic
* @date 25.01.2018
* @author Tomasz Sojka
*/
void dodawanie_na_koniec_kolejki(wierzcholek * &phead_kolejki, wierzcholek * phead_listy_wierz);

/**
* Funkcja usuwa jeden element kolejki
* @param phead_kolejki glowa listy jednokierunkowej(kolejki)
* @return nic
* @date 25.01.2018
* @author Tomasz Sojka
*/
void usuwanie_z_poczatku_kolejki(wierzcholek * & phead_kolejki);

/**
* Funkcja zwraca adres jednego elementu z poczatku kolejki, z adresem zwrocone zostaja dane struktury wierzcholek tego elementu
* @param phead_kolejki glowa listy jednokierunkowej(kolejki)
* @return nic
* @date 25.01.2018
* @author Tomasz Sojka
*/
wierzcholek * zwracanie_poczatku_kolejki(wierzcholek *  phead_kolejki);

#endif 

