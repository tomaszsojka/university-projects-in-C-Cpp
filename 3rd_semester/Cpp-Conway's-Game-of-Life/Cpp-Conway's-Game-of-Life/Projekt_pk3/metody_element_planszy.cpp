#include <iostream>
#include "klasa_element_planszy.h"
#include "komunkiaty_wyjatki.h"

element_planszy * element_planszy::getp()
{
	if (this)
		return pprawy;
	else
	{
		throw kom_brak_ob_element_planszy();
		return nullptr;
	}
}
element_planszy * element_planszy::getl()
{
	if (this)
		return plewy;
	else
	{
		throw kom_brak_ob_element_planszy();
		return nullptr;
	}
}
element_planszy * element_planszy::getd()
{
	if (this)
		return pdolny;
	else
	{
		throw kom_brak_ob_element_planszy();
		return nullptr;
	}
}
element_planszy * element_planszy::getg()
{
	if (this)
		return pgorny;
	else
	{
		throw kom_brak_ob_element_planszy();
		return nullptr;
	}
}
bool element_planszy::get_czy_zyje()
{
	if (this)
		return czy_zyje;
	else
	{
		throw kom_brak_ob_element_planszy();
		return nullptr;
	}
}
void element_planszy::setp(element_planszy * pp)
{
	int x = 0;
	if (this )
		pprawy = pp;
	else
		throw kom_brak_ob_element_planszy();
}
void element_planszy::setl(element_planszy * pl)
{
	if (this)
		plewy = pl;
	else
		throw kom_brak_ob_element_planszy();
}
void element_planszy::setd(element_planszy * pd)
{
	if (this)
		pdolny = pd;
	else
		throw kom_brak_ob_element_planszy();
}
void element_planszy::setg(element_planszy * pg)
{
	if (this)
		pgorny = pg;
	else
		throw kom_brak_ob_element_planszy();
}

void element_planszy::set_czy_zyje(bool zyje)
{
	if (this)
		czy_zyje = zyje;
	else
		throw kom_brak_ob_element_planszy();
}