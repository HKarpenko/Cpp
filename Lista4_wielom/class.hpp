#ifndef CLASS_WIEL
#define CLASS_WIEL

class Wielomian{
private:
    int stopien;
    double *wspolcz;
public:
    friend std::ostream& operator<< (std::ostream &out, const Wielomian &w);
    friend std::istream& operator>> (std::istream &in, Wielomian &w);
    friend Wielomian operator +(const Wielomian &u, const Wielomian &v);
    friend Wielomian operator -(const Wielomian &u);
    friend Wielomian operator -(const Wielomian &u, const Wielomian &v);
    friend Wielomian operator *(const Wielomian &u, const Wielomian &v);
    friend Wielomian operator *(const Wielomian &u, double c);
    double& operator[] (const int index){
        return wspolcz[index];
    }
    double& operator[] (const int index) const {
        return wspolcz[index];
    }
    Wielomian(int st=0, double wsp=1.0){
        stopien=st;
        wspolcz = new double[1];
        wspolcz[0]=wsp;
    }
    Wielomian(int st, double wsp[]){
        if(st<0)
            throw std::invalid_argument("Podany ujemny stopien");
        if(wsp[st]==0)
            throw std::invalid_argument("Podany bledny wspolczynnik");
        stopien=st;
        wspolcz = new double[st+1];
        for(int i=0;i<st+1;i++)
            wspolcz[i]=wsp[i];
    }
    ~Wielomian() {
		delete[] wspolcz;
    }
    Wielomian(const std::initializer_list<double> &wsp){
        int i=0;
        stopien = wsp.size()-1;
        wspolcz = new double[wsp.size()];
        for (double element : wsp) {
			wspolcz[i] = element;
			i++;
        }
    }
    Wielomian(const Wielomian &obj) {
        this->wspolcz = new double[obj.get_degree()+1];
        this->stopien=obj.get_degree();
        for (int i=0;i<obj.get_degree()+1;i++)
            this->wspolcz[i] = obj[i];
    }
    Wielomian &operator =(const Wielomian &obj) {
        if (this == &obj)
            return *this;
        delete[] this->wspolcz;
        this->wspolcz = new double[obj.get_degree()+1];
        this->stopien=obj.get_degree();
        for (int i=0;i<obj.get_degree()+1;i++)
            this->wspolcz[i] = obj[i];
        return *this;
    }
    Wielomian(Wielomian &&obj){
        this->wspolcz = obj.wspolcz;
        this->stopien=obj.get_degree();
        obj.wspolcz=nullptr;
    }
    Wielomian &operator =(Wielomian &&obj) {
        delete[] this->wspolcz;
        this->wspolcz = obj.wspolcz;
        this->stopien=obj.get_degree();
        obj.wspolcz=nullptr;
        return *this;
    }
    double operator() (double x) const {
        double rez=(*this)[this->stopien];
        for(int i=this->stopien-1; i>=0; i--)
            rez=rez*x + (*this)[i];
        return rez;
    }
    Wielomian &operator +=(const Wielomian &v){
        return *this=*this+v;
    }
    Wielomian &operator -=(const Wielomian &v){
        return *this=*this-v;
    }
    Wielomian &operator *=(const Wielomian &v){
        return *this=*this*v;
    }
    Wielomian &operator *=(double c){
        return *this=*this*c;
    }
    int get_degree() const {
        return stopien;
    }

};


#endif
