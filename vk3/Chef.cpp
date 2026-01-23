
#include "Chef.h"
#include <iostream>
#include <algorithm>

// Chef-luokan toteutus

Chef::Chef(const std::string& kokkiNimi) : nimi(kokkiNimi)
{
    std::cout << "Chef luotu: " << nimi << std::endl;
}

Chef::~Chef()
{
    std::cout << "Chef poistuu: " << nimi << std::endl;
}

int Chef::teeSalaatti(int aineksia)
{
    std::cout << nimi << " valmistaa salaatin" << std::endl;
    return aineksia / 5;
}

int Chef::teeKeitto(int aineksia)
{
    std::cout << nimi << " valmistaa keiton" << std::endl;
    return aineksia / 3;
}

// ItalianChef-luokan toteutus

ItalianChef::ItalianChef(const std::string& kokkiNimi, int j, int v)
    : Chef(kokkiNimi), salainen("pizza"), jauhot(j), vesi(v)
{
    std::cout << "ItalianChef luotu: " << nimi << std::endl;
}

ItalianChef::~ItalianChef()
{
    std::cout << "ItalianChef poistuu: " << nimi << std::endl;
}

int ItalianChef::valmistaPizza(int jauhoja, int vettä)
{
    std::cout << nimi << " tekee pizzaa" << std::endl;
    return std::min(jauhoja / 5, vettä / 5);
}

bool ItalianChef::kysySalainen(const std::string& vastaus)
{
    if (vastaus == salainen) {
        std::cout << "Salasana oikein!" << std::endl;
        std::cout << "Pizzoja tehtiin: "
                  << valmistaPizza(jauhot, vesi) << std::endl;
        return true;
    }

    std::cout << "Väärä salasana" << std::endl;
    return false;
}
