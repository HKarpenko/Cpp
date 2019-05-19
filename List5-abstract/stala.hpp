#ifndef CLASS_STALA
#define CLASS_STALA

class Stala : public Wyrazenie {
public:
    virtual const int prio() = 0;
    virtual double oblicz()=0;
    virtual std::string opis()=0;
};

class Pi : public Stala {
public:
    Pi();
    const int prio() override;
    double oblicz() override;
    std::string opis() override;
};

class E : public Stala {
public:
    E();
    const int prio() override;
    double oblicz() override;
    std::string opis() override;
};

class Fi : public Stala {
public:
    Fi();
    const int prio() override;
    double oblicz() override;
    std::string opis() override;
};

#endif // CLASS_STALA
