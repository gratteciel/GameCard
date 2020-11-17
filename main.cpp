#include "main.h"
#include "Affichage.h"


int main() {
    Utilisateur user = Utilisateur("Mathis");
    Utilisateur user1= Utilisateur("Emilian");
    Affichage affichageSFML;
    Match match(&user,&user1,3,1);
    match.lancementmatch();
    return 0;
}END_OF_MAIN();
