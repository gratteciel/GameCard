//
// Created by bemat on 03/11/2020.
//

#include "../../Headers/Cartes/Energie.h"

/*
 * Constructeur et destructeur
 */

Energie::Energie(std::string _nom, std::string _descritpion, short _domaine)
        :Carte(_nom, _descritpion), m_domaine(_domaine)
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