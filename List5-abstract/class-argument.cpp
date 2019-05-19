#include <iostream>
#include <math.h>
#include "argument.hpp"
#include "wyrazy.hpp"

Sin::Sin(Wyrazenie *o) {opd=o;}
const int Sin::prio() {return 0;}
double Sin::oblicz() {
    return sin(opd->oblicz());
}
std::string Sin::opis(){
    return "syn("+opd->opis()+")";
}


Cos::Cos(Wyrazenie *o){opd=o;}
const int Cos::prio(){return 0;}
double Cos::oblicz(){
    return cos(opd->oblicz());
}
std::string Cos::opis(){
    return "cos("+opd->opis()+")";
}


Exp::Exp(Wyrazenie *o){opd=o;}
const int Exp::prio(){return 0;}
double Exp::oblicz(){
    return exp(opd->oblicz());
}
std::string Exp::opis(){
    return "exp("+opd->opis()+")";
}


Ln::Ln(Wyrazenie *o){opd=o;}
const int Ln::prio(){return 0;}
double Ln::oblicz(){
    return log10(opd->oblicz());
}
std::string Ln::opis(){
    return "ln("+opd->opis()+")";
}


Bezwzgl::Bezwzgl(Wyrazenie *o){opd=o;}
const int Bezwzgl::prio(){return 0;}
double Bezwzgl::oblicz(){
    return abs(opd->oblicz());
}
std::string Bezwzgl::opis(){
    return "|"+opd->opis()+"|";
}


Przeciw::Przeciw(Wyrazenie *o){opd=o;}
const int Przeciw::prio(){return 0;}
double Przeciw::oblicz(){
    return -1*opd->oblicz();
}
std::string Przeciw::opis(){
    return "-("+opd->opis()+")";
}

Odwrot::Odwrot(Wyrazenie *o){opd=o;}
const int Odwrot::prio(){return 0;}
double Odwrot::oblicz(){
    return 1/opd->oblicz();
}
std::string Odwrot::opis(){
    return "1/("+opd->opis()+")";
}


Dodaj::Dodaj(Wyrazenie *o1,Wyrazenie *o2){opd1=o1;opd2=o2;}
const int Dodaj::prio(){return 1;}
double Dodaj::oblicz(){
    return opd1->oblicz()+opd2->oblicz();
}
std::string Dodaj::opis(){
    return opd1->opis()+"+"+opd2->opis();
}


Odejmij::Odejmij(Wyrazenie *o1,Wyrazenie *o2){opd1=o1;opd2=o2;}
const int Odejmij::prio(){return 1;}
double Odejmij::oblicz(){
    return opd1->oblicz()-opd2->oblicz();
}
std::string Odejmij::opis(){
    if(opd2->prio()==1)
        return opd1->opis()+"-("+opd2->opis()+")";
    return opd1->opis()+"-"+opd2->opis();
}


Mnoz::Mnoz(Wyrazenie *o1,Wyrazenie *o2){opd1=o1;opd2=o2;}
const int Mnoz::prio(){return 2;}
double Mnoz::oblicz(){
    return opd1->oblicz()*opd2->oblicz();
}
std::string Mnoz::opis(){
    if(opd1->prio()==1||opd1->prio()==2)
        if(opd2->prio()==1||opd2->prio()==2)
            return "("+opd1->opis()+")*("+opd2->opis()+")";
        else
            return "("+opd1->opis()+")*"+opd2->opis();
    else if(opd2->prio()==1||opd2->prio()==2)
        return opd1->opis()+"*("+opd2->opis()+")";
    return opd1->opis()+"*"+opd2->opis();
}


Dziel::Dziel(Wyrazenie *o1,Wyrazenie *o2){
    opd1=o1;opd2=o2;
    if(&o2->oblicz==0)
        throw std::invalid_argument("Division by zero");
    opd1=o1;opd2=o2;
}
const int Dziel::prio(){return 2;}
double Dziel::oblicz(){
    return opd1->oblicz()/opd2->oblicz();
}
std::string Dziel::opis(){
    if(opd1->prio()==1||opd1->prio()==2)
        if(opd2->prio()==1||opd2->prio()==2)
            return "("+opd1->opis()+")/("+opd2->opis()+")";
        else
            return "("+opd1->opis()+")/"+opd2->opis();
    else if(opd2->prio()==1||opd2->prio()==2)
        return opd1->opis()+"/("+opd2->opis()+")";
    return opd1->opis()+"/"+opd2->opis();
}


Modulo::Modulo(Wyrazenie *o1,Wyrazenie *o2){
    if(&o2->oblicz==0)
        throw std::invalid_argument("Division by zero");
    opd1=o1;opd2=o2;
}
const int Modulo::prio(){return 2;}
double Modulo::oblicz(){
    return (int)floor(opd1->oblicz())%(int)floor(opd2->oblicz());
}
std::string Modulo::opis(){
    if(opd1->prio()==1||opd1->prio()==2)
        if(opd2->prio()==1||opd2->prio()==2)
            return "("+opd1->opis()+")%("+opd2->opis()+")";
        else
            return "("+opd1->opis()+")%"+opd2->opis();
    else if(opd2->prio()==1||opd2->prio()==2)
        return opd1->opis()+"%("+opd2->opis()+")";
    return opd1->opis()+"%"+opd2->opis();
}


Logarytm::Logarytm(Wyrazenie *o1,Wyrazenie *o2){
    opd1=o1;opd2=o2;
}
const int Logarytm::prio(){return 0;}
double Logarytm::oblicz(){
    return log(opd1->oblicz())/log(opd2->oblicz());
}
std::string Logarytm::opis(){
    return "log("+opd1->opis()+","+opd2->opis()+")";
}


Potega::Potega(Wyrazenie *o1,Wyrazenie *o2){opd1=o1;opd2=o2;}
const int Potega::prio(){return 3;}
double Potega::oblicz(){
    return pow(opd1->oblicz(),opd2->oblicz());
}
std::string Potega::opis(){
    if(opd1->prio()>0&&opd1->prio()<3)
        if(opd2->prio()>0&&opd2->prio()<3)
            return "("+opd1->opis()+")^("+opd2->opis()+")";
        else
            return "("+opd1->opis()+")^"+opd2->opis();
    else if(opd2->prio()>0&&opd2->prio()<3)
        return opd1->opis()+"^("+opd2->opis()+")";
    return opd1->opis()+"^"+opd2->opis();
}
