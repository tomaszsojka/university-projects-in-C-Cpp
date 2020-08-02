#ifndef KLASA_WSPOLRZEDNE
#define KLASA_WSPOLRZEDNE
/**
* Klasa sluzy do sczytywania wspolrzednych komorek do ozywienia(na planszy do gry w zycie) do tablicy dynamicznej punkty(pole klasy wypelnij).
* Jest klasa pochodna klasy wypelnij(ktora jest klasa pochodna klasy dane_planszy).
*
* Klasa zostala stworzona aby oddzielic operacje wczytania i wyswietlanie komunikatow zwiazanych z tym od logiki metod klasy sasiedzi. 
* Metody tej klasy zawieraja rowniez operacje zapobiegajace wpisaniu niepoprawnych danych.
* Wykozystana jest maszyna stanow.
* Zawera dodatkowo typ wyliczeniowy oraz metody.
*/
class wspolrzedne : public wypelnij
{
	enum stany { podaj, nie_liczba, spoza_zakresu, wyjdz };/*!< Typ wyliczeniowy stany utworzony dla metody wypelnij_tab_wsp, aby zapobiedz wprowadzeniu niepoprawnych danych przez uzytkownika. */
public:
	/**
	* Metoda sluzy do wprowadzenia rozmiaru kwardatowej planszy poczatkowej(dlugosc boku).
	*
	* Wyswietlany jest komunikat, ktory prosi uzytkonika o podanie rozmiaru planszy , tak aby zmiescily sie wszystkie komorki do ozywienia.
	* Nastepnie uzytkownik powinien podac ten rozmiar.
	* Operacja sie powtarza dopoki uzytkownik nie poda liczby naturalnej. Kazdorazowo przy wpisaniu niepoprawwnych danych wyswietlany jest odpowiedni komunikat.
	* \return nic
	*/
	void podaj_rozmiar_planszy();
	/**
	* Metoda sluzy do wypelnienia tablicy dynamicznej punkty(pole klasy wypelnij) przez uzytkownika(recznie).
	*
	* Najpierw sczytany jest rozmiar kwadratowej planszy poczatkowej(metoda podaj_rozmiar_planszy).
	* Tworzona jest tablica wspolrzednych punkty(metoda klasy wypelnij stworz_tab_wsp) o rozmiarze rozmiar * rozmiar * 2 (jest to ilosc komorek na planszy * 2(dwie wspolrzedne)).
	* Wyswitlony jest komunikat jak zakonczyc wpisywanie wspolrzednych komorek do ozywienia.
	* W petli wykorzystana jest maszyna stanow do pobrania od uzytkownika wspolrzednych.
	* Wyswietlany komentarz prosi uzytkownika o wybor sposobu wprowadzenia wspolrzednych komorek do ozywienia.
	* \return nic
	*/
	void wypelnij_tab_wsp();
	/**
	* Metoda sluzy do wypelnienia tablicy dynamicznej punkty(pole klasy wypelnij) z pliku o podanej nazwie.
	*
	* Najpierw zostaje wyswietlony komunikat proszacy o podanie nazwy pliku i wyjasniajacy jak beda interpretowane dane w pliku.
	* Po podaniu nazwy otwieranyn jest plik.
	* Wykorzystany przeciazony operator strumieniowy >>.
	* Jezeli plik nie istnieje, wyrzucany jest wyjatek przez ten operator. 
	* Jesli istnieje, dane zostaja wczytane z pliku w podany w komunikacie sposob.
	* \return nic
	*/
	void wypelnij_tab_wsp_z_pliku();
};
#endif // !KLASA_WSPOLRZEDNE

