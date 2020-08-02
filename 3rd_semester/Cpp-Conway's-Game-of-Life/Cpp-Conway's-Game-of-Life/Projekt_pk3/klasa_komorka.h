#ifndef KLASA_KOMORKA
#define KLASA_KOMORKA
/**
* Klasa sluzy do "ozywiania i zabijania komorek".
* Dziedziczy po klasie sasiedzi i dodaje tylko jedna metode. Nie zawiera dodatkowychy pol.
*/
class komorka : public sasiedzi
{
public:
	/**
	* Metoda w zaleznosci od ilosci sasiadow komorki zabija ozywia lub zostawia w poprzednim stanie komorke.
	*
	* Metoda uzywa dwoch wskaznikow pomocniczych. 
	* Pierwszy, tmp_lista jest uzyty do przechodzenia listy sasiadow i odczytywania z niej wartosci.
	* Drugi, tmp jest uzyty do przechodzenia planszy "wezykiem w dol"(wywolana jest do tego metoda klasy sasiedzi przesun_wezykiem_w_dol) i sprawdzania oraz ustawiania stanu komorek w zaleznosci od ilosci sasiadow pod wskaznikiem tmp_lista.
	* Metoda lapie ewentualne wyjatki wyrzucone przez uzyte w niej inne metody.
	* \return nic
	*/
	void ozyw_zabij_lub_zostaw();

};
#endif // !KLASA_KOMORKA

