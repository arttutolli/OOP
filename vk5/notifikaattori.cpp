#include "notifikaattori.h"
#include <iostream>

Notifikaattori::Notifikaattori()
    : alku_(nullptr)
{
    std::cout << "Luodaan notifikaattori" << std::endl;
}

void Notifikaattori::lisaa(Seuraaja* uusi)
{
    uusi->next = alku_;
    alku_ = uusi;

    std::cout << "Notifikaattori lisaa seuraajan " << uusi->getNimi() << std::endl;
}

void Notifikaattori::poista(Seuraaja* poistettava)
{
    Seuraaja* nykyinen = alku_;
    Seuraaja* edellinen = nullptr;

    while (nykyinen != nullptr)
    {
        if (nykyinen->getNimi() == poistettava->getNimi())
        {
            if (edellinen == nullptr)
                alku_ = nykyinen->next;
            else
                edellinen->next = nykyinen->next;

            std::cout << "Notifikaattori poistaa seuraajan "
                      << poistettava->getNimi() << std::endl;
            return;
        }

        edellinen = nykyinen;
        nykyinen = nykyinen->next;
    }
}

void Notifikaattori::tulosta() const
{
    std::cout << "Notifikaattorin seuraajat:" << std::endl;

    Seuraaja* ptr = alku_;
    while (ptr != nullptr)
    {
        std::cout << " - " << ptr->getNimi() << std::endl;
        ptr = ptr->next;
    }
}

void Notifikaattori::postita(const std::string& viesti)
{
    std::cout << "Notifikaattori postittaa viestin: " << viesti << std::endl;

    Seuraaja* ptr = alku_;
    while (ptr != nullptr)
    {
        ptr->paivitys(viesti);
        ptr = ptr->next;
    }
}

