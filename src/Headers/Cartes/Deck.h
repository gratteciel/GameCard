//
// Created by bemat on 04/11/2020.
//

#ifndef CARDGAME_DECK_H
#define CARDGAME_DECK_H

#include "../../../biblio.h"

#include "Energie.h"
#include "Creature.h"

class Deck {
    private:
        std::vector<Energie> m_energies;
        std::vector<Creature> m_creatures;
        //std::vector<Speciale> m_speciales;
        bool m_tailleConst; //Si c'est un deck avec une taille constante
    public:
        //Constructeur et destructeur
        Deck(bool _tailleConst);
        ~Deck();

        //Méthodes
        unsigned nombreCartes() const;
        //Accesseurs et mutateurs
        bool getTailleConst() const;

};


#endif //CARDGAME_DECK_H
