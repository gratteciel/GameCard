#include "main.h"


int main() {
    Utilisateur user = Utilisateur("Mathis");
    Utilisateur user1= Utilisateur("Emilian");
    Match match(&user,&user1,3,1);
    match.lancementmatch();

    //ne pas oublier de liberer la mémoire 
    return 0;
}
