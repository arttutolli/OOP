#ifndef NOTIFIKAATTORI_H
#define NOTIFIKAATTORI_H

#include <string>
#include "seuraaja.h"

class Notifikaattori
{
public:
    Notifikaattori();

    void lisaa(Seuraaja* uusi);
    void poista(Seuraaja* poistettava);

    void tulosta() const;
    void postita(const std::string& viesti);

private:
    Seuraaja* alku_;   // linkitetyn listan alku
};

#endif
