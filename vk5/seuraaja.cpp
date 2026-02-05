#include "seuraaja.h"
#include <iostream>

Seuraaja::Seuraaja(const std::string& nimi)
    : nimi_(nimi), next(nullptr)
{
    std::cout << "Luodaan seuraaja " << nimi_ << std::endl;
}

const std::string& Seuraaja::getNimi() const
{
    return nimi_;
}

void Seuraaja::paivitys(const std::string& viesti)
{
    std::cout << "Seuraaja " << nimi_ << " sai viestin: " << viesti << std::endl;
}

