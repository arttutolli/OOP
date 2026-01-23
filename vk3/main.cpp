#include "Chef.h"
#include <iostream>

int main()
{
    Chef kotikokki("Gordon");
    kotikokki.teeSalaatti(12);
    kotikokki.teeKeitto(10);

    ItalianChef italialainen("Mario", 25, 20);
    italialainen.kysySalainen("pizza");

    return 0;
}
