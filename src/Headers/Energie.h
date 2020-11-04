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
        Energie(std::string _nom, std::string _descritpion,short _domaine);
        ~Energie();

        //Accesseurs et mutateurs
        short getDomaine() const;
};


#endif //CARDGAME_ENERGIE_H
