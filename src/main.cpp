#include "main.h"

int main() {

    Game jeu;
    jeu.connectionUser("Dimitri");
    jeu.connectionUser("Michel");

    jeu.lancerMatch(0,1);

    return 0;
}

