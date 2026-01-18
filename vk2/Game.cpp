#include <iostream>
#include <cstdlib>
#include <ctime>
#include <limits>
#include "Game.h"
using namespace std;

Game::Game(int maxNum) {
    maxNumber = (maxNum >= 1) ? maxNum : 1;

    guesses = 0;

    // Arvotaan salainen luku väliltä 1..maxNumber
    srand(static_cast<unsigned>(time(0)));
    numberToGuess = rand() % maxNumber + 1;

    cout << "GAME CONSTRUCTOR: object initialized with " << maxNumber << " as a maximum value" << endl;
}


Game::~Game() {
    cout << "GAME DESTRUCTOR: object cleared from stack memory" << endl;
}

// pelin runko
void Game::Play() {
    int guess;  // pelaajan arvaus

    do {
        cout << "Anna arvauksesi valilta 1-" << maxNumber << ": ";

        // Tarkistetaan, että syöte on kokonaisluku
        if (!(cin >> guess)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Virhe: syotteen tulee olla kokonaisluku." << endl;
            continue;
        }
        // Raja-arvot
        if (guess < 1 || guess > maxNumber) {
            cout << "Virhe: sallitut luvut ovat valilta 1-" << maxNumber << "." << endl;
            continue;
        }

        guesses++;  // kasvatetaan arvausten määrää

        if (guess < numberToGuess) {
            cout << "Arvauksesi on liian pieni." << endl;
        } else if (guess > numberToGuess) {
            cout << "Arvauksesi on liian suuri." << endl;
        } else {
            cout << "Oikein! Arvaus vastaa etsittya lukua = " << guess << endl;
        }

    } while (guess != numberToGuess);
}

//tulostus pelin lopuksi
void Game::PrintGameResult() {
    cout << "Oikea vastaus oli: " << numberToGuess << endl;
    cout << "Arvauksia yhteensa: " << guesses << endl;
}
