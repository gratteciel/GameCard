//
// Created by bemat on 03/11/2020.
//

#include "../../Headers/Cartes/Carte.h"

/*
 * Constructeur et destructeur
 */

Carte::Carte(int _id)
      :m_id(_id)
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

int Carte::getId() const{
    return m_id;
}


