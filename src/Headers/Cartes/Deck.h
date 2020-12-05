//
// Created by bemat on 04/11/2020.
//

#ifndef CARDGAME_DECK_H
#define CARDGAME_DECK_H

#include "../../biblio.h"

class Deck {
    private:
        //vecteur d'immatriculation
        std::vector<int> m_cartes;
        static const unsigned int m_numCartes; //Nombre de cartes par deck

    public:
        //Constructeur et destructeur
        Deck(std::vector<int>& _cartes);
        ~Deck();

        //Méthodes
        bool getDeckActuValide();

        //Accesseurs et mutateurs
        static const unsigned int getNumCartes();
        std::vector<int>& getCartes();

};


#endif //CARDGAME_DECK_H
