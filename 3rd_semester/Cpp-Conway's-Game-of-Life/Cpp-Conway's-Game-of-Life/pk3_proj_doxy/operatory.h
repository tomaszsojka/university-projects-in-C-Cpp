#ifndef OPERATORY
#define OPERATORY
class element_planszy;
class wyswietl;
class wspolrzedne;
/**
* Przeciazony operator strumieniowy << sluzy do wyswietlania stanu obiektu klasy element_planszy.
*
* W zaleznosci od stanu (wartosci pola czy_zyje) elementu wskazywanego przez drugi argument operator "wrzuca" do strumienia ostream inne wartosci.
* " . " - gdy komorka nie zyje.
* " O " - gdy komorka zyje.
* \param s strumien ostream, do ktorego beda "wrzucone" znaki do wyswietlenia.
* \param ob wskaznik na element, ktorego stan ma byc wyswietlony.
* \return strumien ostream i to co w nim.
*/
std::ostream & operator <<(std::ostream &s, element_planszy * ob);
/**
* Przeciazony operator strumieniowy << sluzy do wyswietlania aktualnego stanu planszy do gry w zycie.
*
* Operator ustawia wskaznik pomocniczy na pierwszy element planszy(w obiekcie wyswietl).
* Przesuwa go po niej i uzywa przeciazonego operatora << dla elementu planszy do wyswietlenia jego stanu.
* \param s strumien ostream, do ktorego beda "wrzucone" znaki do wyswietlenia.
* \param ob obiekt klasy wypelnij ktorego stan planszy pod wskaznikiem ppoczatkowy byc wyswietlony.
* \return strumien ostream i to co w nim.
*/
std::ostream & operator <<(std::ostream &s, wyswietl  &ob );
/**
* Przeciazony operator strumieniowy >> sluzy do wczytywania rozmiaru kwadrwtowej planszy poczatkowej oraz wspolrzednych komorek do ozywienia z pliku.
*
* Jesli plik podany jako pierwszy argument istnieje, operator sczytuje rozmiar kwadratowej planszy podstawowej 
* Nastepnie tworzy tablice z wspolrzednymi(pole punkty(wywolanie metody stworz_tab_wsp dla ob klasy wspolrzedne)).
* Natepnie dopoki w pliku istnieja jakies liczby operator sczytuje je do stworzonej tablicy.
* Operator wyzruca wyjatek gdy nie ma dostepu  do pliku podanego jako pierwszy argument.
* \param plik strumien ifstream, plik z ktorego beda wczytane dane.
* \param ob obiekt klasy wspolrzedne, do ktorego (do tablicy punkty) maja zostac wczytane wspolrzedne.
* \return strumien iftream.
*/
std::ifstream & operator >>(std::ifstream &plik, wspolrzedne &ob);
/**
* Przeciazony operator strumieniowy << sluzy do zapisania aktualnego stanu planszy do pliku.
*
* Jesli plik podany jako pierwszy argument istnieje oraz wskaznik ppoczatkowy obiektu podanego jako drugi argument na cos wskazuje,
* operator zapisuje w pliku aktualny stan planszy wskazanej przez wskaznik ppoczatkowy obiektu klasy wspolrzedne.
* Operator uzywa pomocniczego wskaznika ktorym przesuwa sie po planszy i uzywa przeciazonego operatora << dla kazdego elementu planszy.
* Jesli nie ma planszy, operator nic nie robi.
* Jesli nie istnieje podalny plik, operator wyrzuca wyjatek.
* \param plik strumien ofstream, plik do ktorego zapisany bedzie aktualny stan planszy.
* \param ob obiekt klasy wyswietl, z ktorego ma zostac zapisany stan planszy(wskazywanej przez wskaznik ppoczatkowy).
* \return strumien oftream.
*/
std::ofstream & operator <<(std::ofstream &plik, wyswietl &ob);

//pozostale operatory znajduja sie w klasach: plansza, wypelnij, sasiedzi

#endif // !OPERATORY
