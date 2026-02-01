
#ifndef ASIAKAS_H
#define ASIAKAS_H

#include <string>
#include "pankkitili.h"
#include "luottotili.h"

class Asiakas {
private:
    std::string nimi;
    Pankkitili pankkitili;
    Luottotili luottotili;

public:
    Asiakas(const std::string& n, double luottoraja);

    void showSaldo() const;

    bool talletus(double amount);
    bool nosto(double amount);

    bool luotonMaksu(double amount);
    bool luotonNosto(double amount);

    bool tiliSiirto(double amount, Asiakas& toinen);
};

#endif
