////////////////////////////////////
//    LIBRARY BY Michal Haldas    //
////////////////////////////////////

/*
------------------------------------------
				TO DO: 
	1. UNRESOLVED EXTERNAL SYMBOL "PRIVATE..." - naprawic
	2. Zrobic wyjatki / pomijanie specjalych przypadkow
-----------------------------------------
*/

#pragma once

#define _CRT_SECURE_NO_WARNINGS
#define OUTFILE true // gdy true - plik napis.cpp wlaczony 

#include <iostream>
#include <cmath>
#include <sstream>

#if !OUTFILE
	#include "NapisInline.h"

#elif OUTFILE

class Napis
{
private:
	char* napis;
	unsigned dlugosc{};

	// Konstruktor kopiujacy
	Napis(unsigned size);

public:
	Napis(const char* n = "");
	Napis(const Napis& wzor);
	Napis(Napis&& wzor) noexcept;
	~Napis();

	/////////////////////////////////////////
	//				FUNKCJE                //
	/////////////////////////////////////////

	// Funkcja zwracajaca dlugosc napisu
	unsigned Dlugosc();

	// Funkcja zwracajaca ilosc zajetej pamieci przez napis
	unsigned ZajetaPamiec();

	// Funkcja sprawdzajaca czy napis jest pusty
	bool SprawdzCzyPusty();

	// Funkcja zastepujaca wybrany znak podanym napisem
	void WstawZamiastZnaku(const char* napis, int x = 0);

	// Funkcja zastepujaca wybrany znak podanym napisem
	void WstawZamiastZnaku(const Napis& n, int x = 0);

	// Funkcja zastepujaca wszytkie kolejne znaki podanym napisem
	void NadpiszNapis(const char* napis, unsigned x = 0);

	// Funkcja zastepujaca wszytkie kolejne znaki podanym napisem
	void NadpiszNapis(const Napis& n, unsigned x = 0);

	// Funkcja wstawiajaca tekst przed wybranym znakiem napisu
	void WstawPrzedZnakiem(const char* napis, unsigned x = 0);

	// Funkcja wstawiajaca tekst przed wybranym znakiem napisu
	void WstawPrzedZnakiem(const Napis& n, unsigned x = 0);

	// Funkcja zamieniajaca ze soba napisy (dziala na zasadzie swap)
	void ZamienNapisy(Napis& n1);

	// Funkcja zamieniajaca konkretny znak napisu na maly
	void ZamienNaMaleZnak(unsigned x = 0);

	// Funkcja zamieniajaca konkretny znak napisu na duzy
	void ZamienNaDuzeZnak(unsigned x = 0);

	// Funkcja zamieniajaca caly napis na maly
	void ZamienNaMaleWszystko();

	// Funkcja zamieniajaca caly napis na duzy
	void ZamienNaDuzeWszystko();

	// Funkcja konwertujaca napis na zmienna typu double
	double NapisNaDouble();

	// Funkcja konwertujaca napis na zmienna typu float
	float NapisNaFloat();

	// Funkcja konwertujaca napis na zmienna typu int
	int NapisNaInt();

	// Funkcja konwertujaca napis na zmienna typu unsigned
	unsigned NapisNaUnsigned();

	// Funkcja sprawdzajaca czy dany podnapis istnieje w napisie
	bool SprawdzCzyIstnieje(const Napis& szukany);

	// Funkcja zwracajaca index szukanego podnapisu z napisu
	unsigned ZnajdzWnapisie(const Napis& szukany);

	// Funkcja zwracajaca wybrany fragment z napisu
	// x - index poczatkowy napisu, dl - jak dlugi ma byc podnapis
	Napis ZwrocPodnapis(unsigned x, unsigned dl);

	// Funkcja usuwajaca wybrany fragment z napisu
	// x - odkad ma byc wyciete, dl - jak dlugie ma byc wyciecie
	void UsunZnapisu(unsigned x, unsigned dl);

	// Funkcja sprawdzajaca czy napisy sa takie same
	bool SprawdzRownosc(const Napis& n1);

	// Funkcja sprawdzajaca czy napisy sa takie same
	bool SprawdzRownosc(const char* napis);

	// Funkcja zwracajaca "wiekszy" napis
	// (ex. "ala" > "ola")
	Napis& ZwrocWiekszy(Napis& n1);

	// Funkcja zwracajaca "mniejszy" napis
	// (ex. "ala" > "ola")
	Napis& ZwrocMniejszy(Napis& n1);

	// Funkcja zwracajaca znak z danego indexu napisu
	char& Znak(unsigned x);

	/////////////////////////////////////////
	//		  FUNKCJE ZAPRZYJAZNIONE       //
	/////////////////////////////////////////

	// Statyczna funkcja sprawdzajaca czy napis jest pusty
	friend bool SprawdzCzyPusty(const Napis& n1);

	// Statyczna funkcja zamieniajaca ze soba napisy (dziala na zasadzie swap)
	friend void ZamienNapisy(Napis& n1, Napis& n2);

	//Funkcja konwertujaca dowolny typ zmiennej na napis
	template <typename T>
	friend Napis KonwertujNaNapis(T zmienna);

	// Statyczna funkcja konwertujaca wybrany napis na zmienna typu double
	friend double NapisNaDouble(const Napis& n1);

	// Statyczna funkcja konwertujaca wybrany napis na zmienna typu float
	friend float NapisNaFloat(const Napis& n1);

	// Statyczna funkcja konwertujaca wybrany napis na zmienna typu int
	friend int NapisNaInt(const Napis& n1);

	// Statyczna funkcja konwertujaca wybrany napis na zmienna typu unsigned
	friend unsigned NapisNaUnsigned(const Napis& n1);

	// Statyczna funkcja sprawdzajaca czy dany podnapis istnieje w napisie
	friend bool SprawdzCzyIstnieje(const Napis& n1, const Napis& szukany);

	// Statyczna funkcja zwracajaca index szukanego podnapisu z napisu
	friend unsigned ZnajdzWnapisie(const Napis& n1, const Napis& szukany);

	// Statyczna funkcja sprawdzajaca czy napisy sa takie same
	friend bool SprawdzRownosc(const Napis& n1, const Napis& n2);

	// Statyczna funkcja zwracajaca "wiekszy" napis
	// (ex. "ala" > "ola")
	friend Napis& ZwrocWiekszy(Napis& n1, Napis& n2);

	// Statyczna funkcja zwracajaca "mniejszy" napis
	// (ex. "ala" > "ola")
	friend Napis& ZwrocMniejszy(Napis& n1, Napis& n2);

	/////////////////////////////////////////
	//				OPERATORY              //
	/////////////////////////////////////////

	friend bool operator == (const Napis& n1, const Napis& n2);
	friend bool operator != (const Napis& n1, const Napis& n2);
	friend bool operator > (const Napis& n1, const Napis& n2);
	friend bool operator >= (const Napis& n1, const Napis& n2);
	friend bool operator < (const Napis& n1, const Napis& n2);
	friend bool operator <= (const Napis& n1, const Napis& n2);
	friend std::ostream& operator << (std::ostream& out, const Napis& n);
	friend std::istream& operator >> (std::istream& in, Napis& n);
	friend Napis operator + (const char* napis, Napis& n2);
	Napis& operator = (const Napis& wzor);
	Napis& operator = (const char* napis);
	Napis operator + (const Napis& n2)const;
	Napis& operator += (const Napis& n2);
	Napis& operator += (const char* napis);
	Napis& operator = (Napis&& wzor) noexcept;
	char& operator [] (unsigned x);
};
 
#endif