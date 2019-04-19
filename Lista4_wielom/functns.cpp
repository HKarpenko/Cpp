#include <iostream>
#include <E:\Программирование\универ\Lista4\class.hpp>

using namespace std;

class Wielomian;

std::ostream& operator <<(ostream &out, const Wielomian &w){
    out << w[w.get_degree()] << "*x(" << w.get_degree() << ")";
    for(int i=w.get_degree()-1;i>0;i--)
        if(w[i]>=0)
            out << "+" << w[i] << "*x(" << i << ")";
        else
            out << w[i] << "*x(" << i << ")";
    if(w[0]>=0)
        out << "+" << w[0] << std::endl;
    else
        out << w[0] << std::endl;
    return out;
}

std::istream& operator >>(istream &in, Wielomian &w){
    for(int i=0;i<=w.get_degree();i++)
        in >> w[i];
    return in;
}

Wielomian operator +(const Wielomian &u, const Wielomian &v){
    Wielomian mx;
    Wielomian mn;
    if(u.get_degree()>v.get_degree()){
        mx=u;
        mn=v;
    }
    else {
        mx=v;
        mn=u;
    }
    double *wsp = new double[mx.get_degree()+1];
    for(int i=0;i<=mx.get_degree();i++){
        wsp[i]=mx[i];
        if(i<=mn.get_degree())
            wsp[i]+=mn[i];
    }
    int wyn_deg=mx.get_degree();
    for(int i=mx.get_degree();i>0;i--)
        if(wsp[i]==0)
            wyn_deg--;
        else
            break;
    double *rwsp = new double[wyn_deg+1];
    for(int i=0;i<=wyn_deg;i++)
        rwsp[i]=wsp[i];
    Wielomian wyn(wyn_deg,rwsp);
    delete[] wsp;
    delete[] rwsp;
    return wyn;
}

Wielomian operator *(double c, const Wielomian &u){
    if (c==0)
        return Wielomian(0,0.0);
    Wielomian wyn=u;
    for(int i=0;i<=wyn.get_degree();i++)
        wyn[i]*=c;
    return wyn;
}

Wielomian operator -(const Wielomian &u){
    Wielomian wyn=u;
    cout << wyn.get_degree() << endl;
    return -1*wyn;
}

Wielomian operator -(const Wielomian &u, const Wielomian &v){
    return u+(-v);
}


Wielomian operator *(const Wielomian &u, const Wielomian &v) {
    if ((u.get_degree()==0 && u[0]==0)||(v.get_degree()==0  && v[0]==0))
        return Wielomian(0,0.0);
    double *buf;
    buf = new double[u.get_degree()+v.get_degree()+1];
    for(int i=u.get_degree()+v.get_degree();i>=0;i--) {
        if(i>=u.get_degree())
            buf[i]=v[i-u.get_degree()];
        else
            buf[i]=0;
    }
    Wielomian wyn(u.get_degree()+v.get_degree(),buf);
    wyn=u[u.get_degree()]*wyn;
    delete[] buf;
    for(int i=u.get_degree()-1;i>=0;i--)
        if(u[i]!=0) {
            buf = new double[v.get_degree()+i+1];
            for(int j=v.get_degree()+i;j>=0;j--){
                if(j>=i)
                    buf[j]=v[j-i];
                else
                    buf[j]=0;
            }
            wyn=wyn+u[i]*Wielomian(v.get_degree()+i,buf);
            delete[] buf;
        }
        else
            continue;
    return wyn;
}

