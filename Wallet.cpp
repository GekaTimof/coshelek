#include <iostream>
#include "Wallet.h"
#include "Const.h"



using namespace std;
// ïàğàìåòğû âàëşò
const char* allCurrency[] = { "Ruble", "Dollar", "Euro", "Pound" };
const double allRate[] = { 1.0, 0.011149, 0.010161, 0.008737 };
// îáùåå êîë-âî âàëşò
const int currencyCount = (sizeof(allRate) / sizeof(*allRate));


int currencyType(const char* type) {
	for (int i = 0; i < currencyCount; i++) {
		if (type == allCurrency[i]) {
			return i;
		}
	}
	cout << "err - try to create unreal Ñurrency";
	return -1;
}

Ñurrency::Ñurrency(double value, const char* type){
		Value = value;
		Type = currencyType(type);
}

int Ñurrency::getType() {
	return Type;
}

double Ñurrency::getValue() {
	return Value;
}


void Ñurrency::changeCurrency(const char* type) {
	int typeTest = currencyType(type);

	if (typeTest > -1) {
		Value = Value / allRate[Type] * allRate[typeTest];
		Type = typeTest;
	}
}


void Ñurrency::print() {
	cout << Value << " - " << allCurrency[Type] << '\n';
}

// îïåğàöèÿ äîáàâëåíèÿ
Ñurrency& Ñurrency::operator +=(const Ñurrency& c) {
	Value = (Value + c.Value);
	return *this;
};

// îïåğàöèÿ ñëîæåíèÿ
Ñurrency Ñurrency::operator +(const Ñurrency& c) const {
	Ñurrency res(*this);
	return (res += c);
}

// îïåğàòîğ îòğèöàíèÿ
Ñurrency Ñurrency::operator -() const {
	Ñurrency res(-Value, allCurrency[Type]);
	return res;
}

// îïåğàòîğ óìåíüøåíèÿ
Ñurrency& Ñurrency::operator -=(const Ñurrency& c) {
	return (*this += (-c));
}

// îïåğàòîğ âû÷åòàíèÿ
Ñurrency Ñurrency::operator -(const Ñurrency& c) const {
	Ñurrency res(*this);
	return (res -= c);
}





Wallet::Wallet() {
	for (int i = 0; i < currencyCount; i++) {
		Ñurrency nemCurrency(0, allCurrency[i]);
		myCurrency[i] = nemCurrency;
	}
}

void Wallet::print() {
	for (int i = 0; i < currencyCount; i++) {
		myCurrency[i].print();
	}
}

void Wallet::add(Ñurrency X) {
	if (X.getType() >= 0) {
		myCurrency[X.getType()] += X;
	}
	else {
		cout << "err - Ñurrency not exist \n";
	}
}

void Wallet::add(double value, const char* type) {
	Ñurrency currency(value, type);
	this->add(currency);
}

void Wallet::remove(Ñurrency X) {
	if (X.getType() >= 0) {
		myCurrency[X.getType()] -= X;
	}
	else {
		cout << "err - Ñurrency not exist \n";
	}
}

void Wallet::remove(double value, const char* type) {
	Ñurrency currency(value, type);
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