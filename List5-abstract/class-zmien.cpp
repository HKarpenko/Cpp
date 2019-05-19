#include <iostream>
#include <map>
#include "wyrazy.hpp"
#include "zmien.hpp"

Zmienna::Zmienna(std::string name){sym=name;}

const int Zmienna::prio(){return 0;}

double Zmienna::oblicz(){
    return z_list.at(sym);
}

std::string Zmienna::opis(){
    return sym;
}

void Zmienna::ustal(std::string kl,double wart){
    Zmienna::z_list.map::erase(kl);
    Zmienna::z_list.map::insert(std::pair<std::string,double>(kl,wart));
}

std::map<std::string,double> Zmienna::z_list;

