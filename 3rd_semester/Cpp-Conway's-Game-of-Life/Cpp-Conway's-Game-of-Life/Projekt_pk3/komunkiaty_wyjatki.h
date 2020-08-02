#ifndef KOMUNIKATY_WYJATKI
#define KOMUNIKATY_WYJATKI
/**
* Funkcja wyswietla stringa o podanej nazwie.
* Jest uzywana do wyswietlania ewentualnych wyjatkow.
* Wyswietla inny komunikat w zaleznosci od tego, jaki wyjatek zostal wyrzucony.
*/
void wyswietl_komunikat(std::string str);

//wyjatki dane_planszy
/**
* Funkcja zwraca napis informujacy o wyjatku w klasie dane_planszy.
* Napis informuje o braku dostepu do obiektu klasy dane_planszy.
*/
std::string kom_brak_dost_do_ob_dane_planszy();

//wyjatki element_planszy
/**
* Funkcja zwraca napis informujacy o wyjatku w klasie element_planszy.
* Napis informuje o braku dostepu do obiektu klasy element_planszy.
*/
std::string kom_brak_ob_element_planszy();

//wyjatki wypelnij
/**
* Funkcja zwraca napis informujacy o wyjatku w klasie wypelnij.
* Napis informuje o braku dostepu do obiektu klasy wypelnij.
*/
std::string kom_brak_ob_wypelnij();
/**
* Funkcja zwraca napis informujacy o wyjatku w klasie wypelnij.
* Napis informuje o tym, ze wspolrzedna komorki do ozywienia wskazuje poza plansze.
* Wyjatek jest wyrzucony w metodzie wczytujacej dane z pliku(przy recznym wpisywaniu jest to od razu sprawdzane).
*/
std::string kom_wsp_spoza_planszy();
/**
* Funkcja zrwaca napis informujacy o wyjatku w klasie wypelnij.
* Napis informuje o braku drugiej wspolrzednej komorki do ozywienia.
*/
std::string kom_brak_wsp_y();

//wyjatki wyswietl
/**
* Funkcja zwraca napis informujacy o wyjatku w klasie wyswietl.
* Napis informuje o braku dostepu do obiektu klasy wyswietl.
*/
std::string kom_brak_ob_wyswietl();

//wyjatki operatory
/**
* Funkcja zwraca napis informujacy o wyjatku w przeciazonym operatorze.
* Napis informuje o braku dostepu do pliku o podanej nazwie.
*/
std::string kom_brak_pliku();

//wyjatki element_listy_sasiadow
/**
* Funkcja zwraca napis informujacy o wyjatku w klasie element_listy_sasiadow.
* Napis informuje o braku dostepu do obiektu klasy element_listy_sasiadow.
*/
std::string kom_brak_ob_element_listy_sasiadow();

#endif // !KOMUNIKATY_WYJATKI


