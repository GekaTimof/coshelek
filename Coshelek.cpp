#include <iostream>
#include<string>
#include "Coshelek.h"
#include "Const.h"

using namespace std;
�urrency::�urrency(double value) {
		Value = value;
}


int �urrency::currencyType(const char* type) {
	for (int i = 0; i < currencyCount; i++) {
		if (allCurrency[i] == type) {
			return i;
		}
	}
	cout << "����� ������ ���";
	return -1;
}


void �urrency::changeCurrency(const char* type) {
	int typeTest = currencyType(type);

	if (typeTest > -1) {
		Value = Value / allRate[Type] * allRate[typeTest];
		Type = typeTest;
	}
}


void �urrency::print() {
	cout << Value << " - " << allCurrency[Type];
}

void Coshelek::print() {
	for (int i = 0; i < currencyCount; i++) {
		coshelek[i].print();
		cout << "\n";
	}
}