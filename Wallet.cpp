#include <iostream>
#include "Wallet.h"
#include "Const.h"



using namespace std;
// ��������� �����
const char* allCurrency[] = { "Ruble", "Dollar", "Euro", "Pound" };
const double allRate[] = { 1.0, 0.011149, 0.010161, 0.008737 };
// ����� ���-�� �����
const int currencyCount = (sizeof(allRate) / sizeof(*allRate));


int currencyType(const char* type) {
	for (int i = 0; i < currencyCount; i++) {
		if (type == allCurrency[i]) {
			return i;
		}
	}
	cout << "err - try to create unreal �urrency";
	return -1;
}

�urrency::�urrency(double value, const char* type){
		Value = value;
		Type = currencyType(type);
}

int �urrency::getType() {
	return Type;
}

double �urrency::getValue() {
	return Value;
}


void �urrency::changeCurrency(const char* type) {
	int typeTest = currencyType(type);

	if (typeTest > -1) {
		Value = Value / allRate[Type] * allRate[typeTest];
		Type = typeTest;
	}
}


void �urrency::print() {
	cout << Value << " - " << allCurrency[Type] << '\n';
}

// �������� ����������
�urrency& �urrency::operator +=(const �urrency& c) {
	Value = (Value + c.Value);
	return *this;
};

// �������� ��������
�urrency �urrency::operator +(const �urrency& c) const {
	�urrency res(*this);
	return (res += c);
}

// �������� ���������
�urrency �urrency::operator -() const {
	�urrency res(-Value, allCurrency[Type]);
	return res;
}

// �������� ����������
�urrency& �urrency::operator -=(const �urrency& c) {
	return (*this += (-c));
}

// �������� ���������
�urrency �urrency::operator -(const �urrency& c) const {
	�urrency res(*this);
	return (res -= c);
}





Wallet::Wallet() {
	for (int i = 0; i < currencyCount; i++) {
		�urrency nemCurrency(0, allCurrency[i]);
		myCurrency[i] = nemCurrency;
	}
}

void Wallet::print() {
	for (int i = 0; i < currencyCount; i++) {
		myCurrency[i].print();
	}
}

void Wallet::add(�urrency X) {
	if (X.getType() >= 0) {
		myCurrency[X.getType()] += X;
	}
	else {
		cout << "err - �urrency not exist \n";
	}
}

void Wallet::add(double value, const char* type) {
	�urrency currency(value, type);
	this->add(currency);
}

void Wallet::remove(�urrency X) {
	if (X.getType() >= 0) {
		myCurrency[X.getType()] -= X;
	}
	else {
		cout << "err - �urrency not exist \n";
	}
}

void Wallet::remove(double value, const char* type) {
	�urrency currency(value, type);
	this->remove(currency);
}

double Wallet::total(int type) {
	double Total = 0;

	for (int i = 0; i < currencyCount; i++) {
		Total += myCurrency[i].getValue() / allRate[i];
	}

	for (int i = 0; i < currencyCount; i++) {
		if (type == i) {
			return Total * allRate[i];
		}
	}

}

double Wallet::total(const char* type) {
	double Total = total(currencyType(type));
	return Total;
}