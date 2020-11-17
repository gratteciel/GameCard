//
// Created by bemat on 04/11/2020.
//

#ifndef CARDGAME_ATTAQUE_H
#define CARDGAME_ATTAQUE_H

#include "../../biblio.h"
#include "Carte.h"

//Hérite de Carte : nom et description
class Attaque : public Carte{
    private:
        int m_degat;
        //Nombre de point demandés d'énergie pour lancer l'attaque
        std::vector<std::vector<short> > m_nbPoints;
    public:
        //Constructeur et destructeur
        Attaque(int _immatriculation);
        ~Attaque();
        //Méthodes
        void afficheDescription();
        void creer(std::ofstream& fileOutput);
        //Accesseurs et mutateurs
        short getDegat() const;
};


#endif //CARDGAME_ATTAQUE_H
