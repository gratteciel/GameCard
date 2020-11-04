//
// Created by bemat on 04/11/2020.
//

#include "../../Headers/Cartes/Attaque.h"

/*
 * Constructeur et destructeur
 */



Attaque::Attaque(std::string _nom, std::string _description, short _degat)
        :Carte(_nom, _description), m_degat(_degat)
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

void Attaque::afficheDescription() {
    std::cout << getDescription() <<std::endl;
}


