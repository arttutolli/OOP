
#ifndef LUOTTOTILI_H
#define LUOTTOTILI_H

#include <string>
#include "pankkitili.h"

class Luottotili : public Pankkitili {
private:
    std::string omistaja;   // Vaatimuksen mukainen omistajan nimi
    double luottoraja;      // negatiivinen arvo, esim. -2000

public:
    Luottotili(const std::string& nimi, double raja);  // nimi + raja (vaatimus)

    bool deposit(double amount) override;   // velan maksu, ei yli nollan
    bool withdraw(double amount) override;  // velan nosto, ei alle luottorajan

    const std::string& getOwner() const { return omistaja; }
    double getLuottoraja() const { return luottoraja; }
};

#endif
