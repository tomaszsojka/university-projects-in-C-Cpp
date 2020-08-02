#include <iostream>
#include "klasa_menue.h"

#include <thread>
#include <functional>

#include "klasa_element_planszy.h"
#include "klasa_dane_planszy.h"
#include "klasa_plansza.h"
#include "klasa_wypelnij.h"
#include "klasa_wspolrzedne.h"
#include "klasa_wyswietl.h"
#include "klasa_sasiedzi.h"
#include "klasa_komorka.h"
#include "operatory.h"

#include "klasa_menue.h"

#include <stdlib.h>
#include "windows.h"

bool menue::warunek_wyjscia = false;

void menue::kom_wpr_danych()
{
	std::cout << "Podaj czy chcesz wprowadzic wspolrzedne punktow z pliku, czy wprowadzic recznie:" << std::endl;
}
void menue::kom_wpr_danych_w_petli()
{
	std::cout << "1. Z pliku." << std::endl
		<< "2. Recznie." << std::endl;
}
void menue::kom_s_czy_s()
{
	std::cout << "Start, czy chcesz zakonczyc program i cos jeszcze zmienic" << std::endl;
}
void menue::kom_s_czy_s_w_petli()
{
	std::cout << "1.Start" << std::endl
		<< "2.Stop" << std::endl;
}
void menue::kom_zapis()
{
	std::cout << "Czy chcesz zapisac aktualny stan planszy do pliku ?" << std::endl;
}
void menue::kom_zapis_w_petli()
{
	std::cout << "1.Tak" << std::endl
		<< "2.Nie" << std::endl;
}
void menue::kom_stan_planszy()
{
	std::cout << "Po wprowadzeniu wsp. punktow do ozywienia tak wyglada nasza plansza:" << std::endl;
}
void menue::kom_start()
{
	std::cout << "Zaraz rozpocznie sie gra w zycie. Aby przerwac nacisnij przycisk n i zatwierdz ENTERem."<< std::endl;
}
int menue::wybor(int &zmiana_wyb)
{
	if (!zmiana_wyb)
		kom_wpr_danych();
	else if (zmiana_wyb == 1)
		kom_s_czy_s();
	else
		kom_zapis();
	int wybor = 0, clear = 0;
	while (wybor != 49 && wybor != 50)
	{
		if (!zmiana_wyb)
			kom_wpr_danych_w_petli();
		else if (zmiana_wyb == 1)
			kom_s_czy_s_w_petli();
		else
			kom_zapis_w_petli();
		wybor = getchar();
		while ((clear = getchar()) != '\n' && clear != EOF);
		system("CLS");
		if (wybor != 49 && wybor != 50)
		{
			std::cout << "Wybierz jeszcze raz" << std::endl;
		}
	}
	if (zmiana_wyb < 2 && zmiana_wyb >= 0)
		zmiana_wyb++; // inkrementacja, aby przygotowac na kolejny wybor
	else
		zmiana_wyb = 0;
	return wybor - 48;
}
void menue::petla( komorka  ko,  wyswietl  wys)
{
	for (;;)
	{
		ko.policz_sasiadow();
		ko.ozyw_zabij_lub_zostaw();

		wys.set_pocz(ko.ob->get_pocz());
		system("CLS");
		wys.wyswietl_plansze();
		if (warunek_wyjscia)
		{
			warunek_wyjscia = false;
			break;
		}
		Sleep(700);
	}
}
void menue::zatrzymaj_petle()
{
	int clear = 0;
	if ((clear = getchar()) == 'n' || clear == 'N')
	{
		getchar();
		warunek_wyjscia = true;
	}
	else
	{
		while ((clear = getchar()) != '\n' && clear != EOF);
		zatrzymaj_petle(); // rekurencyjne wywolanie, aby funkcja nie zakonczyla sie przed koncem petli
	}
}
void menue::poprowadz_uzytkownika()
{
	int zmiana_wyboru = 0;
	int w = wybor(zmiana_wyboru);

	wspolrzedne ws;
	switch (w)
	{
	case 1:
		ws.wypelnij_tab_wsp_z_pliku();
		break;
	case 2:
		ws.wypelnij_tab_wsp();
		break;
	}
	plansza pl;
	pl.set_roz(ws.get_roz());
	pl.stworz_podstawowa_plansze();
	
	ws.set_pocz(pl.get_pocz());

	ws.wypelnij_plansze();

	wyswietl wys;
	wys.set_pocz(pl.get_pocz());
	kom_stan_planszy();
	wys.wyswietl_plansze();

	w = wybor(zmiana_wyboru);
	if (w == 1)
	{
		kom_start();
		Sleep(5000);
		system("CLS");
		komorka ko;
		ko.ob = &pl;
		//watek petli
		std::thread petla_thread(petla, ko, wys);
		//watek metody do zatrzymania petli
		std::thread zatrzymaj_petle_thread(zatrzymaj_petle);
		//synchronizacja
		petla_thread.join();
		zatrzymaj_petle_thread.join();

		/* Konieczne tutaj, poniewaz ppoczatkowy obiektu wys nie zmienil sie przez podanie kopii tego obiektu jako argument. 
		Obiekt ko tez jest podany jako kopia, lecz jego polem jest wsk na ob klasy plansza i zmieniamy dopiero to co jest w tym obiekcie(jego wskaznik ppoczatkowy).
		A wiec, ta zmiana jest wykonana na oryginale i jest widoczna poza metoda petla.
		Thread domyslnie pobiera argumenty fukcji jako kopie, wiec dodanie zwyklej referencji nic tu nie pomaga, a niestety nie wiem jeszcze jak dzialac na oryginale w thread.
		*/
		wys.set_pocz(ko.ob->get_pocz()); 
		w = wybor(zmiana_wyboru);
		if(w == 1)
			wys.zapisz_plansze();
	}
}


