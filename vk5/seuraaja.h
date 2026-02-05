#ifndef SEURAAJA_H
#define SEURAAJA_H

#include <string>

class Seuraaja
{
public:
    explicit Seuraaja(const std::string& nimi);

    const std::string& getNimi() const;
    void paivitys(const std::string& viesti);

    Seuraaja* next;   // linkitetyn listan osoitin

private:
    std::string nimi_;
};

#endif

