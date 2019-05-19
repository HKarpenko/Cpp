#include <iostream>
#include "Wyjatki.hpp"

const char* Dzielenie_przez_0::getErr() { return "Blad! Mianownik nie mozy byc 0"; }

const char* Przekroczenie_zakresu::getErr(){ return "Blad! Zakres int zostal przekroczony"; }
