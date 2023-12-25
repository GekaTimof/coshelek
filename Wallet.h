#include <iostream>
#include "Const.h"

#ifndef _WALLET
#define _WALLET

using namespace std;
// ���������� ���������� �����
extern const char* allCurrency[];
extern const double allRate[];

// �� ���������� �������� 
//extern const int currencyCount = 4;

int currencyType(const char* type);

class �urrency {
	int Type = 0;
	double Value = 0;

public:
	�urrency() {};

	�urrency(double value, const char* type);

	void changeCurrency(const char* type);

	void print();

	int getType();

	double getValue();

	// �������� ����������
	�urrency& operator +=(const �urrency& r);

	// �������� ��������
	�urrency operator +(const �urrency& r) const;

	// �������� ���������
	�urrency operator -() const;

	// �������� ����������
	�urrency& operator -=(const �urrency& r);

	// �������� ���������
	�urrency operator -(const �urrency& r) const;
};


class Wallet {
	�urrency myCurrency[/*currencyCount*/ 4 ];

public:
	Wallet();

	void print();

	void add(�urrency X);

	void add(double value, const char* type);

	void remove(�urrency X);

	void remove(double value, const char* type);

	double total(int type = 0);

	double total(const char* type);
};


#endif