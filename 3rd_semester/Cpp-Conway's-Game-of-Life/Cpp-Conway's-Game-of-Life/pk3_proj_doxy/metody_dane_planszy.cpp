#include <iostream>
#include "klasa_dane_planszy.h"
#include "komunkiaty_wyjatki.h"

element_planszy * dane_planszy::get_pocz()
{
	if (this)
		return ppoczatkowy;
	else
	{
		throw kom_brak_dost_do_ob_dane_planszy();
		return nullptr;
	}
}
int dane_planszy::get_roz()
{
	if (this)
		return rozmiar;
	else
	{
		throw kom_brak_dost_do_ob_dane_planszy();
		return -1;
	}
}
void dane_planszy::set_pocz(element_planszy * pp)
{
	if (this)
		ppoczatkowy = pp;
	else
		throw kom_brak_dost_do_ob_dane_planszy();
}
void dane_planszy::set_roz(int r)
{
	if (this)
		rozmiar = r;
	else
		throw kom_brak_dost_do_ob_dane_planszy();
}
