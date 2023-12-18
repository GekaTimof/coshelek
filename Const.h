#include <iostream>

#ifndef _CONST
#define _CONST

using namespace std;

const int currencyCount = 4;

const char* allCurrency[currencyCount] = { "Ruble", "Dollar", "Euro", "Pound" };
const double allRate[currencyCount] = { 1.0, 0.011149, 0.010161, 0.008737 };

#endif