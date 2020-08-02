#ifndef KLASA_WYSWIETL
#define KLASA_WYSWIETL
/**
* Klasa sluzy do wyswietlania oraz wpisywania aktualnego stanu planszy do pliku.
* Jest klasa pochodna klasy dane_planszy.
* Rozszerza tylko o metody.
*/
class wyswietl : public dane_planszy
{
public:
	/**
	* Metoda wyswietla aktualny stan planszy na strumien wyjsciowy.
	* Metoda wykorzystuje przeciazony operator strumieniowy <<.
	* \return nic
	*/
	void wyswietl_plansze();
	/**
	* Metoda zapisuje sktualny stan planszy do pliku  o podanej przez uzytkownika nazwie.
	*
	* Najpierw zostaje wyswietlony komunikat proszacy o podanie nazwy pliku.
	* Po podaniu nazwy otwieranyn jest plik.
	* Wykorzystany przeciazony operator strumieniowy <<.
	* Jezeli plik nie istnieje, wyrzucany jest wyjatek przez ten operator.
	* Jesli istnieje dane zostaja wpisane do pliku.
	* \return nic
	*/
	void zapisz_plansze();
};

#endif // !KLASA_WYSWIETL
