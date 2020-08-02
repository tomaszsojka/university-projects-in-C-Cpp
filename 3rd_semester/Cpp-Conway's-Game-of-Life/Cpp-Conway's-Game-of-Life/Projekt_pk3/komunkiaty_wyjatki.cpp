#include <iostream>
#include "komunkiaty_wyjatki.h"
#include <string>

void wyswietl_komunikat(std::string str)
{
	std::cout << str << std::endl;
}

std::string kom_brak_dost_do_ob_dane_planszy()
{
	return std::string("Nie ma dostepu do obiektu dane_planszy. Cos poszlo nie tak");
}

std::string kom_brak_ob_element_planszy()
{
	return std::string("Nie ma dostepu do obiektu element_planszy. Cos poszlo nie tak");
}

std::string kom_brak_ob_wypelnij()
{
	return std::string("Nie ma dostepu do obiektu wyswietl. Cos poszlo nie tak");
}

std::string kom_wsp_spoza_planszy()
{
	return std::string("Ktoras wspolrzedna wskazuje poza plansze. Zmien dane w pliku");
}

std::string kom_brak_wsp_y()
{
	return std::string("Nie podano drugiej wspolrzednej y ostatniego punktu do ozywienia. Ostatni punkt nie zostanie wczytany przez program");
}

std::string kom_brak_ob_wyswietl()
{
	return std::string("Nie ma dostepu do obiektu wypelnij. Cos poszlo nie tak");
}

std::string kom_brak_pliku()
{
	return std::string("Plik o podanej nazwie nie istnieje");
}

std::string kom_brak_ob_element_listy_sasiadow()
{
	return std::string("Nie ma dostepu do obiektu element__listy_sasiadow. Cos poszlo nie tak");
}
