#include <iostream>
#include <initializer_list>
#include <E:\Программирование\универ\Lista3\class.hpp>

using namespace std;

int main()
{
    string com="";
    FIFO k1(2);
    FIFO k2();
    FIFO k3 {"el1","el2","el3"};
    FIFO k4(k3);
    FIFO k5(move(FIFO {"e","l"}));
    cout << "Polecenia:\n\tWstawienie: paste;\n\tUsuniecie: delete;\n\tIlosc elementow: count;\n\tPojemnosc kolejki: size;\n\tWypisanie kolejki: all,\n\tKoniec programu: stop.\n";
    while(1){
        cout << "Wpisz polecenie:\n";
        cin >> com;
        if(com=="paste")
            if(k1.rozmiar()!=k1.get_pom()){
            cin >> com;
            k1.wloz(com);
            }
            else
                cout << "FIFO overflow" << endl;
        else if(com=="delete")
            cout << k1.wyciagnij() << endl;
        else if(com=="count")
            cout << k1.rozmiar() << endl;
        else if(com=="size")
            cout << k1.get_pom() << endl;
        else if(com=="all"){
            if(k1.get_pom()!=0 && k1.rozmiar()!=0)
                k1.wypisz();
        }
        else if(com=="stop")
            break;
        else
            cout << "Podane nieprawiedlowe polecenie" << endl;
    }
    return 0;
}
