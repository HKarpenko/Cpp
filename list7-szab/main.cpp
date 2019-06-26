#include <iostream>
#include <cstring>

#include "treit.hpp"
#include "bst.hpp"

using namespace std;
using namespace struktury;

int main()
{
    Bst<int> drzewo {5,3,10};
    cout << drzewo.fnd(10) << endl;
    cout << drzewo << endl;
    drzewo.dlt(5);
    try{
        cout << drzewo.fnd(5) << endl;
    }
    catch(logic_error &er){ clog << er.what() << endl; }
    drzewo.ins(3);
    cout << drzewo << endl;
    const char* str="Hello";
    cout << strlen(str) << endl;
    Bst<const char*> bstr {"aa","n","zzz","hello","world","m"};
    cout << bstr << endl;
    Bst<int> test;
    cout << "\n\n";
    string com="";
    int el=0;
    cout << "Polecenia:\n\tWstawienie: paste;\n\tUsuniecie: delete;\n\tZnalesc element: lookup;\n\tWypisanie drzewa: all,\n\tKoniec programu: stop.\n";
    while(1){
        cout << "Wpisz polecenie:\n";
        cin >> com;
        if(com=="paste"){
            cout << "Wpisz element: ";
            cin >> el;
            test.ins(el);
            cout << "Drzewo: " << test << endl;
        }
        else if(com=="delete"){
            cout << "Wpisz element: ";
            cin >> el;
            test.dlt(el);
            cout << "Drzewo: " << test << endl;
        }
        else if(com=="lookup"){
            try{
                cout << "Wpisz element: ";
                cin >> el;
                test.fnd(el);
                cout << el << " znaleziono!" << endl;
            }
            catch(logic_error &er){ clog << er.what() << endl; }
        }
        else if(com=="all")
            cout << "Drzewo: " << test << endl;
        else if(com=="stop")
            break;
        else
            cout << "Podane nieprawiedlowe polecenie" << endl;
    }
    return 0;
}
