
#include "luottotili.h"

Luottotili::Luottotili(const std::string& nimi, double raja)
    : omistaja(nimi)
{
    luottoraja = -raja;  // sisäisesti negatiivisena
    saldo = 0.0;         // ei velkaa alussa
}

bool Luottotili::deposit(double amount) {
    if (amount < 0) return false;
    if (saldo + amount > 0) return false;  // ei yli nollan
    saldo += amount;
    return true;
}

bool Luottotili::withdraw(double amount) {
    if (amount < 0) return false;
    if (saldo - amount < luottoraja) return false; // ei alle luottorajan
    saldo -= amount;
    return true;
}
