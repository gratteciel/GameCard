#include "main.h"

int main() {
    Utilisateur user = Utilisateur("Mathis");
    Collection carteBase;
    carteBase.chargerCartes();


    std::cout << carteBase.getNbCartes().speciale << std::endl;
    carteBase.creerCarte(Speciale(209,0,"boi","jimmy notron"));
    std::cout << carteBase.getNbCartes().speciale << std::endl;

    return 0;
}
