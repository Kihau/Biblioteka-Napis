////////////////////////////////////
//    LIBRARY BY Michal Haldas    //
////////////////////////////////////

/*
------------------------------------------
				TO DO:
	1. Zrobic wyjatki / pomijanie specjalych przypadkow
	2. Utworzyc przestrzen dla funkcji friend
-----------------------------------------
*/

#pragma once

#define _CRT_SECURE_NO_WARNINGS
#define OUTFILE true // gdy true - plik napis.cpp wlaczony 

#include <iostream>
#include <cmath>
#include <sstream>

#if OUTFILE

#include "NapisOutfile.h"
//class Napis;

#elif !OUTFILE

/*
----------------------
	TU KLASA INLINE
----------------------
*/

#endif
