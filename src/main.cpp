#include "main.h"

int main() {
    Game jeu;
    jeu.connectionUser("Dimitri");
    jeu.connectionUser("Michel");

    jeu.lancerMatch("Dimitri","Michel");

    return 0;
}

