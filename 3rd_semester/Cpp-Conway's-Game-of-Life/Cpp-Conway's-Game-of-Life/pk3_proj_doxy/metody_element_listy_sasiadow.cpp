#include <iostream>
#include "klasa_element_listy_sasiadow.h"
#include "komunkiaty_wyjatki.h"

element_listy_sasiadow::element_listy_sasiadow()
{
}

element_listy_sasiadow::element_listy_sasiadow(element_listy_sasiadow * pn, int l_s) : pnext(pn), liczba_sasiadow(l_s)
{
}

element_listy_sasiadow * element_listy_sasiadow::getn()
{
	if (this)
		return pnext;
	else
	{
		throw kom_brak_ob_element_listy_sasiadow();
		return nullptr;
	}
}

int element_listy_sasiadow::get_l_sasiadow()
{
	if (this)
		return liczba_sasiadow;
	else
	{
		throw kom_brak_ob_element_listy_sasiadow();
		return -1;
	}
}

void element_listy_sasiadow::setn(element_listy_sasiadow * pn)
{
	if (this)
		pnext = pn;
	else
		throw kom_brak_ob_element_listy_sasiadow();
}

void element_listy_sasiadow::set_l_sasiadow(int l_s)
{
	if (this)
		liczba_sasiadow = l_s;
	else
		throw kom_brak_ob_element_listy_sasiadow();
}