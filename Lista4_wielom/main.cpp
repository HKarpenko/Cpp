#include <iostream>
#include <initializer_list>
#include <E:\Программирование\универ\Lista4\class.hpp>

using namespace std;

int main()
{
    double arr[2]={1.1,2.2};
    Wielomian wr1(1,arr);
    Wielomian wr2();
    Wielomian wr3(wr1);
    Wielomian wr4(move(wr3));
    int stop;
    Wielomian w2 {1.3,2.5,3.0};
    cout << "Podaj stopien wielomiana: ";
    cin >> stop;
    double *cos=new double[stop+1];
    Wielomian w1(stop,cos);
    cout << "Podaj wspolczynniki wielomiana: ";
    cin >> w1;
    cout << "Wielomian w1: " << w1;
    cout << "Wielomian w2: " << w2;
    cout << "Wielomian w2 po wspolczynnikam:  " << w2[2] << "  " << w2[1] << "  " << w2[0] << endl;
    cout << "Policzmy w1-w2 : " << w1-w2;
    cout << "I pomonozymy przez 2 : " << 2*(w1-w2);
    cout << "Teraz w1*w2 : " << w1*w2;
    cout << "Niech w2*=w1 : ";
    w2*=w1;
    cout << w2;
    cout << "Teraz policzmy w2 dla x=2 : " << w2(2) << endl;
    return 0;
}
