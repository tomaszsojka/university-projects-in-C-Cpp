#include "stdafx.h"
#include <iostream>
#define _USE_MATH_DEFINES
#include <math.h>
#include <time.h>
#include <iomanip>
#include <fstream>
#include <string>
#include <stdlib.h>
using namespace std;

void wprowadzaniedanych(int R, int M, int D, tm*data)
{
	data->tm_mday = D;
	data->tm_mon = M - 1;      //miesiace w strukturze tm sa liczone 0-11
	data->tm_year = R - 1900;  // rok w strukturze tm jest liczony od 1900
}//wprowadzanie danych
time_t timetdata(int R, int M, int D, tm*data, time_t datasek)
{
	datasek = mktime(data);    //zmiana daty poczatkowej z tm na time_t
	return datasek;
}// zmiana czasu na time_t                    

double kat(double x) //zamiana na radianay
{
	double kat=M_PI*x/180;
	return kat;
}

struct dane_astronomiczne
{
	double Wys = -0.833;
	double j, wiek, a, b, c, d, e, f, g;
}dane;


void obliczenia(int R, int M, int D, double Lat, double Lon, int Stref)
{
	dane.j = 367 * R - int(7 * (R + int((M + 9) / 12)) / 4) + int(275 * M / 9) + D - 730531.5;
	dane.wiek = dane.j / 36525;
	dane.a = fmod((4.8949504201433 + 628.331969753199*dane.wiek), 2 * M_PI);
	dane.b = fmod((6.2400408 + 628.3019501*dane.wiek), 2 * M_PI);
	dane.c = 0.409093 - 0.0002269*dane.wiek;
	dane.d = 0.033423*sin(dane.b) + 0.00034907*sin(2 * dane.b);
	dane.e = 0.0430398*sin(2 * (dane.a + dane.d)) - 0.00092502*sin(4 * (dane.a + dane.d)) - dane.d;
	dane.f = asin(sin(dane.c)*sin(dane.a + dane.d));
	dane.g = (sin(kat(dane.Wys)) - sin(kat(Lat))*sin(dane.f)) / (cos(kat(Lat))*cos(dane.f));
}//obliczenia godziny wschodu

double obliczeniawschodu(int R, int M, int D, double Lat, double Lon, int Stref)
{
	double Wsch = (M_PI - (dane.e + kat(Lon) + 1 * acos(dane.g))) * 180 / M_PI / 15 + Stref;// godzina wschodu (+godziny strefowe)
	return Wsch;
}//obliczenia godziny wschodu

double obliczeniazachodu(int R, int M, int D, double Lat, double Lon, int Stref)
{
	double Zach = (M_PI - (dane.e + kat(Lon) - 1 * acos(dane.g))) * 180 / M_PI / 15 + Stref;// godzina zachodu (+godziny strefowe)
	return Zach;
} //obliczenia godziny zachodu

void wypisywanienaglowka(const string &nazwa, double Lat, double Lon, int Stref)
{
	ofstream plik(nazwa);
	if (plik)
	{
		plik << setw(25) << "WSCHODY I ZACHODY SLONCA" << endl;
		if (Lat>0)
			plik << setw(18) << "szerokosc :  " << setw(3) << Lat << setw(2) << 'N' << endl;
		else if (Lat<0)
			plik << setw(18) << "szerokosc :  " << setw(3) << Lat << setw(2) << 'S' << endl;
		else
			plik << setw(18) << "szerokosc :  " << setw(3) << Lat << endl;
		if (Lon > 0)
			plik << setw(18) << "dlugosc   :  " << setw(3) << Lon << setw(2) << 'E' << endl;
		else if (Lon < 0)
			plik << setw(18) << "dlugosc   :  " << setw(3) << Lon << setw(2) << 'W' << endl;
		else
			plik << setw(18) << "dlugosc   :  " << setw(3) << Lon << endl;
		if (Stref > 0)
			plik << setw(20) << "strefa    :   +" << setw(3) << Stref << endl << endl;
		else
			plik << setw(18) << "strefa    :  " << setw(3) << Stref << endl << endl;

		plik << setw(7) << "data" << setw(11) << "wschod" << setw(8) << "zachod" << endl;
		plik.close();
	}
} //wypisanie naglowka

void wypisywaniegodziny(const string &nazwa, time_t datasek, tm*data, double sekundy, int R, int M, int D, double Lat, double Lon, double Stref)
{
	ofstream plik(nazwa, ios_base::app);//wpisywanie za naglowkiem , ktory zostal juz wpisany do pliku funkcja wypisywanienaglowka

	if (plik)
	{
		datasek = datasek - 86400;//-1 dzien , poniewaz petla w funkcji wypisywaniegodziny zaczyna sie od nastepnego dnia
		for (int i = 0; i <= sekundy; i++)
		{
			datasek = datasek + 86400; // dodaje 1 dzien
			data = localtime(&datasek);
			R = data->tm_year + 1900; //wypisuje poprawny rok do algorytmu
			M = data->tm_mon + 1;     //wypisuje poprawny miesiac do algorytmu
			D = data->tm_mday;       //wypisuje poprawny dzien do algorytmu
			obliczenia(R, M, D, Lat, Lon, Stref); // dodane przy wersji ze struktura
			int minw = int(60 * (obliczeniawschodu(R, M, D, Lat, Lon, Stref) - int(obliczeniawschodu(R, M, D, Lat, Lon, Stref)))); //minuty wschodu
			int minz = int(60 * (obliczeniazachodu(R, M, D, Lat, Lon, Stref) - int(obliczeniazachodu(R, M, D, Lat, Lon, Stref)))); //minuty zachodu
			plik << R << '-' << setw(2) << setfill('0') << M << '-' << setw(2) << setfill('0') << D <<     //wyswietlanie daty
				"   " << setw(2) << setfill('0') << int(obliczeniawschodu(R, M, D, Lat, Lon, Stref)) << ':' << setw(2) << setfill('0') << minw << //wyswietlanie godziny wschodu
				"   " << setw(2) << setfill('0') << int(obliczeniazachodu(R, M, D, Lat, Lon, Stref)) << ':' << setw(2) << setfill('0') << minz << endl;    //wyswietlanie godziny zachodu
		}
		plik.close();
	}
} // wypisywanie godzin wschodów i zachodów dla podanych dni


bool odczytajargumenty(int ile, char * argumenty[], string & nazwa, double & Lat, double & Lon, int & R, int & M, int & D, int & R2, int & M2, int & D2, int & Strefa)
{
	const string ETYKIETA_NAZWA("-o");
	const string ETYKIETA_DATAPOCZATKOWA("-s");
	const string ETYKIETA_DATAKONCOWA("-k");
	const string ETYKIETA_DLUGOSC("--lon");
	const string ETYKIETA_SZEROKOSC("--lat");
	const string ETYKIETA_STREFA("-t");
	const int FLAGA_NAZWA = 1;
	const int FLAGA_DATAPOCZATKOWA = FLAGA_NAZWA << 1;
	const int FLAGA_DATAKONCOWA = FLAGA_DATAPOCZATKOWA << 1;
	const int FLAGA_DLUGOSC = FLAGA_DATAKONCOWA << 1;
	const int FLAGA_SZEROKOSC = FLAGA_DLUGOSC << 1;
	const int FLAGA_STREFA = FLAGA_SZEROKOSC << 1;

	const int POPRAWNY_WYNIK = FLAGA_NAZWA | FLAGA_DATAPOCZATKOWA | FLAGA_DATAKONCOWA | FLAGA_DLUGOSC | FLAGA_SZEROKOSC | FLAGA_STREFA;

	int wynik = 0;

	for (int i = 0; i < ile; i++)
	{
		string arg(argumenty[i]);
		if (arg == ETYKIETA_NAZWA)
		{
			nazwa = argumenty[i + 1];
			wynik |= FLAGA_NAZWA;
		}
		if (arg == ETYKIETA_DATAPOCZATKOWA)
		{
			string datapoczatkowa = argumenty[i + 1];
			string rokpoczatkowy;
			string miesiacpoczatkowy;
			string dzienpoczatkowy;
			string delimiter = "-";

			size_t pos;
			pos = datapoczatkowa.find(delimiter);

			rokpoczatkowy = datapoczatkowa.substr(0, pos);
			datapoczatkowa.erase(0, pos + delimiter.length());

			pos = datapoczatkowa.find(delimiter);
			miesiacpoczatkowy = datapoczatkowa.substr(0, pos);
			datapoczatkowa.erase(0, pos + delimiter.length());

			pos = datapoczatkowa.find(delimiter);
			dzienpoczatkowy = datapoczatkowa.substr(0, pos);
			datapoczatkowa.erase(0, pos + delimiter.length());

			try
			{
				D = stoi(dzienpoczatkowy);
				M = stoi(miesiacpoczatkowy);
				R = stoi(rokpoczatkowy);
			}
			catch (exception &ex)
			{
				return false;
			}

			wynik |= FLAGA_DATAPOCZATKOWA;

		}
		if (arg == ETYKIETA_DATAKONCOWA)
		{
			string datakoncowa = argumenty[i + 1];
			string rokkoncowy;
			string miesiackoncowy;
			string dzienkoncowy;
			string delimiter = "-";

			size_t pos;
			pos = datakoncowa.find(delimiter);

			rokkoncowy = datakoncowa.substr(0, pos);
			datakoncowa.erase(0, pos + delimiter.length());

			pos = datakoncowa.find(delimiter);
			miesiackoncowy = datakoncowa.substr(0, pos);
			datakoncowa.erase(0, pos + delimiter.length());

			pos = datakoncowa.find(delimiter);
			dzienkoncowy = datakoncowa.substr(0, pos);
			datakoncowa.erase(0, pos + delimiter.length());

			try
			{
				D2 = stoi(dzienkoncowy);
				M2 = stoi(miesiackoncowy);
				R2 = stoi(rokkoncowy);
			}
			catch (exception &ex)
			{
				return false;
			}
			wynik |= FLAGA_DATAKONCOWA;
		}
		if (arg == ETYKIETA_DLUGOSC)
		{
			try
			{
				Lon = stod(argumenty[i + 1]);
			}
			catch (exception &ex)
			{
				return false;
			}
			wynik |= FLAGA_DLUGOSC;
		}
		if (arg == ETYKIETA_SZEROKOSC)
		{
			
			try
			{
				Lat = stod(argumenty[i + 1]);
			}
			catch (exception &ex)
			{
				return false;
			}
			wynik |= FLAGA_SZEROKOSC;
		}
		if (arg == ETYKIETA_STREFA)
		{
			try
			{
				Strefa = stoi(argumenty[i + 1]);
			}
			catch (exception &ex)
			{
				return false;
			}
			wynik |= FLAGA_STREFA;
		}

	}

	if (wynik == POPRAWNY_WYNIK)
		return true;
	else
		return false;
}

void funkcjakoncowa(int &R, int &M, int &D, int &R2, int &M2, int &D2, int &Stref, int &sekundy, double &Lat, double &Lon, string &nazwa)
{
	tm * data;//data poczatkowa
	time_t datasek;
	time(&datasek);
	data = localtime(&datasek);
	wprowadzaniedanych(R, M, D, data);//wprowadzenie danych daty poczatkowej
	datasek = timetdata(R, M, D, data, datasek);//data poczatkowa w time_t

	tm*data2;//data koncowa
	time_t datasek2;
	time(&datasek2);
	data2 = localtime(&datasek2);
	wprowadzaniedanych(R2, M2, D2, data2);//wprowadzenie danych daty koncowej
	datasek2 = timetdata(R2, M2, D2, data2, datasek2);//data koncowa w time_t

	sekundy = difftime(datasek2, datasek) / 86400; // ilosc dni od daty poczatkowej do koncowej(86400-liczba sekund jednej doby)
	
		wypisywanienaglowka(nazwa, Lat, Lon, Stref); // wypisanie naglowka
		wypisywaniegodziny(nazwa, datasek, data, sekundy, R, M, D, Lat, Lon, Stref); // wypisywanie godzin wschodów i zachodów dla podanych dni
	
}

int main(int argc, char **argv)
{
	int Stref, sekundy, D, R, M, D2, M2, R2;
	double Lat, Lon;
	string nazwa;
	if ((odczytajargumenty(argc, argv, nazwa, Lat, Lon, R, M, D, R2, M2, D2, Stref) == false) || (Lat > 90) || (Lat < -90) || (Lon > 180) || (Lon < -180) || (Stref < -12) || (Stref > 14) || (R<1970) || (R2<1970))
	{			//zakres szerokosci geo. <-90;90>, zakres dlugosci geo. <-180;180>, zakres stref <-12;14>, czas w time_t zaczyna sie od 1900-01-01 00:00
		cout << "Nieprawidlowe parametry lub dane spoza zakresu"<<endl;
		return 0;
	}

	funkcjakoncowa(R, M, D, R2, M2, D2, Stref, sekundy, Lat, Lon, nazwa);


	return 0;
}