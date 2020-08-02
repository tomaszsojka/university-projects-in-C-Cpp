#ifndef KLASA_WYPELNIJ
#define KLASA_WYPELNIJ
/**
* Klasa sluzy do wypelniania planszy do gry w zycie zywymi komorkami.
* Jest klasa bazowa klasy wspolrzedne.
*/
class wypelnij : public dane_planszy
{
protected:
	int * punkty;/*!< Pole wskaznikowe na int, sluzy do tworzenia tablicy dynamicznej z wspolrzednymi punktow do ozywienia. */
public:
	/**
	* Konstruktor klasy wypelnij.
	* Utworzony, aby ustawiac pole punkty na nullptr przy tworzeniu nowego obiektu.
	*/
	wypelnij();
	/**
	* Destruktor klasy wypelnij.
	* Utworzony, aby dodatkwo zwalniac pamiec zajmowana przez tablice dynamiczna punkty (wywolana funkcja usun_tab_wsp).
	* Jesli pole punkty na cos wskazuje, zostaje to usuniete.
	*/
	~wypelnij();
	/**
	* Metoda zwraca pole punkty.
	*
	* Metoda zostala stworzona aby uzyskac dostep do pola punkty przez klasy niezaprzyjaznione i niepochodne.
	* Jesli cos poszlo nie tak i nie ma dostepu do obiektu klasy wypelnij (lub obiektu klasy pochodnej), metoda wyrzuca wyjatek.
	* \return punkty, jesli jest dotep do obiektu klasy dane_planszy. Jesli nie, zwraca nullptr.
	*/
	int * get_punkty();
	/**
	* Metoda zwraca element tablicy dynamicznej punkty o podanym w argumencie indeksie.
	*
	* Metoda zostala stworzona aby uzyskac dostep do jednego elementu pola punkty (wskazaego przez argument) przez klasy niezaprzyjaznione i niepochodne.
	* Jesli cos poszlo nie tak i nie ma dostepu do obiektu klasy wypelnij (lub obiektu klasy pochodnej), metoda wyrzuca wyjatek.
	* \param idx indeks elementu tablicy dynamicznej do zwrocenia
	* \return punkty, jesli jest dotep do obiektu klasy wypelnij. Jesli nie, zwraca -1.
	*/
	int get_el_punktow(int idx);
	/**
	* Metoda ustawia pole punkty.
	*
	* Metoda zostala stworzona aby uzyskac dostep i pozwolic na zmiane wartosci pola punkty przez klasy niezaprzyjaznione i niepochodne.
	* Do pola przypisywana jest wartosc przekazana przez argument.
	* Jesli cos poszlo nie tak i nie ma dostepu do obiektu klasy wypelnij (lub obiektu klasy pochodnej), metoda wyrzuca wyjatek.
	* \param p wskaznik na tablice dynamiczna, na ktora ma wskazywac pole punkty.
	*/
	void set_punkty(int * p);
	/**
	* Metoda ustawia wartosc jednego elementu tablicy dynamicznej punkty.
	* Wartosc podana jako drugi argument wpisana jest do elementu tablicy punkty o podanym indeksie w pierwszym argumencie.
	*
	* Metoda zostala stworzona aby uzyskac dostep i pozwolic na zmiane wartosci elementu tablicy punkty (wskazanego przez arg idx) przez klasy niezaprzyjaznione i niepochodne.
	* Do pola przypisywana jest wartosc przekazana przez drugi argument.
	* Jesli cos poszlo nie tak i nie ma dostepu do obiektu klasy wypelnij (lub obiektu klasy pochodnej), metoda wyrzuca wyjatek.
	* \param idx indeks elementu tablicy dynamicznej do zmiany wartosci.
	* \param liczba wartosc , ktora ma byc przypisana elementowi tablicy punkty.
	*/
	void set_el_punktow(int idx, int liczba);
	/**
	* Metoda tworzy tablice dynamiczna punkty o rozmiarze 2 * rozmiar * rozmiar [jest to ilosc komorek na planszy * 2(dwie wspolrzedne)] oraz wypelnia ja wartosciami -1.
	*
	* Rozmiar stworzonej tablicy odpowia liczbie elementow planszy * 2. 
	* Mozna wiec maksymalnie wpisac tyle elementow, zeby zaplenic cala stworzona plansze.
	* \return nic
	*/
	void stworz_tab_wsp(); 
	/**
	* Metoda usuwa i zwalnia pamiec po tablicy dynamicznej punkty.
	* Metoda zabezpieczona przed kilkukrotnym usunieciem
	* Metoda wywolana w destruktorze.
	* \return nic
	*/
	void usun_tab_wsp();
	/**
	* Metoda sluzy do wypelnienia tablicy dynamicznej punkty.
	*
	* Metoda przesuwa wskaznik pomocniczy na element planszy wskzany przez wspolrzedne w tablicy punkty.\
	* Nastepnie ozywia ten element (zmiana pola klasy element_planszy czy_zyje na true).
	* Metoda wykorzystuje przeciazony operator tablicowy [] do przesuniecia wskaznika pomocniczego na odpowiedni element.
	* \return nic
	*/
	void wypelnij_plansze();
	/**
	* Przeciazony operator tablicowy [], ktory ustawia pomocniczy wskaznik na elemencie o podanym w argumencie indeksie i zwraca go.
	*
	* Operator  ustawia wskaznik chwilowy tmp na adres elementu planszy do gry w zycie o podanym przez argument indeksie.
	* Indeks jest interpretowany w nastepujacy sposob:
	* Poniewaz metoda przesuwa pomocniczy wskaznik kolejno po wierszach, indeks oznacza liczbe przesuniec konieczna do ustawienia tego wskaznika.
	* Indeks rowny jest pierwszej wspolrzednej x + rozmiar * druga wspolrzedna y.
	* Jesli okaze sie, ze wspolrzedna w tablicy punkty wskazywala na element poza plansza zostaje wyrzucony wyjatek.
	* \param el indeks komorki do ozywienia (ilosc koniecznych przesuniec od elementu poczatkowego, aby dostac sie do pozodanej komorki)
	* \return adres na ktory ustawiony jest pomocniczy wskaznik, czyli elementu o podanym w argumencie indeksie.
	*/
	element_planszy * operator [](size_t el);
};

#endif // !KLASA_WYPELNIJ

