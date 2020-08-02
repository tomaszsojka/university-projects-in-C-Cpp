#ifndef KLASA_MENUE
#define KLASA_MENUE
class komorka;
class wyswietl;
/**
* Klasa sluzy do laczenia wszystkich operacji, aby gra w zycie dzialala poprawnie oraz do komunikacji z uzytkownikiem.
*/
class menue
{
	static bool warunek_wyjscia;/*!< Pole statyczne warunek_wyjscia okresla czy zostal spelniony warunek wyjscia z nieskonczonej petli gry w zycie */
public:
	/**
	* Metoda wyswietla komentarz na strumien wyjsciowy.
	*
	* Wyswietlany komentarz prosi uzytkownika o wybor sposobu wprowadzenia wspolrzednych komorek do ozywienia.
	* \return nic
	*/
	static void kom_wpr_danych();
	/**
	* Metoda wyswietla komentarz na strumien wyjsciowy.
	*
	* Wyswietlany komentarz dotyczy wyboru sposobu wprowadzenia wspolrzednych.
	* Jest on wyswietlany w petli, ktora konczy sie gdy uzytkownik poda poprawna odpowiedz (1 lub 2).
	* \return nic
	*/
	static void kom_wpr_danych_w_petli();
	/**
	* Metoda wyswietla komentarz na strumien wyjsciowy.
	*
	* Wyswietlany komentarz prosi uzytkownika o wybor, czy uzytkownik chce rozpoczac gre w zycie z ozywionymi przez siebie komorkami, czy wylaczyc program i cos jeszcze zmienic.
	* \return nic
	*/
	static void kom_s_czy_s();
	/**
	* Metoda wyswietla komentarz na strumien wyjsciowy.
	*
	* Wyswietlany komentarz dotyczy wyboru, czy uzytkownik chce wystartowac gre, czy zakonczyc program i cos zmienic. 
	* Jest on wyswietlany w petli, ktora konczy sie gdy uzytkownik poda poprawna odpowiedz (1 lub 2).
	* \return nic
	*/
	static void kom_s_czy_s_w_petli();
	/**
	* Metoda wyswietla komentarz na strumien wyjsciowy.
	*
	* Wyswietlany komentarz prosi uzytkownika o wybor, czy chce on zapisac aktualny stan(po zatrzymaniu) planszy do pliku.
	* \return nic
	*/
	static void kom_zapis();
	/**
	* Metoda wyswietla komentarz na strumien wyjsciowy.
	*
	* Wyswietlany komentarz dotyczy wyboru, czy uzytkownik chce zapisac plansze do pliku.
	* Jest on wyswietlany w petli, ktora konczy sie gdy uzytkownik poda poprawna odpowiedz (1 lub 2).
	* \return nic
	*/
	static void kom_zapis_w_petli();
	/**
	* Metoda wyswietla komentarz na strumien wyjsciowy.
	*
	* Wyswietlany komentarz informuje, ze zaraz zostanie wyswietlony aktualny stan planszy.
	* Metoda jest uzyta przed wyswietleniem planszy w wersji zaraz po wprowadzeniu danych przez uzytkownika.
	* \return nic
	*/
	static void kom_stan_planszy();
	/**
	* Metoda wyswietla komentarz na strumien wyjsciowy.
	*
	* Wyswietlany komentarz informuje, ze zaraz rozpocznie sie gra w zycie oraz jak ja zakonczyc.
	* Metoda jest uzyta tuz przed startem gry.
	* \return nic
	*/
	static void kom_start();

	/**
	* Metoda do wyboru miedzy dwoma opcjami.
	*
	* Metoda zaleznosci od parametru podanego jako argument wyswietla komunikaty zwiazane z roznym wyborem.
	* 1 - wybor sposobu wprowadzenia wspolrzednych punktow do ozywienia
	* 2 - wybor czy wystartowac gre w zycie, czy ja zakonczyc
	* 3 - wybor czy zapisac aktualny stan planszy po zatrzymaniu nieskonczonej petli gry w zycie.
	* Metoda nie konczy sie dopoki uzytkownik nie poda liczby 1 lub 2 na wejscie.
	* Po zakonczeniu zwraca nr wyboru, ktory pozniej jest uzyty do wywolania odpowiednich metod. 
	* \param zmiana_wyboru jest indeksem wyboru, w zaleznosci od jego wartosci wyswietlaja sie inne opcje wyboru(1 - jak wprowadzic wspolrzedne, 2 - czy wystartowac gre w zycie, 3 - czy zapisac aktualny stan planszy).
	* \return wybor - 48 (-48 , poniewaz wybrane opcje zostaja sczytane jako kod ascii)
	*/
	static int wybor(int &zmiana_wyb);
	/**
	* Metoda zawiera nieskonczona petle do gry w zycie.
	*
	* W metodzie, w nieskonczonej petli, wywolywane sa wszelkie metody konieczne do zmiany stanu planszy(ozywianie i zabijanie) oraz do wyswietlenia jej.
	* Z petli da sie wyjsc przez zmiane wartosci pola statycznego klasy menue warunek_wyjscia. Za zmiane tego pola odpowiedzialna jest zsynchronizowany watek metody zatrzymaj_petle.
	* Obiekty podane jako argumenty musialy byc kopiowane, poniewaz tak jest domyslnie w watku, ktory przyjmuje funkcje i jej rgumenty.
	* Zwykla referencja nic nie zmieniala. Niestety nie potrafie jeszcze dodac do watku argumentow bez kopiwania i dzialac na oryginale.
	* \param ko kopia obiektu klasy komorka, za pomoca metod tego obiektu beda ozywiane i zabijane komorki
	* \param wys kopia obiektu klasy wyswietl, za pomoca metody tego obiektu bedzie wyswietlana plansza do gry w zycie i jej aktualny stan.
	* \return nic
	*/
	static void petla( komorka   ko,  wyswietl  wys);
	/**
	* Metoda sluzy do zatrzymania nieskonczonej petli do gry w zycie.
	*
	* Metoda czeka na podanie przez uzytkownika danych na wejscie.
	* Jesli podana dana jest litera n, metoda zmienia wartosc pola klasy menue warunek_wyjscia na true.
	* Nastepnie po sprawdzeniu tego warunku w nieskonczonej petli do gry w zycie petla sie zatrzymuje.
	* Jesli uzytkownik podal cos innego, bufor sie czysci i metoda jest wywolana ponownie rekurencyjnie.
	* Rekurencja byla konieczna, poniewaz inaczej metoda konczyla sie przed moetoda petla.
	* Uniemozliwialo to wyjscie z nieskonczonej petli w sytuacji, gdy uzytkownik najpierw podal niepoprawna dana (cos co nie bylo litera n).
	* Watek tej metody jest zsynchornizowany z watkiem metody petla.
	* \return nic
	*/
	static void zatrzymaj_petle();
	/**
	* Glowna metoda w ktorej sa utworzone wszystkie obiekty oraz wywolane wszystkie metody konieczne do poprawnego dzialania gry w zycie
	*
	* Kolejnosc dzialania:
	* Uzytkownika czeka pierwszy wybor, czy chce wprowadzic wspolrzedne komorek do ozywienia z pliku czy wpisac je recznie.
	* Po sczytaniu wspolrzednych (jednym ze sposobow) do tablicy dynamicznej utworzona zostaje postawowa plansza, a nastepnie wypelniona.
	* Stan planszy jest wyswietlony. Jesli wszystko sie zgadza z oczekiwaniami, uzytkownik moze wystartowac gre w zycie. 
	* Jesli nie, moze wylaczyc program aby podac jeszcze raz inne wspolrzedne. 
	* Gdy uzytkownik wybral start gry, zostaje wyswietlony komunikat o sposobie zakonczenia gry.
	* Gdy uzytkownik przerwie dzialanie programu (poprzez dzialanie opisane przy metodzie zatrzymaj_petle) pytany jest, czy chce zapisac aktualny stan planszy do pliku.
	* Jesli tak, program pyta o nazwe nowego pliku do utworzenia.
	* Program sie konczy.
	* Jest to jedyna metoda wywolana w funkcji main.
	* \return nic
	*/
	static void poprowadz_uzytkownika();

};
#endif // !KLASA_MENUE

