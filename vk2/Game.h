#ifndef GAME_H
#define GAME_H

class Game {
private:
    int maxNumber;      // suurin mahdollinen arvottava luku
    int numberToGuess;  // arvottu salainen luku
    int guesses;        // arvausten määrä

public:
    // Konstruktori: asettaa ylärajan, arpoo luvun ja nollaa laskurin
    explicit Game(int maxNum);

    // Destruktori: debug-viesti, kun olio poistuu pinosta
    ~Game();

    // Suorittaa pelin: kysyy arvauksia, antaa vihjeet
    void Play();

    // Tulostaa pelin lopputuloksen (oikea luku ja arvausten määrä)
    void PrintGameResult();
};

#endif // GAME_
