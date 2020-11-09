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

    int m_numDeck;

public:
    //Constructeur et destructeur
    Joueur(Utilisateur *_user, int _numDeck);
    ~Joueur();
    //Méthodes
    void affichageJoueur();//affichage de l'utilisateur avec son deck et les cartes


    //Accesseurs et mutateurs
    //à faire, faire les getters et setters pour le user
    int getNumDeck() const;
    int getPdv()const;
    Utilisateur* getUser()const;

    void setNumDeck(int _numDeck);

};


#endif //CARDGAME_JOUEUR_H
