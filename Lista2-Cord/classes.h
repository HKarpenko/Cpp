#ifndef CLASSES_H
#define CLASSES_H

class Point;
class Segment;
class Triangle;
double dist(Point &p1, Point &p2);
Point cross(Segment &s1, Segment &s2);

class Point {
    friend Segment;
    friend Triangle;
    private:
        double x;
        double y;
    public:
        Point() {
        }
        Point(double cx, double cy) {
            x=cx;
            y=cy;
        }
        Point(const Point &obj) {
            this->x=obj.cordx();
            this->y=obj.cordy();
        }
        Point & operator=(const Point &obj) {
            if (this != &obj) {
                this->x=obj.cordx();
                this->y=obj.cordy();
			}
            return *this;
        }
        double cordx() const {
            return x;
        }
        double cordy() const {
            return y;
        }
        void moving(double xx,double yy) {
            x+=xx;
            y+=yy;
        }
        void rotating(double grad, Point O);
};

class Segment {
private:
    Point P1;
    Point P2;
public:
    Segment(Point punk1, Point punk2):P1(punk1),P2(punk2)
    {
        if (punk1.cordx()==punk2.cordx() && punk1.cordy()==punk2.cordy())
            throw std::invalid_argument("nie mozna utworzyc odcinka o dlugosci 0");
    }
    Segment(const Segment &obj) {
        this->P1=obj.P1;
        this->P2=obj.P2;
    }
    Segment & operator=(const Segment &obj) {
        if (this != &obj) {
            this->P1=obj.get_start();
            this->P2=obj.get_end();
        }
        return *this;
    }
    Point get_start() const{
        return P1;
    }
    Point get_end() const{
        return P2;
    }
    double length()
    {
        return dist(P1,P2);
    }
    Point midpoint()
    {
        Point srod((P2.x+P1.x)/2,(P2.y+P1.y)/2);
        return srod;
    }
    bool belong(Point &p)
    {
        if ((P1.x<=p.x && p.x<=P2.x) || (P2.x<=p.x && p.x<=P1.x))
            if((p.x-P1.x)*(P2.x-P1.x) + (p.y-P1.y)*(P2.y-P1.y)==0.0)
                return true;
        return false;
    }
    void moving(double xx,double yy);

    void rotating(double grad, Point O);

};

class Triangle {
private:
    Point Pn1;
    Point Pn2;
    Point Pn3;
    double Oneside(Point &P1, Point &P2, Point &P3, Point &P4) {
        return ((P3.x-P1.x)*(P2.y-P1.y)-(P3.y-P1.y)*(P2.x-P1.x))*((P4.x-P1.x)*(P2.y-P1.y)-(P4.y-P1.y)*(P2.x-P1.x)) >= 0;
    }
public:
    Triangle(Point punk1, Point punk2, Point punk3):Pn1(punk1),Pn2(punk2),Pn3(punk3)
    {
        Segment a(punk1,punk2);
        Segment b(punk2,punk3);
        Segment c(punk3,punk1);
        if (a.length()+b.length()<=c.length()||a.length()+c.length()<=b.length()||c.length()+b.length()<=a.length())
            throw std::invalid_argument("nie mozna utworzyc trojkata o podanych wspolrzednych");
    }
    Triangle(const Triangle &obj) {
        this->Pn1=obj.Pn1;
        this->Pn2=obj.Pn2;
        this->Pn3=obj.Pn3;
    }
    Triangle & operator=(const Triangle &obj) {
        if (this != &obj) {
            this->Pn1=obj.Pn1;
            this->Pn2=obj.Pn2;
            this->Pn3=obj.Pn3;
        }
        return *this;
    }
    Point get_cord1() const{
        return Pn1;
    }
    Point get_cord2() const{
        return Pn2;
    }
    Point get_cord3() const{
        return Pn3;
    }
    void moving(double xx,double yy);

    void rotating(double grad, Point O);
    double perimeter()
    {
        return dist(Pn1,Pn2)+dist(Pn2,Pn3)+dist(Pn1,Pn3);
    }
    double area()
    {
        double a=dist(Pn1,Pn2), b=dist(Pn2,Pn3), c=dist(Pn1,Pn3);
        double p=this->perimeter()/2;
        return sqrt(p*(p-a)*(p-b)*(p-c));
    }
    bool Epoint(Point &pnt) {
        return Oneside(Pn1,Pn2,Pn3,pnt) && Oneside(Pn2,Pn3,Pn1,pnt) && Oneside(Pn3,Pn1,Pn2,pnt);
    }
    Point middle();

};

#endif
