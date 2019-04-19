#ifndef CLASS_FIFO
#define CLASS_FIFO

class FIFO{
private:
    int pojemnosc;
    int pocz;
    int ile;
    std::string *kolejka;
public:
    FIFO(int pom){
        if(pojemnosc<0)
            throw std::invalid_argument("Podana ujemna pojemnosc");
        else{
            pojemnosc=pom;
            pocz=0;
            ile=0;
            kolejka = new std::string[pojemnosc];
        }
    }
    FIFO() : FIFO(1) {}
    ~FIFO() {
		delete[] kolejka;
    }
    FIFO(const std::initializer_list<std::string> &lista): FIFO(lista.size()) {
        for (std::string element : lista) {
			kolejka[ile] = element;
			ile++;
		}
    }
    FIFO(const FIFO &obj) {
        this->kolejka = new std::string[obj.pojemnosc];
        this->ile=obj.ile;
        this->pojemnosc=obj.pojemnosc;
        this->pocz=obj.pocz;
        for (int i=0;i<obj.ile;i++)
            this->kolejka[i]=obj.kolejka[i];
    }
    FIFO &operator=(const FIFO &obj) {
        if (this == &obj)
            return *this;
        delete[] this->kolejka;
        this->ile=obj.ile;
        this->pojemnosc=obj.pojemnosc;
        this->pocz=obj.pocz;
        this->kolejka = new std::string[obj.pojemnosc];
        for (int i=0;i<obj.ile;i++)
            this->kolejka[i]=obj.kolejka[i];
        return *this;
    }
    FIFO(FIFO &&obj){
        this->kolejka = obj.kolejka;
        this->ile=obj.ile;
        this->pojemnosc=obj.pojemnosc;
        this->pocz=obj.pocz;
        obj.kolejka=nullptr;
    }
    FIFO &operator=(FIFO &&obj) {
        delete[] this->kolejka;
        this->ile=obj.ile;
        this->pojemnosc=obj.pojemnosc;
        this->pocz=obj.pocz;
        this->kolejka = obj.kolejka;
        obj.kolejka=nullptr;
        return *this;
    }
    void wloz(std::string str) {
        if(ile==pojemnosc)
            throw std::invalid_argument("FIFO overflow");
        if(pocz+ile<pojemnosc)
            kolejka[ile] = str;
        else
            kolejka[pocz+ile-pojemnosc]=str;
        ile++;
    }
    std::string wyciagnij() {
        if(ile==0)
            throw std::invalid_argument("Nie ma elementow");
        ile--;
        pocz++;
        if(pocz==pojemnosc){
            pocz=0;
            return kolejka[pojemnosc-1];
        }
        return kolejka[pocz-1];
    }
    std::string sprawdz() const {
        if(ile==0)
            throw std::invalid_argument("Nie ma elementow");
        return kolejka[pocz];
    }
    int rozmiar() const {
        return ile;
    }
    int get_pom() const {
        return pojemnosc;
    }
    void wypisz() const{
        int buf=pocz;
        if(ile==0)
            throw std::invalid_argument("Nie ma elementow");
        for(int i=0;i<ile;i++){
            std::cout << kolejka[buf] << std::endl;
            buf++;
            if(buf==pojemnosc)
                buf=0;
        }
    }
};

#endif
