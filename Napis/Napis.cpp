#include "Napis.h"

#if OUTFILE

namespace lib
{
	/* ZEBRAC FRIEND FUNKCJE TU */
}

/////////////////////////////////////////
//
//       KONSTRUKTORY I DESTRUKTOR
//
/////////////////////////////////////////
Napis::Napis(unsigned size)
{
	dlugosc = size;
	napis = new char[dlugosc + 1];
}

Napis::Napis(const char* n)
{
	dlugosc = strlen(n);
	napis = new char[dlugosc + 1];
	strcpy(napis, n);
}

Napis::Napis(const Napis& wzor)
{
	dlugosc = wzor.dlugosc;
	//napis = wzor.napis;
	napis = new char[dlugosc + 1];
	strcpy(napis, wzor.napis);
}

Napis::~Napis()
{
	delete[] napis;
}

/////////////////////////////////////////
//
//		NIEOKRESLONE FUNKCJE KLASY
//
/////////////////////////////////////////

unsigned Napis::Dlugosc() { return dlugosc; }
unsigned Napis::ZajetaPamiec() { return sizeof(napis); }

bool Napis::SprawdzCzyPusty()
{
	if (dlugosc == NULL) return true;
	else return false;
}

bool SprawdzCzyPusty(const Napis& n1)
{
	if (n1.dlugosc == NULL) return true;
	else return false;
}

void Napis::WstawZamiastZnaku(const Napis& n, int x) { WstawZamiastZnaku(n.napis, x); }
void Napis::WstawZamiastZnaku(const char* napis, int x)
{
	unsigned size = strlen(napis);
	dlugosc += size - 1;
	char* nowy = new char[dlugosc + 1];
	strncpy(nowy, this->napis, x);
	nowy[x] = NULL;
	strcat(nowy, napis);
	strcat(nowy, this->napis + x + 1);
	delete[] this->napis;
	this->napis = nowy;
}

void Napis::NadpiszNapis(const Napis& n, unsigned x) { NadpiszNapis(n.napis, x); }
void Napis::NadpiszNapis(const char* napis, unsigned x)
{
	unsigned size = strlen(napis);
	if (size > dlugosc - x)
	{
		dlugosc += abs(static_cast <int>(dlugosc - size - x));
		char* nowy = new char[dlugosc + 1];
		strcpy(nowy, this->napis);
		delete[] this->napis;
		this->napis = nowy;
		for (unsigned i = x, j = 0; j < size + 1; i++, j++)
			this->napis[i] = napis[j];
	}
	else
	{
		for (unsigned i = x, j = 0; j < size; i++, j++)
			this->napis[i] = napis[j];
	}
}

void Napis::WstawPrzedZnakiem(const Napis& n, unsigned x) { WstawPrzedZnakiem(n.napis, x); }
void Napis::WstawPrzedZnakiem(const char* napis, unsigned x)
{
	unsigned dlugosc = strlen(napis);
	this->dlugosc += dlugosc;
	char* nowy = new char[this->dlugosc + 1];
	strncpy(nowy, this->napis, x);
	nowy[x] = NULL;
	strcat(nowy, napis);
	strcat(nowy, this->napis + x);
	delete[] this->napis;
	this->napis = nowy;
}

void Napis::ZamienNapisy(Napis& n1)
{
	char* nowy;
	nowy = this->napis;
	this->napis = n1.napis;
	n1.napis = nowy;
}

void ZamienNapisy(Napis& n1, Napis& n2)
{
	char* nowy;
	nowy = n1.napis;
	n1.napis = n2.napis;
	n2.napis = nowy;
}

/////////////////////////////////////////
/////////// WIELKOSC ZNAKOW /////////////
/////////////////////////////////////////

void Napis::ZamienNaMaleZnak(unsigned x)
{
	if (napis[x] > 64 && napis[x] < 93)
		napis[x] = napis[x] + 32;
}

void Napis::ZamienNaDuzeZnak(unsigned x)
{
	if (napis[x] > 96 && napis[x] < 123)
		napis[x] = napis[x] - 32;
}

void Napis::ZamienNaMaleWszystko()
{
	for (unsigned i = 0; i < dlugosc; i++)
	{
		if (napis[i] > 64 && napis[i] < 93)
			napis[i] = napis[i] + 32;
	}
}

void Napis::ZamienNaDuzeWszystko()
{
	for (unsigned i = 0; i < dlugosc; i++)
	{
		if (napis[i] > 96 && napis[i] < 123)
			napis[i] = napis[i] - 32;
	}
}

/////////////////////////////////////////
//
//		FUNKCJE KONWERTUJACE NAPIS
//
/////////////////////////////////////////

template <typename T>
static Napis KonwertujNaNapis(T zmienna)
{
	//Napis n1;
	std::stringstream os;
	os << zmienna;
	Napis n1(os.str().c_str());
	return n1;
}

/////////////////////////////////////////
////////////// STATYCZNE ////////////////
/////////////////////////////////////////

double NapisNaDouble(const Napis& n1) { return atof(n1.napis); }
float NapisNaFloat(const Napis& n1) { return static_cast<float>(atof(n1.napis)); }
int NapisNaInt(const Napis& n1) { return atoi(n1.napis); }
unsigned NapisNaUnsigned(const Napis& n1) { return static_cast<unsigned>(atoi(n1.napis)); }

/////////////////////////////////////////
///////////// OBIEKT KLASY //////////////
/////////////////////////////////////////

double Napis::NapisNaDouble() { return atof(this->napis); }
float Napis::NapisNaFloat() { return static_cast<float>(atof(this->napis)); }
int Napis::NapisNaInt() { return atoi(this->napis); }
unsigned Napis::NapisNaUnsigned() { return static_cast<unsigned>(atoi(this->napis)); }

/////////////////////////////////////////
//
//	 FUNKCJE SZUKAJACE ORAZ DZIALAJACE
//	 NA FRAGMANTACH(PRZEDZIALACH) NAPISU
//
/////////////////////////////////////////

bool Napis::SprawdzCzyIstnieje(const Napis& szukany)
{
	char* istnieje = NULL;
	istnieje = strstr(napis, szukany.napis);
	if (istnieje) return true;
	else return false;
}

bool SprawdzCzyIstnieje(const Napis& n1, const Napis& szukany)
{
	char* istnieje = NULL;
	istnieje = strstr(n1.napis, szukany.napis);
	if (istnieje) return true;
	else return false;
}

unsigned Napis::ZnajdzWnapisie(const Napis& szukany)
{
	char* wynik = strstr(napis, szukany.napis);
	unsigned index = wynik - napis;
	//unsigned substringLength = dlugosc - index;
	return index;
}

unsigned ZnajdzWnapisie(const Napis& n1, const Napis& szukany)
{
	char* wynik = strstr(n1.napis, szukany.napis);
	unsigned index = wynik - n1.napis;
	//unsigned substringLength = dlugosc - index;
	return index;
}

Napis Napis::ZwrocPodnapis(unsigned x, unsigned dl)
{
	if (dlugosc + 1 - (x + 1) < dl) dl = dlugosc + 1 - (x + 1);
	char* nowy = new char[dl + 1];
	nowy[0] = NULL;
	for (unsigned i = 0; i < dl; i++)
		nowy[i] = napis[i + x];
	nowy[dl] = NULL;
	Napis n1(nowy);
	delete[] nowy;
	return n1;
}

void Napis::UsunZnapisu(unsigned x, unsigned dl)
{
	if (dlugosc - (x + 1) > dl)
	{
		char* nowy = new char[dlugosc - dl + 1];
		strncpy(nowy, napis, x);
		nowy[x] = NULL;
		strcat(nowy, this->napis + dlugosc - x - dl);
		delete[] this->napis;
		this->napis = nowy;
		dlugosc -= dl + 1;
	}
	else
	{
		dl = dlugosc - (x + 1);
		char* nowy = new char[dlugosc - dl + 1];
		nowy[x] = NULL;
		strncpy(nowy, napis, x);
		delete[] this->napis;
		this->napis = nowy;
		dlugosc -= dl + 1;
	}
}

/////////////////////////////////////////
//
//		OPERATORY ==, != i FUNKCJE
//		SPRAWDZAJACE ROWNOSC TABLIC 	
//
/////////////////////////////////////////

bool operator == (const Napis& n1, const Napis& n2)
{
	if (strcmp(n1.napis, n2.napis) == 0) return true;
	else return false;
}

bool operator != (const Napis& n1, const Napis& n2)
{
	if (strcmp(n1.napis, n2.napis) != 0) return true;
	else return false;
}

bool Napis::SprawdzRownosc(const Napis& n1)
{
	if (strcmp(n1.napis, napis) == 0) return true;
	else return false;
}

bool Napis::SprawdzRownosc(const char* napis)
{
	if (strcmp(this->napis, napis) == 0) return true;
	else return false;
}

bool SprawdzRownosc(const Napis& n1, const Napis& n2)
{
	if (strcmp(n1.napis, n2.napis) == 0) return true;
	else return false;
}

/////////////////////////////////////////
//
//	  OPERATORY >, >=, <, <= i FUNKCJE
//	  POROWNOJACE TABLICE	
//
/////////////////////////////////////////

bool operator > (const Napis& n1, const Napis& n2)
{
	if (strcmp(n1.napis, n2.napis) < 0) return true;
	else return false;
}

bool operator >= (const Napis& n1, const Napis& n2)
{
	if (strcmp(n1.napis, n2.napis) <= 0) return true;
	else return false;
}

bool operator < (const Napis& n1, const Napis& n2)
{
	if (strcmp(n1.napis, n2.napis) > 0) return true;
	else return false;
}

bool operator <= (const Napis& n1, const Napis& n2)
{
	if (strcmp(n1.napis, n2.napis) >= 0) return true;
	else return false;
}

Napis& Napis::ZwrocWiekszy(Napis& n1)
{
	if (strcmp(this->napis, n1.napis) < 0) return *this;
	else return n1;
}

Napis& Napis::ZwrocMniejszy(Napis& n1)
{
	if (strcmp(this->napis, n1.napis) > 0) return *this;
	else return n1;
}

Napis& ZwrocWiekszy(Napis& n1, Napis& n2)
{
	if (strcmp(n1.napis, n2.napis) < 0) return n1;
	else return n2;
}

Napis& ZwrocMniejszy(Napis& n1, Napis& n2)
{
	if (strcmp(n1.napis, n2.napis) > 0) return n1;
	else return n2;
}

/////////////////////////////////////////
//
//    OPERATORY = NADPISUJACE TABLICE
//
/////////////////////////////////////////

Napis& Napis::operator = (const Napis& wzor)
{
	if (this != &wzor) // obj = obj;
	{
		delete[] napis;
		dlugosc = wzor.dlugosc;
		napis = new char[dlugosc + 1];
		strcpy(napis, wzor.napis);
	}
	return *this;
}

Napis& Napis::operator = (const char* napis)
{
	delete[] this->napis;
	dlugosc = strlen(napis);
	this->napis = new char[dlugosc + 1];
	//this->napis = napis;
	strcpy(this->napis, napis);
	return *this;
}

/////////////////////////////////////////
//
//     OPERATORY + DODAJACE TABLICE
//
/////////////////////////////////////////

Napis Napis::operator + (const Napis& n2)const
{
	unsigned size = this->dlugosc + n2.dlugosc;
	Napis suma(size);

	strcpy(suma.napis, napis);
	strcat(suma.napis, n2.napis);
	return suma;
}

Napis operator + (const char* napis, Napis& n2)
{
	Napis dodane;
	dodane = n2 + napis;
	return dodane;
}

/////////////////////////////////////////
//
//   OPERATORY += DOPISUJACE DO TABLICY
//
/////////////////////////////////////////

Napis& Napis::operator += (const Napis& n2)
{
	// obj1 = obj1 + obj2

	dlugosc += n2.dlugosc;
	char* copy = new char[dlugosc + 1];

	strcpy(copy, this->napis);
	strcat(copy, n2.napis);
	delete[] napis;
	napis = copy;

	return *this;
}

Napis& Napis::operator += (const char* napis)
{
	dlugosc += strlen(napis);
	char* copy = new char[dlugosc + 1];

	strcpy(copy, this->napis);
	strcat(copy, napis);
	delete[] this->napis;
	this->napis = copy;

	return *this;
}

/////////////////////////////////////////
//
//      OPERATORY WYJSCIA i WEJSCIA
//
/////////////////////////////////////////

std::ostream& operator << (std::ostream& out, const Napis& n)
{
	return out << n.napis;
}

std::istream& operator >> (std::istream& in, Napis& n)
{
	char buff[80];
	in >> buff[0];
	in.get(buff + 1, 79);
	n = buff;
	while (in.peek() != '\n' && in)
	{
		in.get(buff, 80);
		n += buff;
	}
	in.get(); // wyciagniecie ze strumienia '\n'

	return in;
}

/////////////////////////////////////////
//
//		 OPERATORY PRZESUWAJACE
//
/////////////////////////////////////////		

Napis::Napis(Napis&& wzor) noexcept
{
	napis = wzor.napis;
	dlugosc = wzor.dlugosc;
	wzor.napis = nullptr;
	wzor.dlugosc = 0;
}

Napis& Napis::operator = (Napis&& wzor) noexcept
{
	napis = wzor.napis;
	dlugosc = wzor.dlugosc;
	wzor.napis = nullptr;
	wzor.dlugosc = 0;
	return *this;
}

/////////////////////////////////////////
//
//   OPERATOR [] i FUNKCJA ODWOLUJACA
//   SIE DO DANEGO MIEJSCA W TABLICY
//
/////////////////////////////////////////

char& Napis::operator [] (unsigned x)
{
	if (x < dlugosc - 1)
		return napis[x];
	else throw 1;
}

// Funkcja zwracajaca znak z danego indexu napisu
char& Napis::Znak(unsigned x)
{
	if (x < dlugosc - 1)
		return napis[x];
	else throw 1;
}
  
#endif
