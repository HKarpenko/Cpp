#ifndef CLASS_WYRAZY
#define CLASS_WYRAZY

class Wyrazenie {
public:
    virtual const int prio() = 0;
    virtual double oblicz() = 0;
    virtual std::string opis() = 0;
};

#endif // CLASS_WYRAZY
