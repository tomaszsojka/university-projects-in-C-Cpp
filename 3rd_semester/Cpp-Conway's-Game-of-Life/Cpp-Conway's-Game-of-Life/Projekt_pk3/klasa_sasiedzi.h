#ifndef KLASA_SASIEDZI
#define KLASA_SASIEDZI

class element_listy_sasiadow;
class element_planszy;
class plansza;
/**
* Klasa sluzy do zliczania sasiadow komore planszy do gry w zycie.
* Jest klasa bazowa klasy komorka
*/
class sasiedzi
{
protected:
	element_listy_sasiadow * pglowa;/*!< Pole pglowa jest wskaznikiem na pierwszy element listy sasiadow. */
public: 
	plansza * ob;/*!< Pole ob jest wskaznikiem na obiekt klasy plansza. Takie rozwiazanie zostalo zastosowane zamiast dziedziczenia po klasie dane_planszy, aby nie tworzyc tymczasowego obiektu klasy plansza do wywolania metod do rozszerzania planszy.*/
	/**
	* Konstruktor klasy sasiedzi.
	* Utworzony, aby ustawiac pole pglowa na nullptr przy tworzeniu nowego obiektu.
	*/
	sasiedzi();
	/**
	* Destruktor klasy sasiedzi.
	* Utworzony, aby dodatkwo zwalniac pamiec zajmowana przez liste sasiadow (wywolana funkcja usun_liste_sasiadow).
	* Jesli pole pglowa na cos wskazuje, zostaje to usuniete.
	*/
	~sasiedzi();
	/**
	* Metoda rozszerza plansze do gry w zycie w odpowiedna strone
	* 
	* Metoda uzywa pomocniczych wskaznikow i przesuwa jeden z nich wokol planszy sprawdzajac, czy na krawedzi jest jakas zywa komorka.
	* Jesli tak, plansza jest rozszerzana(wywolana jest odpowiednia metoda klasy plansza) w strone krawedzi przy ktorej znaleziona zostala zywa komorka.
	* \return nic
	*/
	void rozszerz_w_dobra_strone();
	/**
	* Przeciazony operator arytmetyczny +=, ktory sluzy do dodawania elementow na koniec listy sasiadow.
	* \param l_s liczba sasiadow komorki, ktora ma byc dodana do listy
	* \return nowy przeksztalcony wskaznik na pierwszy element listy sasiadow.
	*/
	element_listy_sasiadow * operator +=(int l_s);
	/**
	* Metoda dodaje nowy element na koniec listy sasiadow.
	*
	* W metodzie uzyty jest przeciazony operator arytmetyczny +=.
	* \param l_s liczba sasiadow komorki, ktora ma byc dodana do listy
	* \return nic
	*/
	void dodaj_na_koniec_listy_sasiadow(int l_s);
	/**
	* Metoda usuwa i zwalnia pamiec po liscie sasiadow.
	* Metoda wywolana w destruktorze.
	* \return nic
	*/
	void usun_liste_sasiadow();
	/**
	* Metoda sprawdza polozenie komorki i w zaleznosci od niego zwraca odpowiednia liczbe.
	*
	* Znaczenie zwracanej liczby, to lokalizacja komorki w:
	* 0 - prawa krawedz
	* 10 - prawy dolny rog
	* 20 - prawy gorny rog
	* 1 - lewa krawedz
	* 11 - lewy dolny rog
	* 21 - lewy gorny rog
	* 2 - dolna krawedz
	* 3 - gorna krawedz
	* Dzieki tej metodzie metoda policz_sasiadow nie sprawdza sasiadow, ktorzy nie maja prawa byc zywymi.
	* \param el wskaznik na komorke, ktorej lokalizacje chcemy poznac.
	* \return liczba odpowiadajaca lokalizacji komorki.
	*/
	int sprawdz_czy_krawedz(element_planszy * el);
	/**
	* Metoda przesuwa wskaznik po planszy "wezykiem w dol".
	*
	* Metoda przesuwa wskaznik podany jako parametr el o jedna pozycje.
	* Najpierw do konca w prawo, jak juz sie nie da, raz w dol, potem w lewo.
	* Przesuniecie jest mozliwe dopoki wskaznik na dolnego sasiada wskazuje na cos.
	* \param el wskaznik na element planszy (do przesuniecia) 
	* \param el_za wskaznik na element za el w sensie przechodzenia wezykiem w dol(wskazuje na sasiada po lewej, jak metoda przesuwa w prawo, odwrotnie gdy w lewo)
	* \return nic
	*/
	void przesun_wezykiem_w_dol(element_planszy * &el, element_planszy * &el_za);
	/**
	* Metoda liczy sasiadow wszystkich komorek w planszy i dodaje ich liczbe na koniec listy sasiadow.
	*
	* W metodzie wywolane sa prawie wszytkie metody klasy sasiedzi.
	* Na poczatku plansza jest rozszerzona w odpowiednie strony (metoda rozszerz_w_dobra_strone), aby moc sprawdzic ilosc sasiadow komorek, ktore wczesniej nie istnialy.
	* Zainicjowane sa wskazniki pomocnicze do przechodzenia planszy i liczenia sasiadow.
	* W petli najpierw sprawdzana jest pozycja komorki(metoda sprawdz_czy_krawedz).
	* Nastepnie w zaleznosci od wartosci zwroconej przez metode sprawdz_czy_krawedz(czytaj opis tej metody) sprawdzana jest ilosc sasiadow.
	* Ilosc ta jest dodana na koniec listy sasiadow(metoda dodaj_na_koniec_listy_sasiadow).
	* operacja powtarzana az zostana zliczeni sasiedzi wszystkich komorek rozszerzonej planszy.
	* \return nic
	*/
	void policz_sasiadow();
};

#endif // !KLASA_SASIEDZI
