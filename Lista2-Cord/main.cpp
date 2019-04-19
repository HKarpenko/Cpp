#include <iostream>
#include <cmath>
#include <iomanip>
#include <classes.h>

using namespace std;

class Point;
class Segment;
class Triangle;
double dist(Point &p1, Point &p2);
Point cross(Segment &s1, Segment &s2);
bool parall(Segment &s1, Segment &s2);
bool perpend(Segment &s1, Segment &s2);
bool tri_com_section(Triangle &tri1, Triangle &tri2);
bool tri_in_tri(Triangle &tri1, Triangle &tri2);


int main()
{
    cout << "Point demonstration: " << endl;
    Point pocz(0.0,0.0);
    cout << "Poczatkowe znaczenie stworzonego punkta: " << endl;
    cout << "x: " << pocz.cordx() << endl << "y: " << pocz.cordy() << endl;
    cout << "Przesuwamy nasz punkt o wektor v(1.0,1.0): " << endl;
    pocz.moving(1.0,1.0);
    cout << "x: " << pocz.cordx() << endl << "y: " << pocz.cordy() << endl;
    cout << "I obracamy wokol punkta (1.0,0.0) na 90 stopni: " << endl;
    pocz.rotating(90,Point(0.0,1.0));
    cout << "x: " << pocz.cordx() << endl << "y: " << pocz.cordy() << endl << endl;

    try{
    cout << "Segment demonstration: " << endl;
    cout << "Stworzymy dwa odcinka o kordynatach: " << endl;
    Segment od1(Point(1.0,1.0),Point(2.0,1.0));
    Segment od2(Point(0.0,0.0),Point(2.0,1.0));
    cout << "A1: (" << od1.get_start().cordx() << "," << od1.get_start().cordy() << ") ";
    cout << "B1: (" << od1.get_end().cordx() << "," << od1.get_end().cordy() << ")" << endl;
    cout << "A2: (" << od2.get_start().cordx() << "," << od2.get_start().cordy() << ") ";
    cout << "B2: (" << od2.get_end().cordx() << "," << od2.get_end().cordy() << ")" << endl;
    cout << "Dlugosc pierwszego odcinka: " << od1.length() << endl;
    cout << "Dlugosc drugiego odcinka: " << od2.length() << endl;
    cout << "Srodek drugiego odcinka: (" << od2.midpoint().cordx() << "," << od2.midpoint().cordy() << ")" << endl;
    cout << "Czy odcinki sa rownolegle? " << parall(od1, od2) << " - nie" << endl << "A prostopadle? " << perpend(od1, od2) << " - nie" << endl;
    Point new_pn(1.0,1.2);
    cout << "Czy nalezy punkt (1.0,1.2) do pierwszego odcinka? " << od1.belong(new_pn) << " - czyli, tak" << endl;
    cout << "Teraz przesunmy drugi odcinek o wektor v(2.0,0.0): " << endl;
    od2.moving(2.0,0.0);
    cout << "A2: (" << od2.get_start().cordx() << "," << od2.get_start().cordy() << ") ";
    cout << "B2: (" << od2.get_end().cordx() << "," << od2.get_end().cordy() << ")" << endl;
    cout << "I obrucmy wokol punkta (0.0,0.0) na 30 stopni: " << endl;
    od2.rotating(30,Point(0.0,0.0));
    cout << "A2: (" << od2.get_start().cordx() << "," << od2.get_start().cordy() << ") ";
    cout << "B2: (" << od2.get_end().cordx() << "," << od2.get_end().cordy() << ")" << endl;
    cout << "Punkt przeciecia dwoch odcinkow: (" << cross(od1,od2).cordx() << "," << cross(od1,od2).cordy() << ")" << endl << endl;
    }
    catch(invalid_argument &ia)
    {
        clog << ia.what() << endl;
    }

    try {
    cout << "Triangle demonstration: " << endl;
    cout << "Tworzymy dwa trojkaty o kordynatach: " << endl;
    Triangle tri90p(Point(0.0,0.0),Point(100.0,0.0),Point(0.0,100.0));
    Triangle tri90l(Point(1.0,1.0),Point(1.0,2.0),Point(2.0,1.0));
    cout << "A1: (" << tri90p.get_cord1().cordx() << "," << tri90p.get_cord1().cordy() << ") ";
    cout << "B1: (" << tri90p.get_cord2().cordx() << "," << tri90p.get_cord1().cordy() << ") ";
    cout << "C1: (" << tri90p.get_cord3().cordx() << "," << tri90p.get_cord3().cordy() << ") " << endl;
    cout << "A2: (" << tri90l.get_cord1().cordx() << "," << tri90l.get_cord1().cordy() << ") ";
    cout << "B2: (" << tri90l.get_cord2().cordx() << "," << tri90l.get_cord1().cordy() << ") ";
    cout << "C2: (" << tri90l.get_cord3().cordx() << "," << tri90l.get_cord3().cordy() << ") " << endl;
    cout << "Obwod pierwszego trojkata: " << tri90p.perimeter() << endl;
    cout << "A pole: " << tri90p.area() << endl;
    cout << "Srodek drugiego trojkata: (" << tri90l.middle().cordx() << "," << tri90l.middle().cordy() << ")" << endl;
    Point new_pn2(1.3,1.3);
    cout << "Czy nalezy punkt (1.3,1.3) do drugiego trojkata? " << tri90l.Epoint(new_pn2) << " - czyli, tak" << endl;
    cout << "Czy sa trojkaty rozlaczne? " << tri_com_section(tri90l,tri90p) << " - czyli, tak" << endl;
    cout << "Czy jeden trojkat zawarty w innym? " << tri_in_tri(tri90l,tri90p) << " - czyli, tak" << endl;
    }
    catch(logic_error &er)
    {
        clog << er.what() << endl;
    }
    return 0;
}
