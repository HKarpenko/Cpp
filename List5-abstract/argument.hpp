#ifndef CLASS_ARGUMENT
#define CLASS_ARGUMENT
#include "wyrazy.hpp"

class Op1arg : public Wyrazenie {
public:
    virtual const int prio() = 0;
    virtual double oblicz()=0;
    virtual std::string opis()=0;
};

class Sin : public Op1arg {
private:
    Wyrazenie *opd;
public:
    Sin(Wyrazenie *o);
    const int prio() override;
    double oblicz() override;
    std::string opis() override;
};

class Cos : public Op1arg {
private:
    Wyrazenie *opd;
public:
    Cos(Wyrazenie *o);
    const int prio() override;
    double oblicz() override;
    std::string opis() override;
};

class Exp : public Op1arg {
private:
    Wyrazenie *opd;
public:
    Exp(Wyrazenie *o);
    const int prio() override;
    double oblicz() override;
    std::string opis() override;
};

class Ln : public Op1arg {
private:
    Wyrazenie *opd;
public:
    Ln(Wyrazenie *o);
    const int prio() override;
    double oblicz() override;
    std::string opis() override;
};

class Bezwzgl : public Op1arg {
private:
    Wyrazenie *opd;
public:
    Bezwzgl(Wyrazenie *o);
    const int prio() override;
    double oblicz() override;
    std::string opis() override;
};

class Przeciw : public Op1arg {
private:
    Wyrazenie *opd;
public:
    Przeciw(Wyrazenie *o);
    const int prio() override;
    double oblicz() override;
    std::string opis() override;
};

class Odwrot : public Op1arg {
private:
    Wyrazenie *opd;
public:
    Odwrot(Wyrazenie *o);
    const int prio() override;
    double oblicz() override;
    std::string opis() override;
};

class Op2arg : public Wyrazenie {
public:
    virtual const int prio() = 0;
    virtual double oblicz()=0;
    virtual std::string opis()=0;
};

class Dodaj : public Op2arg {
private:
    Wyrazenie *opd1;
    Wyrazenie *opd2;
public:
    Dodaj(Wyrazenie *o1,Wyrazenie *o2);
    const int prio() override;
    double oblicz() override;
    std::string opis() override;
};

class Odejmij : public Op2arg {
private:
    Wyrazenie *opd1;
    Wyrazenie *opd2;
public:
    Odejmij(Wyrazenie *o1,Wyrazenie *o2);
    const int prio() override;
    double oblicz() override;
    std::string opis() override;
};

class Mnoz : public Op2arg {
private:
    Wyrazenie *opd1;
    Wyrazenie *opd2;
public:
    Mnoz(Wyrazenie *o1,Wyrazenie *o2);
    const int prio() override;
    double oblicz() override;
    std::string opis() override;
};

class Dziel : public Op2arg {
private:
    Wyrazenie *opd1;
    Wyrazenie *opd2;
public:
    Dziel(Wyrazenie *o1,Wyrazenie *o2);
    const int prio() override;
    double oblicz() override;
    std::string opis() override;
};

class Modulo : public Op2arg {
private:
    Wyrazenie *opd1;
    Wyrazenie *opd2;
public:
    Modulo(Wyrazenie *o1,Wyrazenie *o2);
    const int prio() override;
    double oblicz() override;
    std::string opis() override;
};

class Logarytm : public Op2arg {
private:
    Wyrazenie *opd1;
    Wyrazenie *opd2;
public:
    Logarytm(Wyrazenie *o1,Wyrazenie *o2);
    const int prio() override;
    double oblicz() override;
    std::string opis() override;
};

class Potega : public Op2arg {
private:
    Wyrazenie *opd1;
    Wyrazenie *opd2;
public:
    Potega(Wyrazenie *o1,Wyrazenie *o2);
    const int prio() override;
    double oblicz() override;
    std::string opis() override;
};

#endif // CLASS_ARGUMENT
