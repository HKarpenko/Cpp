#ifndef CLASS_ZMIENNA
#define CLASS_ZMIENNA

class Zmienna : public Wyrazenie {
private:
    static std::map<std::string,double> z_list;
    std::string sym;
public:
    Zmienna(std::string name);
    const int prio() override;
    double oblicz() override;
    std::string opis() override;
    static void ustal(std::string kl,double wart);
};

#endif // CLASS_ZMIENNA
