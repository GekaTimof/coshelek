#include <iostream>
#include "Wallet.h"

using namespace std;
int main(void){
    setlocale(LC_ALL, "Russian");

    Сurrency currency(100, "Ruble");
    currency.print();
    currency.changeCurrency("Euro");
    currency.print();

    Wallet wallet;
    wallet.print();

    cout << "\n";

    wallet.add(currency + currency);
    wallet.add(100, "Ruble");
    wallet.print();

    cout << "\n";

    wallet.remove(currency);
    wallet.remove(35, "Ruble");
    wallet.print();

    cout << "\n";

    cout << wallet.total() << " - Ruble total \n";
    cout << wallet.total("Euro") << " - Euro total \n";


    return 0;
}

