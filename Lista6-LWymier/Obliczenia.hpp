#ifndef OBLICZENIA
#define OBLICZENIA
#include "Wyjatki.hpp"

namespace Obliczenia{
    class Wymierna {
    private:
        int licz, mian;
    public:
        friend std::ostream& operator<<(std::ostream& Out, const Wymierna &ww);
        friend Wymierna operator+(const Wymierna &l, const Wymierna &r);
        friend Wymierna operator-(const Wymierna &l, const Wymierna &r);
        friend Wymierna operator*(const Wymierna &l, const Wymierna &r);
        friend Wymierna operator/(const Wymierna &l, const Wymierna &r);
        Wymierna(int Licz=0, int Mian=1);
        Wymierna operator-() const;
        Wymierna operator!() const;
        explicit operator int() const;
        operator double() const;
        getLicz();
        getMian();
    };
    int gcd(int n, int m);
}


#endif // OBLICZENIA

