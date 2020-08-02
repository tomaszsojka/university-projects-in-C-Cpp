#ifndef KLASA_DANE_PLANSZY
#define KLASA_DANE_PLANSZY

class element_planszy;
/**
* Klasa zawiera podtawowe dane planszy do gry w zycie.
* Jest klasa bazowa klas: plansza, wyjwietl, wypelnij(po ktorej dziedziczy klasa wspolrzedne).
*/
class dane_planszy 
{
protected:
	element_planszy * ppoczatkowy;/*!< Pole ppoczatkowy jest wskaznikiem na pierwszy element planszy, ktory znajduje sie w lewym gornym rogu. */
	int rozmiar;/*!< Pole rozmiar przechowuje rozmiar kwadratowej poczatkowej planszy (dlugosc boku), ktora podal uzytkownik, tak aby zmiescily sie w niej wszystkie komorki do ozywienia. */
public:
	/**
	* Metoda zwraca pole ppoczatkowy.
	*
	* Metoda zostala stworzona aby uzyskac dostep do pola ppoczatkowy przez klasy niezaprzyjaznione i niepochodne.
	* Jesli cos poszlo nie tak i nie ma dostepu do obiektu klasy dane_planszy (lub obiektu klasy pochodnej), metoda wyrzuca wyjatek.
	* \return ppoczatkowy, jesli jest dotep do obiektu klasy dane_planszy. Jesli nie, zwraca nullptr. 
	*/
	element_planszy * get_pocz();
	/**
	* Metoda zwraca pole rozmiar.
	*
	* Metoda zostala stworzona aby uzyskac dostep do pola rozmiar przez klasy niezaprzyjaznione i niepochodne.
	* Jesli cos poszlo nie tak i nie ma dostepu do obiektu klasy dane_planszy (lub obiektu klasy pochodnej), metoda wyrzuca wyjatek.
	* \return rozmiar, jesli jest dotep do obiektu klasy dane_planszy. Jesli nie, zwraca -1.
	*/
	int get_roz();
	/**
	* Metoda ustawia pole ppoczatkowy.
	*
	* Metoda zostala stworzona aby uzyskac dostep i pozwolic na zmiane wartosci pola ppoczatkowy przez klasy niezaprzyjaznione i niepochodne.
	* Do pola przypisywana jest wartosc przekazana przez argument.
	* Jesli cos poszlo nie tak i nie ma dostepu do obiektu klasy dane_planszy (lub obiektu klasy pochodnej), metoda wyrzuca wyjatek.
	* \param pp wskaznik na komorke w lewym gornym rogu.
	*/
	void set_pocz(element_planszy * pp);
	/**
	* Metoda ustawia pole rozmiar.
	*
	* Metoda zostala stworzona aby uzyskac dostep i pozwolic na zmiane wartosci pola rozmiar przez klasy niezaprzyjaznione i niepochodne.
	* Do pola przypisywana jest wartosc przekazana przez argument.
	* Jesli cos poszlo nie tak i nie ma dostepu do obiektu klasy dane_planszy (lub obiektu klasy pochodnej), metoda wyrzuca wyjatek.
	* \param r dlugosc boku podstawowej planszy kwadratowej.
	*/
	void set_roz(int r);
};
#endif // !KLASA_DANE_PLANSZY
