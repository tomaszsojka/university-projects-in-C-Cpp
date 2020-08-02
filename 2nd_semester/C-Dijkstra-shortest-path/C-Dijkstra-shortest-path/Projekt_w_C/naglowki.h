#ifndef NAGLOWKI_H
#define NAGLOWKI_H

typedef struct krawedz
{
	double waga;
	struct krawedz * pnext;
	struct wierzcholek * pkoncowy;
	
}krawedz;

typedef struct wierzcholek
{
	int wartosc;
	struct krawedz * pkrawedzie;
}wierzcholek;

typedef struct graf
{
	int liczba_krawedzi;
	int dlugosc_l_wierzcholkow;
}graf;

typedef struct dane
{
	int w_poczatkowy;
	int w_koncowy;
	double waga;
	struct dane * pnext;
}dane;

typedef enum { true = 1, false = 0} bool;

typedef struct sciezka
{
	double dystans;
	int poprzednik;
}sciezka;

//listy
void dodawanie_na_kon_listy_danych(dane ** pphead, int w_pocz, int w_kon, double dlugosc);
void tworzenie_listy_sasiedztwa(graf graf_dane, dane * phead_danych_kraw, wierzcholek ** ptab_wierz);
krawedz * dodawanie_na_pocz_listy_kraw(krawedz * phead, double dlugosc);
void usun_liste_danych(dane ** pphead);
void usun_liste_kraw(krawedz ** pphead);
void usun_liste_sasiedztwa(wierzcholek ** ptab_wierz, int dlugosc_l_wierz);

//pliki
bool czy_istnieje(const char *nazwa);
void wierzcholki_i_krawedzie(const char * nazwa, graf * pgraf_dane, dane ** pphead_dane_kraw, double * suma_odleglosci);
void zapis_sciezek_do_pliku(FILE* plik, int idx_aktualny, int ilosc_przystankow, int ** tab_sciezek, sciezka * tab);

//sciezki
void inicjowanie_tablic(sciezka ** ptab, int dlugosc_l_wierz, bool ** pczy_przetworzone, double suma_odleglosci);
void wyznaczanie_sciezek(sciezka * tab, int dlugosc_l_wierz, bool * czy_przetworzone, wierzcholek * tab_wierz);
void zapis_sciezek(int *** tab_sciezek, sciezka * tab, int dlugosc_l_wierz);
void usun_tablice(sciezka ** ptab, bool ** pczy_przetworzone);
void usun_sciezki(int *** tab_sciezek, int dlugosc_l_wierz);

//komunikacja
void podaj_nazwe1();
char * nazwa_pliku();
void brak_pliku();
void blad();
int wierzcholek_startowy(int max_nr_w_plus_1);
void podaj_nazwe2();
void wyswietlanie_sciezek(int idx_aktualny, int ilosc_przystankow, int ** tab_sciezek, sciezka * tab);
#endif 

