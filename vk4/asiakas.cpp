#include "asiakas.h"
#include <iostream>
#include <iomanip>

Asiakas::Asiakas(const std::string& n, double luottoraja)
    : nimi(n), pankkitili(), luottotili(n, luottoraja) {}  // <-- nimi välitetään

void Asiakas::showSaldo() const {
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "Asiakas: " << nimi << "\n";
    std::cout << "  Pankkitilin saldo: " << pankkitili.getBalance() << " EUR\n";
    std::cout << "  Luottotilin saldo: " << luottotili.getBalance()
              << " EUR (negatiivinen = velkaa)\n";
}

bool Asiakas::talletus(double amount) { return pankkitili.deposit(amount); }
bool Asiakas::nosto(double amount)    { return pankkitili.withdraw(amount); }
bool Asiakas::luotonMaksu(double a)   { return luottotili.deposit(a); }
bool Asiakas::luotonNosto(double a)   { return luottotili.withdraw(a); }

bool Asiakas::tiliSiirto(double amount, Asiakas& toinen) {
    if (amount < 0) return false;
    if (!pankkitili.withdraw(amount)) {
        std::cout << "Tilisiirto epäonnistui: ei katetta.\n";
        return false;
    }
    if (!toinen.pankkitili.deposit(amount)) {
        pankkitili.deposit(amount); // peruutus
        std::cout << "Tilisiirto epäonnistui vastaanottajalle.\n";
        return false;
    }
    return true;
}
