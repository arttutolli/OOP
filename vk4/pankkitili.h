
#ifndef PANKKITILI_H
#define PANKKITILI_H

class Pankkitili {
protected:
    double saldo;

public:
    Pankkitili() : saldo(0.0) {}
    virtual ~Pankkitili() = default;

    virtual bool deposit(double amount) {
        if (amount < 0) return false;
        saldo += amount;
        return true;
    }

    virtual bool withdraw(double amount) {
        if (amount < 0 || amount > saldo) return false;
        saldo -= amount;
        return true;
    }

    double getBalance() const { return saldo; }
};

#endif
