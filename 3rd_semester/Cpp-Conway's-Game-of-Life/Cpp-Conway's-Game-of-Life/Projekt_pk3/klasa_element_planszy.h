#ifndef KLASA_ELEMENT_PLANSZY
#define KLASA_ELEMENT_PLANSZY
/**
* Klasa reprezentuje element planszy do gry w zycie.
* Obiekt klasy zawiera trzy pola wskaznikowe zawierajace adresy sasiadow danego elementu oraz pole typu bool, ktore informuje o tym, czy komorka zyje .
*/
class element_planszy
{
private:
	element_planszy * pprawy;/*!< Pole pprawy zawiera adres komorki po prawej. */
	element_planszy * plewy;/*!< Pole plewy zawiera adres komorki po lewej. */
	element_planszy *pdolny;/*!< Pole pdolny zawiera adres komorki na dole. */
	element_planszy * pgorny;/*!< Pole pgorny zawiera adres komorki na gorze. */
	bool czy_zyje = false;/*!< Pole czy_zyje informuje o tym, czy dana komorka zyje. Domyslnie komorka nie zyje(wartosc ustawiona na false). */
public:
	/**
	* Metoda zwraca pole pprawy.
	*
	* Metoda zostala stworzona aby uzyskac dostep do pola pprawy przez klasy niezaprzyjaznione i niepochodne.
	* Jesli cos poszlo nie tak i nie ma dostepu do obiektu klasy dane_planszy (lub obiektu klasy pochodnej), metoda wyrzuca wyjatek.
	* \return pprawy, jesli jest dotep do obiektu klasy dane_planszy. Jesli nie, zwraca nullptr.
	*/
	element_planszy * getp();
	/**
	* Metoda zwraca pole plewy.
	*
	* Metoda zostala stworzona aby uzyskac dostep do pola plewy przez klasy niezaprzyjaznione i niepochodne.
	* Jesli cos poszlo nie tak i nie ma dostepu do obiektu klasy dane_planszy (lub obiektu klasy pochodnej), metoda wyrzuca wyjatek.
	* \return plewy, jesli jest dotep do obiektu klasy dane_planszy. Jesli nie, zwraca nullptr.
	*/
	element_planszy * getl();
	/**
	* Metoda zwraca pole pdolny.
	*
	* Metoda zostala stworzona aby uzyskac dostep do pola pdolny przez klasy niezaprzyjaznione i niepochodne.
	* Jesli cos poszlo nie tak i nie ma dostepu do obiektu klasy dane_planszy (lub obiektu klasy pochodnej), metoda wyrzuca wyjatek.
	* \return pdolny, jesli jest dotep do obiektu klasy dane_planszy. Jesli nie, zwraca nullptr.
	*/
	element_planszy * getd();
	/**
	* Metoda zwraca pole pgorny.
	*
	* Metoda zostala stworzona aby uzyskac dostep do pola pgorny przez klasy niezaprzyjaznione i niepochodne.
	* Jesli cos poszlo nie tak i nie ma dostepu do obiektu klasy dane_planszy (lub obiektu klasy pochodnej), metoda wyrzuca wyjatek.
	* \return pgorny, jesli jest dotep do obiektu klasy dane_planszy. Jesli nie, zwraca nullptr.
	*/
	element_planszy * getg();
	/**
	* Metoda zwraca pole czy_zyje.
	*
	* Metoda zostala stworzona aby uzyskac dostep do pola pgorny przez klasy niezaprzyjaznione i niepochodne.
	* Jesli cos poszlo nie tak i nie ma dostepu do obiektu klasy dane_planszy (lub obiektu klasy pochodnej), metoda wyrzuca wyjatek.
	* \return pgorny, jesli jest dotep do obiektu klasy dane_planszy. Jesli nie, zwraca nullptr.
	*/
	bool get_czy_zyje();
	/**
	* Metoda ustawia pole pprawy.
	*
	* Metoda zostala stworzona aby uzyskac dostep i pozwolic na zmiane pola pprawy przez klasy niezaprzyjaznione i niepochodne.
	* Do pola przypisywana jest wartosc przekazana przez argument.
	* Jesli cos poszlo nie tak i nie ma dostepu do obiektu klasy dane_planszy (lub obiektu klasy pochodnej), metoda wyrzuca wyjatek.
	* \param pp wskaznik na element po prawej.
	*/
	void setp(element_planszy * pp);
	/**
	* Metoda ustawia pole plewy.
	*
	* Metoda zostala stworzona aby uzyskac dostep i pozwolic na zmiane pola plewy przez klasy niezaprzyjaznione i niepochodne.
	* Do pola przypisywana jest wartosc przekazana przez argument.
	* Jesli cos poszlo nie tak i nie ma dostepu do obiektu klasy dane_planszy (lub obiektu klasy pochodnej), metoda wyrzuca wyjatek.
	* \param pl wskaznik na element po lewej.
	*/
	void setl(element_planszy * pl);
	/**
	* Metoda ustawia pole pdolny.
	*
	* Metoda zostala stworzona aby uzyskac dostep i pozwolic na zmiane pola pdolny przez klasy niezaprzyjaznione i niepochodne.
	* Do pola przypisywana jest wartosc przekazana przez argument.
	* Jesli cos poszlo nie tak i nie ma dostepu do obiektu klasy dane_planszy (lub obiektu klasy pochodnej), metoda wyrzuca wyjatek.
	* \param pd wskaznik na element na dole.
	*/
	void setd(element_planszy * pd);
	/**
	* Metoda ustawia pole pgorny.
	*
	* Metoda zostala stworzona aby uzyskac dostep i pozwolic na zmiane pola pgorny przez klasy niezaprzyjaznione i niepochodne.
	* Do pola przypisywana jest wartosc przekazana przez argument.
	* Jesli cos poszlo nie tak i nie ma dostepu do obiektu klasy dane_planszy (lub obiektu klasy pochodnej), metoda wyrzuca wyjatek.
	* \param pg wskaznik na element na gorze.
	*/
	void setg(element_planszy * pg);
	/**
	* Metoda ustawia pole czy_zyje.
	*
	* Metoda zostala stworzona aby uzyskac dostep i pozwolic na zmiane pola czy_zyje przez klasy niezaprzyjaznione i niepochodne.
	* Do pola przypisywana jest wartosc przekazana przez argument.
	* Jesli cos poszlo nie tak i nie ma dostepu do obiektu klasy dane_planszy (lub obiektu klasy pochodnej), metoda wyrzuca wyjatek.
	* \param zyje stan w jaki komorka ma byc wprowadzona (ozywiona lub zabita).
	*/
	void set_czy_zyje(bool zyje);
};

#endif // !KLASA_ELEMENT_PLANSZY
