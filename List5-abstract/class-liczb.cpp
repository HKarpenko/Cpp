#include <iostream>
#include "wyrazy.hpp"
#include "liczba.hpp"

using namespace std;

Liczba::Liczba(double z){znacz=z;}

const int Liczba::prio(){return 0;}

double Liczba::oblicz(){
    return znacz;
}

std::string Liczba::opis(){
    return to_string(znacz);
}
