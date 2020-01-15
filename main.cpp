#include"Napis.h"

#define TEST 6

char* TestFunkcja(char* dst, const char* src)
{
	while (*dst++ = *src++);
	return dst;
}

int main()
{
#if TEST == 1

	Napis napis1 = "hotel: ";
	Napis napis2;

	std::cin >> napis2;
	//napis2 = "hotel ";

	//napis2 += " trivago";
	napis2 = napis1 + napis2;
	std::cout << napis2;

	std::string heh = "12345";
	heh.at(4) = 'a';

	std::cout << std::endl << heh << std::endl;

#elif TEST == 2

	Napis n1 = "case";
	Napis n2 = "sie";

	std::cout << n1 << std::endl;
	n1.NadpiszNapis(n2);
	std::cout << n1;
	std::cout << "\n" << n2 << "\n";

	if (n2 == "sie") std::cout << "\ntak\n";
	else std::cout << "\nnie\n";

	n2 = n1 + "duta";
	std::cout << std::endl << n2 << std::endl;

#elif TEST == 3

	Napis moj, twoj;
	moj = "case";
	twoj = "siema";

	moj.WstawPrzedZnakiem("pjenc", 0);
	std::cout << moj << std::endl;
	moj.ZamienNaDuzeWszystko();
	moj.ZamienNapisy(twoj);
	std::cout << moj;

#elif TEST == 4

	Napis napis = "witaj";
	double liczba = 25.368126381264856328;
#define liczba2 213.8126586328456
	std::cout << napis.KonwertujNaNapis(liczba) << std::endl;
	std::cout << Napis::KonwertujNaNapis(liczba2) << std::endl;

	std::cout << napis << std::endl;
	napis[3] = 'o';
	std::cout << napis;

#elif TEST == 5

	Napis napis1 = "abcd";
	Napis napis2 = "abd";

	if (napis1 >= napis2) std::cout << "zwrocone: TRUE\n";
	else std::cout << "zwrocone: FALSE\n";

	Napis napis3 = Napis::ZwrocWiekszy(napis1, napis2);
	std::cout << napis3 << std::endl;

	std::string test;

#elif TEST == 6

	Napis delme = "witam cie dzbanie bardzo serdecznie";
	delme.UsunZnapisu(10, 7);
	std::cout << delme << std::endl;

	Napis zepsuj = "siemano";
	zepsuj.UsunZnapisu(5, 289);
	std::cout << zepsuj << std::endl;

	Napis test = "To jest case testowy";
	std::cout << test.ZwrocPodnapis(19, 13);

	Napis znajdz = "siemcasemano", s = "em";
	if (znajdz.SprawdzCzyIstnieje(s))
		std::cout << "\nNapis znaleziono na pozycji: " << znajdz.ZnajdzWnapisie(s);
	else std::cout << "\nNie isnieje w napisie\n";

#endif
	return 0;
}


