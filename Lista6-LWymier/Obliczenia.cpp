#include <iostream>
#include <cmath>
#include "Obliczenia.hpp"

using namespace Obliczenia;

Wymierna::Wymierna(int Licz, int Mian){
    if(Mian==0)
        throw Dzielenie_przez_0();
    if(Mian<0){
        Mian=-Mian;
        Licz*=-1;
    }
    int dziel=gcd(abs(Licz),Mian);
    while(dziel!=1) {
        Licz/=dziel;
        Mian/=dziel;
        dziel=gcd(abs(Licz),Mian);
    }
    licz=Licz;
    mian=Mian;
}
Wymierna Wymierna::operator-() const{
    return Wymierna(-licz,mian);
}

Wymierna Wymierna::operator!() const{
    if(licz==0)
        throw Dzielenie_przez_0();
    return Wymierna(mian,licz);
}

Wymierna::operator int() const{
    return floor(licz/mian);
}

Wymierna::operator double() const{
    return (double)licz/(double)mian;
}

Wymierna::getLicz(){return licz;}
Wymierna::getMian(){return mian;}
namespace Obliczenia{
    Wymierna operator+(const Wymierna &l, const Wymierna &r){
        long long num=static_cast<long long>(l.licz)*r.mian + static_cast<long long>(r.licz)*l.mian;
        long long den=static_cast<long long>(l.mian)*r.mian;
        if(num < -2147483648 || num > 2147483647 || den > 2147483647)
            throw Przekroczenie_zakresu();
        return Wymierna(static_cast<int>(num) , static_cast<int>(den));
    }
    Wymierna operator-(const Wymierna &l, const Wymierna &r){
        return l+(-r);
    }
    Wymierna operator*(const Wymierna &l, const Wymierna &r){
        long long num=static_cast<long long>(l.licz)*r.licz;
        long long den=static_cast<long long>(l.mian)*r.mian;
        if(num < -2147483648 || num > 2147483647 || den > 2147483647)
            throw Przekroczenie_zakresu();
        return Wymierna(static_cast<int>(num) , static_cast<int>(den));
    }

    Wymierna operator/(const Wymierna &l, const Wymierna &r){
        if(r.licz==0)
            throw Dzielenie_przez_0();
        long long num=static_cast<long long>(l.licz)*r.mian;
        long long den=static_cast<long long>(l.mian)*r.licz;
        if(num < -2147483648 || num > 2147483647 || den > 2147483647 || den < -2147483648)
            throw Przekroczenie_zakresu();
        return Wymierna(static_cast<int>(num) , static_cast<int>(den));
    }

    std::ostream& operator<<(std::ostream &Out, const Wymierna &ww){
        Out << ww.licz << "/" << ww.mian;
        return Out;
    }

    int gcd(int n, int m) {
    if(n<m)
        std::swap(n,m);
    while(m>0){
        n=n%m;
        std::swap(n,m);
    }
    return n;
    }
}
