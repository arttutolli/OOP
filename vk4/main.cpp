
#include <iostream>
#include "asiakas.h"

int main() {
    // Luodaan kaksi asiakasta, joilla on eri luottorajat
    Asiakas a("Aapeli", 2000);
    Asiakas b("Bertta", 1500);

    std::cout << "\n--- Alkusaldot ---\n";
    a.showSaldo();
    b.showSaldo();

    // Talletuksia pankkitileille
    std::cout << "\nAapeli tallettaa 500 euroa pankkitilille.\n";
    a.talletus(500);

    std::cout << "Bertta tallettaa 200 euroa pankkitilille.\n";
    b.talletus(200);

    std::cout << "\n--- Talletusten jalkeen ---\n";
    a.showSaldo();
    b.showSaldo();

    // Tilisiirto Matilta Liisalle
    std::cout << "\nAapeli siirtaa 150 euroa Liisalle.\n";
    a.tiliSiirto(150, b);

    std::cout << "\n--- Tilisiirron jalkeen ---\n";
    a.showSaldo();
    b.showSaldo();

    // Luoton nosto
    std::cout << "\nBertta nostaa luottoa 300 euroa.\n";
    b.luotonNosto(300);

    std::cout << "\n--- Luoton noston jalkeen ---\n";
    b.showSaldo();

    // Luoton maksu
    std::cout << "\nBertta maksaa luottoa takaisin 100 euroa.\n";
    b.luotonMaksu(100);

    std::cout << "\n--- Luoton maksun jalkeen ---\n";
    b.showSaldo();

    return 0;
}
