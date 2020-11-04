//
// Created by bemat on 03/11/2020.
//

#include "../../Headers/Cartes/Carte.h"

/*
 * Constructeur et destructeur
 */

Carte::Carte(std::string _nom, std::string _description)
      :m_nom(_nom), m_description(_description)
{

}

Carte::~Carte() {

}

/*
 * Accesseurs et mutateurs
 */

std::string Carte::getNom() const{
    return m_nom;
}


std::string Carte::getDescription() const{
    return m_description;
}




