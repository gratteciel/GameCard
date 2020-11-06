//
// Created by bemat on 03/11/2020.
//

#ifndef CARDGAME_ENERGIE_H
#define CARDGAME_ENERGIE_H


#include "Carte.h"

class Energie : public Carte{
    private:
        short m_domaine;

    public:
        //Constructeur et destructeur
        Energie(int _immatriculation);
        ~Energie();

        //Méthodes
        void afficheDescription();

        //Accesseurs et mutateurs
        short getDomaine() const;
};


#endif //CARDGAME_ENERGIE_H
