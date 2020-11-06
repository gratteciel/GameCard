//
// Created by bemat on 03/11/2020.
//

#include "../../Headers/Cartes/Energie.h"

/*
 * Constructeur et destructeur
 */

Energie::Energie(int _immatriculation)
        :Carte(_immatriculation)
{


}

Energie::~Energie() {

}

/*
 * Accesseurs et mutateurs
 */

short Energie::getDomaine() const{
    return m_domaine;
}


/*
 * Méthodes
 */

void Energie::afficheDescription() {
    std::cout << getDescription() <<std::endl;
}