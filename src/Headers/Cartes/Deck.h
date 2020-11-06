//
// Created by bemat on 04/11/2020.
//

#ifndef CARDGAME_DECK_H
#define CARDGAME_DECK_H

#include "../../../biblio.h"

#include "Energie.h"
#include "Creature.h"
#include "../Collection.h"

class Deck {
    private:
        //vecteur d'id
        std::vector<int> m_cartes;
    public:
        //Constructeur et destructeur
        Deck();
        ~Deck();

        //Méthodes

        //Accesseurs et mutateurs
        bool getTailleConst() const;

};


#endif //CARDGAME_DECK_H
