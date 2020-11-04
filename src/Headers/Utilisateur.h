//
// Created by bemat on 04/11/2020.
//

#ifndef CARDGAME_UTILISATEUR_H
#define CARDGAME_UTILISATEUR_H

#include "..\..\biblio.h"
#include "Cartes/Deck.h"

class Utilisateur {
private:
    std::string m_pseudo;
    std::vector<Deck> m_decks;
    Deck m_cartesSeul;
public:
    //Constructeur et destructeur
    Utilisateur(std::string _pseudo);
    ~Utilisateur();
    //Méthodes

    //Accesseurs et mutateurs
    std::string getPseudo() const;
};


#endif //CARDGAME_UTILISATEUR_H
