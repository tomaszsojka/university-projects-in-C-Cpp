#ifndef KLASA_PLANSZA
#define KLASA_PLANSZA
/**
* Klasa umozliwia operacje na planszy.
* Jest klasa pochodna klasy dane_planszy.
*
* Klasa nie rozszerza klasy dane_planszy o zadne pole. 
* Zawera jedynie dodatkowe metody, takie jak tworzenie elementu planszy, tworzenie z nich podstawowej planszy, rozszerzanie planszy w dana strone.
*/
class plansza : public dane_planszy
{
public:
	/**
	* Destruktor klasy plansza.
	* Poza usunieciem obiektu klasy plansza zwalnia pamiec zajmowana przez elementy planszy do gry w zycie.
	* Jesli ppoczatkowy na nic nie wskazuje destruktor tylko usuwa obiekt.
	*/
	~plansza();
	/**
	* Metoda tworzy element planszy, ktory jest reprezentacja komorki z gry w zycie
	* Pobiera cztery wartosci typu wskaznikowego na obiekt klasy element planszy i zwraca rowniez wskaznik na obiekt klasy element_planszy.
	*
	* W metodzie utworzony jest obiekt klasy element_planszy i ustawiony na niego wskaznik nowy.
	* Nastepnie ustawiane sa wszystkie wskazniki "sasiadow" na elementy podane w parametrach funkcji.
	* \param pp wskaznik na komorke sasiadujaca po prawej lub na nullptr gdy tworzony element znajduje sie na prawej krawedzi planszy
	* \param pl wskaznik na komorke sasiadujaca po lewej lub na nullptr gdy tworzony element znajduje sie na lewej krawedzi planszy
	* \param pd wskaznik na komorke sasiadujaca z dolu lub na nullptr gdy tworzony element znajduje sie na dolnej krawedzi planszy
	* \param pg wskaznik na komorke sasiadujaca z gory lub na nullptr gdy tworzony element znajduje sie na gornej krawedzi planszy
	* \return nowy - wskaznik na nowo utworzony obiekt klasy element_planszy.
	*/
	element_planszy * stworz_element(element_planszy * pp, element_planszy *pl, element_planszy *pd, element_planszy *pg);
	/**
	* Metoda tworzy plansze o boku rownym polu klasy dane_planszy - rozmiar , na ktorej bedzie odbywala sie gra w zycie.
	* Nie pobiera zadnych parametrow i nic nie zwraca.
	*
	* Gdy pole rozmiar jest rowne 0 plansza w ogole sie nie tworzy. Jesli nie, funkcja najpierw tworzy glowna kolumne o dlugosci rozmiar, nastepnie tworzy kolejne kolumny, ktorych jest rowniez rozmiar.
	* W metodzie wykozystane sa trzy wskazniki chwilowe:
	* tmp_w_dol - do przesuwania sie w dol po utworzonej lewej kolumnie i laczenia elementow wskaznikami pprawy z nowo tworzonymi.
	* tmp_prawy_w_dol - do przesuwania sie w dol i tworzenia nowej kolumny oraz laczenia jej z utworzona po lewej za pomoca wskaznikow plewy.
	* tmp_w_prawo  - do przesuniecia powyzszych wskaznikow w prawo tak aby tmp_w_dol wskazywal na pierwszy el istniejacej kolumny, a tmp_prawy_w_dol na pierwszy nowo utworzony w nastepnej. 
	* \return nic
	*/
	void stworz_podstawowa_plansze();
	/**
	* Metoda rozszerza plansze o kolumne w prawo.
	* Pobiera wartosc typu wskaznikowego na obiekt klasy element planszy i nic nie zwraca.
	*
	* Metoda jest uzywana do rozszerzenia planszy w sytuacji gdy komorka "ozyje"(pole bool czy_zyje klasy element_planszy = 1) na prawej krawedzi. Dzieki niej plansza jest nieskonczona z prawej strony (ograniczona pamiecia komputera).
	* Jesli cos poszlo nie tak i wskaznik el wskazuje na el w srodku planszy, funkcja nic nie robi.
	* \param el wskaznik na komorke na prawej krawedzi. 
	* \return nowy - wskaznik na nowo utworzony obiekt klasy element_planszy.
	*/
	void rozszerz_plansze_w_prawo(element_planszy * el);
	/**
	* Metoda rozszerza plansze o kolumne w lewo.
	* Pobiera wartosc typu wskaznikowego na obiekt klasy element planszy i nic nie zwraca.
	*
	* Metoda jest uzywana do rozszerzenia planszy w sytuacji gdy komorka "ozyje"(pole bool czy_zyje klasy element_planszy = 1) na lewej krawedzi. Dzieki niej plansza jest nieskonczona z lewej strony (ograniczona pamiecia komputera).
	* Jesli cos poszlo nie tak i wskaznik el wskazuje na el w srodku planszy, metoda nic nie robi.
	* Metoda przesuwa wskaznik ppoczatkowy z klasy dane_planszy na pierwszy element dodawanej kolumny(element w lewym gornym rogu).
	* \param el wskaznik na komorke na lewej krawedzi.
	* \return nic
	*/
	void rozszerz_plansze_w_lewo(element_planszy * el);
	/**
	* Metoda rozszerza plansze o wiersz w dol.
	* Pobiera wartosc typu wskaznikowego na obiekt klasy element planszy i nic nie zwraca.
	*
	* Metoda jest uzywana do rozszerzenia planszy w sytuacji gdy komorka "ozyje"(pole bool czy_zyje klasy element_planszy = 1) na dolnej krawedzi. Dzieki niej plansza jest nieskonczona z dolu (ograniczona pamiecia komputera).
	* Jesli cos poszlo nie tak i wskaznik el wskazuje na el w srodku planszy, metoda nic nie robi.
	* \param el wskaznik na komorke na dolnej krawedzi.
	* \return nic
	*/
	void rozszerz_plansze_w_dol(element_planszy * el);
	/**
	* Metoda rozszerza plansze o wiersz w gore.
	* Pobiera wartosc typu wskaznikowego na obiekt klasy element planszy i nic nie zwraca.
	*
	* Metoda jest uzywana do rozszerzenia planszy w sytuacji gdy komorka "ozyje"(pole bool czy_zyje klasy element_planszy = 1) na gornej krawedzi. Dzieki niej plansza jest nieskonczona z gory (ograniczona pamiecia komputera).
	* Jesli cos poszlo nie tak i wskaznik el wskazuje na el w srodku planszy, metoda nic nie robi.
	* Metoda przesuwa wskaznik ppoczatkowy z klasy dane_planszy na pierwszy element dodawanej kolumny(element w lewym gornym rogu).
	* \param el wskaznik na komorke na gornej krawedzi.
	* \return nic
	*/
	void rozszerz_plansze_w_gore(element_planszy * el);
	/**
	* Metoda usuwa plansze do gry w zycie.
	* Nic nie pobiera i nic nie zwraca.
	*
	* Metoda ustawia wskaznik chwilowy tmp na adres wskazywany przez wskaznik ppoczatkowy po czym przesuwa wskaznik ppoczatkowy w prawo.
	* Nastepnie usuwa komorke wskazywana przez tmp oraz ustawia wskaznik plewy komorki wskazywanej przez ppoczatkowy na nullptr.
	* Kiedy wskaznik ppoczatkowy "dojdzie" do prawej krawedzi planszy, jesli to mozliwe, przesuwa sie w dol i wykonywana jest ten sam algorytm na nastepnym wierszy, tylko w lewo.
	* Ostatni usuniety element ma wszystkie wskazniki "sasiadow" ustawione na nullptr poza pgorny. 
	* Taka sytuacja spelnia instrukcje warunkowa else if i ustawia wskaznik ppoczatkowy na nullptr i pozwala na wyjscie z petli while.
	* Metoda zostala stworzona aby zapobiedz wyciekowi pamieci. 
	* Jest uzyta w destruktorze, dzieki czemu przy usuwaniu obiektu klasy plansza zostaje zwolniona pamiec zajmowana przez wszystkie elementy planszy. 
	* \return nic
	*/
	void usun_plansze();
	/**
	* Przeciazony operator konwersji na int zlicza ilosc elementow planszy.
	* Nic nie pobiera i zwraca ilosc elementow planszy.
	*
	* Operator  ustawia wskaznik chwilowy tmp na adres wskazywany przez wskaznik ppoczatkowy po czym przesuwa go w prawo zliczajac kolumny.
	* Nastepnie przesuwa ten sam chwilowy wskaznik w dol i liczy wiersze.
	* Poniewaz plansza ma zawsze ksztalt prostakatny wystarczy pomnozyc ilosc kolumn razy ilosc wierszy.
	* \return ilosc elementow planszy
	*/
	operator int();
};

#endif // !KLASA_PLANSZA
