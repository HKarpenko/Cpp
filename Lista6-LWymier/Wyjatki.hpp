#ifndef WYJATKI
#define WYJATKI

class Wyjatek_wymierny {
public:
    virtual const char* getErr() = 0;
};

class Dzielenie_przez_0 : public Wyjatek_wymierny {
public:
    const char* getErr() override;
};

class Przekroczenie_zakresu : public Wyjatek_wymierny {
public:
    const char* getErr() override;
};

#endif // WYJATKI
