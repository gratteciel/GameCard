//
// Created by bemat on 04/11/2020.
//

#ifndef CARDGAME_ATTAQUE_H
#define CARDGAME_ATTAQUE_H

#include "../../../biblio.h"
#include "Carte.h"

//Hérite de Carte : nom et description
class Attaque : public Carte{
    private:
        short m_degat;
        //Nombre de point demandés d'énergie pour lancer l'attaque
        std::vector<std::vector<short> > m_nbPoints;
    public:
        //Constructeur et destructeur
        Attaque(std::string _nom, std::string _description, short _degat);
        ~Attaque();
        //Méthodes
        void afficheDescription();

        //Accesseurs et mutateurs
        short getDegat() const;
};


#endif //CARDGAME_ATTAQUE_H
