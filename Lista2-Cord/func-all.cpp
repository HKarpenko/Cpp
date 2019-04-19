#include <iostream>
#include <cmath>
#include <iomanip>
#include <classes.h>

using namespace std;

class Point;
class Segment;
class Triangle;

void Point::rotating(double grad, Point O) {
    int new_x;
    new_x = O.cordx() + (x - O.cordx()) * round(cos(grad*M_PI/180)*100)/100 - (O.cordy() - y) * round(sin(grad*M_PI/180)*100)/100;
    y = O.cordy() + (y - O.cordy()) * round(cos(grad*M_PI/180)*100)/100 + (x - O.cordx()) * round(sin(grad*M_PI/180)*100)/100;
    x=new_x;
}

void Segment::moving(double xx,double yy) {
    P1.x+=xx;
    P1.y+=yy;
    P2.x+=xx;
    P2.y+=yy;
}

void Segment::rotating(double grad, Point O) {
    int new_x;
    new_x = O.cordx() + (P1.x - O.cordx()) * round(cos(grad*M_PI/180)*100)/100 - (O.cordy() - P1.y) * round(sin(grad*M_PI/180)*100)/100;
    P1.y = O.cordy() + (P1.y - O.cordy()) * round(cos(grad*M_PI/180)*100)/100 + (P1.x - O.cordx()) * round(sin(grad*M_PI/180)*100)/100;
    P1.x=new_x;
    new_x = O.cordx() + (P2.x - O.cordx()) * round(cos(grad*M_PI/180)*100)/100 - (O.cordy() - P2.y) * round(sin(grad*M_PI/180)*100)/100;
    P2.y = O.cordy() + (P2.y - O.cordy()) * round(cos(grad*M_PI/180)*100)/100 + (P2.x - O.cordx()) * round(sin(grad*M_PI/180)*100)/100;
    P2.x=new_x;
}

void Triangle::moving(double xx,double yy) {
    Pn1.x+=xx;
    Pn1.y+=yy;
    Pn2.x+=xx;
    Pn2.y+=yy;
    Pn3.x+=xx;
    Pn3.y+=yy;
}

void Triangle::rotating(double grad, Point O) {
    int new_x;
    new_x = O.cordx() + (Pn1.x - O.cordx()) * round(cos(grad*M_PI/180)*100)/100 - (O.cordy() - Pn1.y) * round(sin(grad*M_PI/180)*100)/100;
    Pn1.y = O.cordy() + (Pn1.y - O.cordy()) * round(cos(grad*M_PI/180)*100)/100 + (Pn1.x - O.cordx()) * round(sin(grad*M_PI/180)*100)/100;
    Pn1.x=new_x;
    new_x = O.cordx() + (Pn2.x - O.cordx()) * round(cos(grad*M_PI/180)*100)/100 - (O.cordy() - Pn2.y) * round(sin(grad*M_PI/180)*100)/100;
    Pn2.y = O.cordy() + (Pn2.y - O.cordy()) * round(cos(grad*M_PI/180)*100)/100 + (Pn2.x - O.cordx()) * round(sin(grad*M_PI/180)*100)/100;
    Pn2.x=new_x;
    new_x = O.cordx() + (Pn3.x - O.cordx()) * round(cos(grad*M_PI/180)*100)/100 - (O.cordy() - Pn3.y) * round(sin(grad*M_PI/180)*100)/100;
    Pn3.y = O.cordy() + (Pn3.y - O.cordy()) * round(cos(grad*M_PI/180)*100)/100 + (Pn3.x - O.cordx()) * round(sin(grad*M_PI/180)*100)/100;
    Pn3.x=new_x;
}

Point Triangle::middle() {
    Segment a(Pn1,Pn2);
    Segment b(Pn2,Pn3);
    Segment m1(Pn1,b.midpoint());
    Segment m2(Pn3,a.midpoint());
    return cross(m1,m2);
}

double dist(Point &p1, Point &p2) {
    return sqrt(pow(p1.cordx()-p2.cordx(),2)+pow(p1.cordy()-p2.cordy(),2));
}

bool parall(Segment &s1, Segment &s2) {
    return (s1.get_end().cordx()-s1.get_start().cordx())*(s2.get_end().cordx()-s2.get_start().cordx()) + (s1.get_end().cordy()-s1.get_start().cordy())*(s2.get_end().cordy()-s2.get_start().cordy())==1;
}

bool perpend(Segment &s1, Segment &s2) {
    return abs((s1.get_end().cordx()-s1.get_start().cordx())*(s2.get_end().cordx()-s2.get_start().cordx()) + (s1.get_end().cordy()-s1.get_start().cordy())*(s2.get_end().cordy()-s2.get_start().cordy()))<=0.0001;
}

Point cross(Segment &s1, Segment &s2){ try{
    if (parall(s1,s2))
        throw invalid_argument("nie ma przeciecia");
    double x1=s1.get_start().cordx(), x2=s1.get_end().cordx(), x3=s2.get_start().cordx(), x4=s2.get_end().cordx();
    double y1=s1.get_start().cordy(), y2=s1.get_end().cordy(), y3=s2.get_start().cordy(), y4=s2.get_end().cordy();
    if (x2 < x1)
        swap(x1,x2);
    if (x4 < x3)
        swap(x4,x3);
    if (x2<x3 || x4<x1)
        throw invalid_argument("nie ma przeciecia");
    if(x1==x2==x3==x4)
        if ((max(y1, y2) < min(y3, y4)) ||
                (min(y1, y2) > max(y3, y4)))
                throw invalid_argument("nie ma przeciecia");
        else {
            Point pnt(x1,y1);
            if (y1 <= y3) {
                Point newp(x1,y3);
                pnt=newp;
            }
            return pnt;
        }
    if (x1==x2) {
        double k2 = (y3-y4)/(x3-x4);
        double b2 = y3-k2*x3;
        double y = k2 * x1 + b2;
        if (!(x3 <= x1 && x4 >= x1 && min(y1, y2) <= y &&
                max(y1, y2) >= y))
            throw invalid_argument("nie ma przeciecia");
        else {
            Point pnt(x1,y);
            return pnt;
        }
    }
    else if (x3==x4) {
        double k1 = (y1-y2)/(x1-x2);
        double b2 = y1-k1*x1;
        double y = k1 * x3 + b2;
        if (!(x1 <= x3 && x2 >= x3 && min(y3, y4) <= y &&
                max(y3, y4) >= y))
            throw invalid_argument("nie ma przeciecia");
        else {
            Point pnt(x3,y);
            return pnt;
        }
    }
    else {
        double k1 = (y1-y2)/(x1-x2);
        double k2 = (y3-y4)/(x3-x4);
        double b1 = y1-k1*x1;
        double b2 = y3-k2*x3;
        double X = (b2-b1)/(k1-k2);
        if ((X < max(x1, x3)) || (X > min(x2, x4)))
            throw invalid_argument("nie ma przeciecia");
        else {
            Point pnt(X,k1*X+b1);
            return pnt;
        }
    }
    }
    catch(invalid_argument &ia)
    {
        clog << ia.what() << endl;
    }
    return Point(-0.00015,0.00015);
}

bool tri_com_section(Triangle &tri1, Triangle &tri2) {
    Segment a1(tri1.get_cord1(),tri1.get_cord2());
    Segment b1(tri1.get_cord2(),tri1.get_cord3());
    Segment c1(tri1.get_cord3(),tri1.get_cord1());
    Segment a2(tri2.get_cord1(),tri2.get_cord2());
    Segment b2(tri2.get_cord2(),tri2.get_cord3());
    Segment c2(tri2.get_cord3(),tri2.get_cord1());
    if (cross(a1,a2).cordx()==-0.00015 && cross(a1,b2).cordx()==-0.00015 && cross(a1,c2).cordx()==-0.00015
        && cross(b1,a2).cordx()==-0.00015 && cross(b1,b2).cordx()==-0.00015 && cross(b1,c2).cordx()==-0.00015
        && cross(c1,a2).cordx()==-0.00015 && cross(c1,b2).cordx()==-0.00015 && cross(c1,c2).cordx()==-0.00015)
            return false;
    return true;
}

bool tri_in_tri(Triangle &tri1, Triangle &tri2) {
    double min1_x=min(tri1.get_cord1().cordx(),min(tri1.get_cord2().cordx(),tri1.get_cord3().cordx())), max1_x=max(tri1.get_cord1().cordx(),max(tri1.get_cord2().cordx(),tri1.get_cord3().cordx()));
    double min1_y=min(tri1.get_cord1().cordy(),min(tri1.get_cord2().cordy(),tri1.get_cord3().cordy())), max1_y=max(tri1.get_cord1().cordy(),max(tri1.get_cord2().cordy(),tri1.get_cord3().cordy()));
    double min2_x=min(tri2.get_cord1().cordx(),min(tri2.get_cord2().cordx(),tri2.get_cord3().cordx())), max2_x=max(tri2.get_cord1().cordx(),max(tri2.get_cord2().cordx(),tri2.get_cord3().cordx()));
    double min2_y=min(tri2.get_cord1().cordy(),min(tri2.get_cord2().cordy(),tri2.get_cord3().cordy())), max2_y=max(tri2.get_cord1().cordy(),max(tri2.get_cord2().cordy(),tri2.get_cord3().cordy()));

    if (tri_com_section(tri1,tri2) && ((min1_x<min2_x && max2_x<max1_x && min1_y<min2_y && max2_y<max1_y) || (min2_x<min1_x && max1_x<max2_x && min2_y<min1_y && max1_y<max2_y)) )
            return true;
    return false;
}
