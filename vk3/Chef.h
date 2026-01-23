
#ifndef CHEF_H
#define CHEF_H

#include <string>

class Chef {
protected:
    std::string nimi;

public:
    Chef(const std::string& kokkiNimi);
    virtual ~Chef();

    int teeSalaatti(int aineksia);
    int teeKeitto(int aineksia);
};

class ItalianChef : public Chef {
private:
    std::string salainen;
    int jauhot;
    int vesi;

    int valmistaPizza(int jauhoja, int vettä);

public:
    ItalianChef(const std::string& kokkiNimi, int j, int v);
    ~ItalianChef();

    bool kysySalainen(const std::string& vastaus);
};

#endif
