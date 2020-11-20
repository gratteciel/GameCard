//
// Created by bemat on 03/11/2020.
//

#ifndef CARDGAME_ENERGIE_H
#define CARDGAME_ENERGIE_H


#include "Carte.h"

class Energie : public Carte{
    private:
        char m_domaine;
    public:
        //Constructeur et destructeur
        Energie(int _immatriculation, int _id, std::vector<int> _cartesBase);
        Energie(int _immatriculation, int _id, std::string _nom, std::string _description, char _domaine);
        ~Energie();

        //Méthodes

        void creer(std::ofstream& fileOutput);
        //Accesseurs et mutateurs
        char getDomaine() const;
};


#endif //CARDGAME_ENERGIE_H
