#include <iostream>

#ifndef _COSHELEK
#define _COSHELEK

using namespace std;
class �urrency {
	int Type = 0;
	double Value = 0;

	int currencyType(const char* type);

public:
	�urrency() {};

	�urrency(double value);

	void changeCurrency(const char* type);

	void print();

};

class Coshelek {
	�urrency coshelek[4] = { 0, 0, 0, 0 };

public:
	void print();
};


#endif