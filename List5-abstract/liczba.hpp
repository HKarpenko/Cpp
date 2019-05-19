#ifndef CLASS_LICZBA
#define CLASS_LICZBA
#include "wyrazy.hpp"

class Liczba : public Wyrazenie {
private:
    double znacz;
public:
    Liczba(double z);
    const int prio() override;
    double oblicz() override;
    std::string opis() override;
};

#endif // CLASS_LICZBA
