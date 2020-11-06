//
// Created by bemat on 05/11/2020.
//

#ifndef CARDGAME_JOUEUR_H
#define CARDGAME_JOUEUR_H

#include "../Utilisateur.h"
#include "Pioche.h"
#include <deque>

class Joueur {
private:
    short m_pdv;
    Utilisateur *m_user;
    Pioche m_pioche;

    int m_numDeck;

public:
    //Constructeur et destructeur
    Joueur(Utilisateur &_link, int _numDeck);
    ~Joueur();
    //Méthodes

    //Accesseurs et mutateurs
};


#endif //CARDGAME_JOUEUR_H
