#ifndef KLASA_ELEMENT_LISTY_SASIADOW
#define KLASA_ELEMENT_LISTY_SASIADOW
/**
* Klasa reprezentuje element listy sasiadow. 
* Obiekt klasy zawiera dwa pola : wskaznik na nastepny element listy oraz liczbe sasiadow danego elementu planszy.
*/
class element_listy_sasiadow
{
private:
	element_listy_sasiadow * pnext;/*!< Pole pnext zawiera adres nastepnego elementu listy sasiadow. */
	int liczba_sasiadow = 0;/*!< Pole liczba_sasiadow zawiera ilosc "zywych" sasiadow elementu planszy do gry w zycie. Domyslnie jest rowne 0. */
public:
	/**
	* Konstruktor klasy element_listy_sasiadow.
	*
	* Nie ustawia zadnych wartosci.
	* Zostal stworzony na potrzebe konstuktora wieloargumentowego.
	*/
	element_listy_sasiadow();
	/**
	* Konstruktor klasy element_listy_sasiadow.
	*
	* Konstruktor przypisuje polom wartosci podane jako argumenty.
	* Zostal stworzony, aby szybciej tworzyc obiekty klasy element_listy_sasiadow.
	*/
	element_listy_sasiadow(element_listy_sasiadow * pn, int l_s);
	/**
	* Metoda zwraca pole pnext.
	*
	* Metoda zostala stworzona aby uzyskac dostep do pola pnext przez klasy niezaprzyjaznione i niepochodne.
	* Jesli cos poszlo nie tak i nie ma dostepu do obiektu klasy dane_planszy (lub obiektu klasy pochodnej), metoda wyrzuca wyjatek.
	* \return ppoczatkowy, jesli jest dotep do obiektu klasy dane_planszy. Jesli nie, zwraca nullptr.
	*/
	element_listy_sasiadow * getn();
	/**
	* Metoda zwraca pole liczba_sasiadow.
	*
	* Metoda zostala stworzona aby uzyskac dostep do pola liczba_sasiadow przez klasy niezaprzyjaznione i niepochodne.
	* Jesli cos poszlo nie tak i nie ma dostepu do obiektu klasy dane_planszy (lub obiektu klasy pochodnej), metoda wyrzuca wyjatek.
	* \return rozmiar, jesli jest dotep do obiektu klasy dane_planszy. Jesli nie, zwraca -1.
	*/
	int get_l_sasiadow();
	/**
	* Metoda ustawia pole pnext.
	*
	* Metoda zostala stworzona aby uzyskac dostep i pozwolic na zmiane wartosci pola pnext przez klasy niezaprzyjaznione i niepochodne.
	* Do pola przypisywana jest wartosc przekazana przez argument.
	* Jesli cos poszlo nie tak i nie ma dostepu do obiektu klasy dane_planszy (lub obiektu klasy pochodnej), metoda wyrzuca wyjatek.
	* \param pn wskaznik na nastepny element listy sasiadow.
	*/
	void setn(element_listy_sasiadow * pn);
	/**
	* Metoda ustawia pole liczba_sasiadow.
	*
	* Metoda zostala stworzona aby uzyskac dostep i pozwolic na zmiane pola liczba_sasiadow przez klasy niezaprzyjaznione i niepochodne.
	* Do pola przypisywana jest wartosc przekazana przez argument.
	* Jesli cos poszlo nie tak i nie ma dostepu do obiektu klasy dane_planszy (lub obiektu klasy pochodnej), metoda wyrzuca wyjatek.
	* \param l_s dlugosc boku podstawowej planszy kwadratowej.
	*/
	void set_l_sasiadow(int l_s);

};
#endif // !KLASA_ELEMENT_LISTY_SASIADOW
