//
// Created by bemat on 04/11/2020.
//

#include "../../Headers/Cartes/Attaque.h"

/*
 * Constructeur et destructeur
 */



Attaque::Attaque(int _immatriculation, int _id, std::string _nom, std::string _description, int _domaine, int _degat, std::vector<t_nbPoints>& _nbPoints)
        :Carte(_immatriculation,_id,_nom,_description, _domaine),m_degat(_degat), m_nbPoints(_nbPoints)
{

}

Attaque::~Attaque() {

}

/*
 * Accesseurs et mutateurs
 */


int Attaque::getDegat() const {
    return m_degat;
}

std::vector<t_nbPoints> Attaque::getNbPoints() const{
    return m_nbPoints;
}

/*
 * Méthodes
 */


void Attaque::creer(std::ofstream& fileOutput){
    //implementer ici
}



