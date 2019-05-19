#include <iostream>
#include <math.h>
#include <map>
#include "liczba.hpp"
#include "wyrazy.hpp"
#include "stala.hpp"
#include "zmien.hpp"
#include "argument.hpp"

using namespace std;

int main()
{
    cout.setf(ios::fixed);
    cout.precision(3);
    Zmienna::ustal("x",2.0);
    Wyrazenie *w = new Odejmij(new Pi(), new Dodaj(new Liczba(2),new Mnoz(new Zmienna("x"),new Liczba(7))));
    cout << w->opis() << " " << w->oblicz() << endl;
    Wyrazenie *w1 = new Dziel(new Mnoz(new Odejmij(new Zmienna("x"),new Liczba(1)),new Zmienna("x")),new Liczba(2));
    cout << w1->opis() << endl;
    Wyrazenie *w2 = new Dziel(new Dodaj(new Liczba(3),new Liczba(5)),new Dodaj(new Liczba(2),new Mnoz(new Zmienna("x"),new Liczba(7))));
    cout << w2->opis() << endl;
    Wyrazenie *w3 = new Odejmij(new Dodaj(new Liczba(2),new Mnoz(new Zmienna("x"),new Liczba(7))),new Dodaj(new Mnoz(new Zmienna("x"),new Liczba(3)),new Liczba(5)));
    cout << w3->opis() << endl;
    Wyrazenie *w4 = new Dziel(new Cos(new Mnoz(new Dodaj(new Zmienna("x"),new Liczba(1)),new Zmienna("x"))),new Potega(new E(),new Potega(new Zmienna("x"),new Liczba(2))));
    cout << w4->opis() << endl;
    for(double i=0;i<=1.0;i+=0.01){
        Zmienna::ustal("x",i);
        cout << "w1 x=" << i << " res: " << w1->oblicz() << endl;
        cout << "w2 x=" << i << " res: " << w2->oblicz() << endl;
        cout << "w3 x=" << i << " res: " << w3->oblicz() << endl;
        cout << "w4 x=" << i << " res: " << w4->oblicz() << endl;
    }
    return 0;
}
