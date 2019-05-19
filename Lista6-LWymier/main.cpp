#include <iostream>
#include <cmath>
#include "Wyjatki.hpp"
#include "Obliczenia.hpp"

int main()
{
    using namespace std;
    Obliczenia::Wymierna w1(5,-10);
    Obliczenia::Wymierna w2(7,8);
    Obliczenia::Wymierna w3(-w2);
    int a=w2;
    double b=w1;
    cout << "Przypiszmy " << w2 << " do zmiennej int: " << a << endl;
    cout << "A " << w1 << " zmiennej double: " << b << endl;
    cout << "Ulamek: " << w3 << "\tjego licznik: " << w3.getLicz() << "\tjego mianownik: " << w3.getMian() << endl;
    cout << w1 << " + " << w3 << " = " << w1+w3 << endl;
    cout << w2 << " - " << w3 << " = " << w2-w3 << endl;
    cout << w3 << " * " << w1 << " = " << w3*w1 << endl;
    cout << w1 << " / " << w2 << " = " << w1/w2 << endl;
    cout << w2 << " a odwrotny ulamek " << !w2 << endl;
    Obliczenia::Wymierna w4(0,1);
    try{
        cout << w4 << " a odwrotny?\n" << !w4;
    }
    catch(Wyjatek_wymierny &except){
        cerr << except.getErr() << endl;
    }
    Obliczenia::Wymierna w5(50000,3);
    Obliczenia::Wymierna w6(50000,3);
    try{
        cout << "Co jak " << w5 << " * " << w6 << " ?\n";
        cout << w5*w6;
    }
    catch(Wyjatek_wymierny &except){
        cerr << except.getErr() << endl;
    }
    return 0;
}
