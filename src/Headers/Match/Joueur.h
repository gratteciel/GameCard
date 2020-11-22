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
    int m_pdv;
    Utilisateur *m_user;
    Pioche m_pioche;



public:
    //Constructeur et destructeur
    Joueur(Utilisateur *_user);
    ~Joueur();

    //Méthodes

    //Accesseurs et mutateurs
    int getPdv()const;
    Utilisateur* getUser()const;
    void setPioche(const Collection& _cartesBase);


};


#endif //CARDGAME_JOUEUR_H
