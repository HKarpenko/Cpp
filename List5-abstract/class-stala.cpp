#include <iostream>
#include <math.h>
#include "wyrazy.hpp"
#include "stala.hpp"

using namespace std;

Pi::Pi(){}

const int Pi::prio(){return 0;}

double Pi::oblicz(){
        return M_PI;
}

std::string Pi::opis(){
        return "pi";
}

E::E(){}

const int E::prio(){return 0;}

double E::oblicz(){
        return M_E;
}

std::string E::opis(){
        return "e";
}

Fi::Fi(){}

const int Fi::prio(){return 0;}

double Fi::oblicz(){
    return (1 + sqrt(5)) / 2;
}
std::string Fi::opis(){
    return "fi";
}
