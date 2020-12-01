//
// Created by bemat on 24/11/2020.
//

#ifndef CARDGAME_AFFICHEMATCH_H
#define CARDGAME_AFFICHEMATCH_H

#include "Affichage.h"
#include "../Match/Match.h"

class AfficheMatch : public Affichage{
private:

    Match m_match;
public:
    //Constructeur et Destructeurs
    AfficheMatch();
    ~AfficheMatch();
    //Methodes
    void lancement(Utilisateur *_user1, Utilisateur *_user2,  const Collection& _cartesBase);
    int boucleMatch();
    void animationDebutDeCombat();
    void affichageTerrain();
    void afficheEnjeux();

    //Getters et Setters



};


#endif //CARDGAME_AFFICHEMATCH_H