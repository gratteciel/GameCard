//
// Created by bemat on 04/11/2020.
//

#include "../../Headers/Cartes/Attaque.h"

/*
 * Constructeur et destructeur
 */



Attaque::Attaque(int _immatriculation)
        :Carte(_immatriculation)
{

}

Attaque::~Attaque() {

}

/*
 * Accesseurs et mutateurs
 */


short Attaque::getDegat() const {
    return m_degat;
}

/*
 * Méthodes
 */


void Attaque::creer(std::ofstream& fileOutput){
    //implementer ici
}


