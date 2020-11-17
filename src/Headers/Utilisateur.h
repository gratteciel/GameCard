//
// Created by bemat on 04/11/2020.
//

#ifndef CARDGAME_UTILISATEUR_H
#define CARDGAME_UTILISATEUR_H

#include "..\..\biblio.h"
#include "Cartes/Deck.h"
#include <sstream>

class Utilisateur {
private:
    std::string m_pseudo;
    std::vector<Deck> m_decks;

    //Ici sont stockés les immatriculations des cartes qui n'ont pas de deck
    std::vector<int> m_cartesSeul;

public:
    //Constructeur et destructeur
    Utilisateur(std::string _pseudo);
    ~Utilisateur();

    //Méthodes
    void creerDatabase();
    void chargerUtilisateur();

    void affichageUtilisateur();
    //Accesseurs et mutateurs
    std::string getPseudo() const;
};


#endif //CARDGAME_UTILISATEUR_H
