//
// Created by bemat on 04/11/2020.
//

#ifndef CARDGAME_ATTAQUE_H
#define CARDGAME_ATTAQUE_H

#include "../../biblio.h"
#include "Carte.h"

typedef struct t_nbPoints{
    int domaine;
    int nbPoints;
}t_nbPoints;


//Hérite de Carte : nom et description
class Attaque : public Carte{
    private:
        int m_degat;
        //Nombre de point demandés d'énergie pour lancer l'attaque
        std::vector<t_nbPoints> m_nbPoints;

    public:
        //Constructeur et destructeur
        Attaque(int _immatriculation, int _id, std::string _nom, std::string _description, int _domaine, int _degat, std::vector<t_nbPoints>& _nbPoints);
        ~Attaque();
        //Méthodes
        void creer(std::ofstream& fileOutput);
        //Accesseurs et mutateurs
        int getDegat() const;
        std::vector<t_nbPoints> getNbPoints() const;
};


#endif //CARDGAME_ATTAQUE_H
