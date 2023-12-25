#include <iostream>
#include "Const.h"

#ifndef _WALLET
#define _WALLET

using namespace std;
// объявление параметров валют
extern const char* allCurrency[];
extern const double allRate[];

// НЕ ПОЛУЧАЕТСЯ ОБЪЯВИТЬ 
//extern const int currencyCount = 4;

int currencyType(const char* type);

class Сurrency {
	int Type = 0;
	double Value = 0;

public:
	Сurrency() {};

	Сurrency(double value, const char* type);

	void changeCurrency(const char* type);

	void print();

	int getType();

	double getValue();

	// оператор добавления
	Сurrency& operator +=(const Сurrency& r);

	// операция сложения
	Сurrency operator +(const Сurrency& r) const;

	// оператор отрицания
	Сurrency operator -() const;

	// оператор уменьшения
	Сurrency& operator -=(const Сurrency& r);

	// оператор вычетания
	Сurrency operator -(const Сurrency& r) const;
};


class Wallet {
	Сurrency myCurrency[/*currencyCount*/ 4 ];

public:
	Wallet();

	void print();

	void add(Сurrency X);

	void add(double value, const char* type);

	void remove(Сurrency X);

	void remove(double value, const char* type);

	double total(int type = 0);

	double total(const char* type);
};


#endif