//
// Created by bemat on 03/11/2020.
//

#ifndef CARDGAME_ENERGIE_H
#define CARDGAME_ENERGIE_H


#include "Carte.h"
#include "../../Headers/Affichage/Affichage.h"
class Energie : public Carte{
    private:
        int m_domaine2;
    public:
        //Constructeur et destructeur

        Energie(int _immatriculation, int _id, std::string _nom, std::string _description, int _domaine, int _domaine2);
        ~Energie();

        //Méthodes
        void affiche(float x, float y);
        void creer(std::ofstream& fileOutput);
        void afficheDescription();
        //Accesseurs et mutateurs

        int getDomaine2() const;
};


#endif //CARDGAME_ENERGIE_H
