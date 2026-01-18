#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int pelaaPeli(int maksimiLuku) {

    time_t nykyAika = time(nullptr);
    srand(nykyAika);

    int salainenLuku = rand() % maksimiLuku;
    int pelaajanArvaus = -1;
    int arvaustenMaara = 0;

    while (pelaajanArvaus != salainenLuku) {
        cout << "Arvaa lukua: ";
        cin >> pelaajanArvaus;
        arvaustenMaara++;

        if (pelaajanArvaus < salainenLuku) {
            cout << "Luku on isompi" << endl;
        }
        else if (pelaajanArvaus > salainenLuku) {
            cout << "Luku on pienempi" << endl;
        }
    }

    cout << "Oikein arvattu!" << endl;
    return arvaustenMaara;
}

int main() {
    cout << "Anna maksimi luku minka kone pystyy valitsemaan: ";
    int maksimiLuku;
    cin >> maksimiLuku;

    int arvaustenMaara = pelaaPeli(maksimiLuku);

    cout << "Arvauksia yhteensa: " << arvaustenMaara << endl;
    return 0;
}
