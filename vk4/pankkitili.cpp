#include <iostream>
#include <string>
using namespace std;

class Pankkitili {
private:
    string omistaja;  // Tilin omistajan nimi
    double saldo;     // Tilin saldo

public:
    // Konstruktori, jossa asetetaan tilin omistaja
    Pankkitili(string s) {
        omistaja = s;
        saldo = 0.0;  // Alustetaan saldo nollaksi
        cout << "Pankkitili luotu " << omistaja << ":lle" << endl;
    }

    // Palauttaa tilin saldon
    double getBalance() {
        return saldo;
    }

    // Talletus funktio
    bool deposit(double d) {
        if (d > 0) {
            saldo += d;  // Lisätään saldoa
            cout << omistaja << " Pankkitili: talletus " << d << " tehty" << endl;
            return true;
        } else {
            cout << "Lukema tulee olla positiivinen" << endl;
            return false;
        }
    }

    // Nosto funktio
    bool withdraw(double d) {
        if (saldo - d >= 0) {  // Varmistetaan, ettei saldo mene negatiiviseksi
            saldo -= d;
            cout << omistaja << " Pankkitili: nosto " << d << " tehty" << endl;
            return true;
        } else {
            cout << "Tilillä liian vähän katetta" << endl;
            return false;
        }
    }
};
