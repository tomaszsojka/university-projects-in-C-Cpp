#include <iostream>
#include "klasa_element_planszy.h"
#include "klasa_dane_planszy.h"
#include "klasa_wyswietl.h"
#include "operatory.h"
#include <string>
#include <fstream>
#include "komunkiaty_wyjatki.h"


void wyswietl::wyswietl_plansze()
{
	if (this)
	{
		std::cout << *this;
	}
	else
		throw kom_brak_ob_wyswietl();
}

void wyswietl::zapisz_plansze()
{
	std::string nazwa_pliku;
	int idx = 0;
	std::cout << "Podaj nazwe pliku w ktorym zostanie zapisany aktualny stan planszy. " << std::endl;
	std::cin >> nazwa_pliku;
	getchar();
	try
	{
		std::ofstream plik(nazwa_pliku);
	
	plik << *this;
	}
	catch (std::string ex)
	{
		wyswietl_komunikat(ex);
	}
}

