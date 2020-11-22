//
// Created by bemat on 03/11/2020.
//

#include "../../Headers/Cartes/Carte.h"

/*
 * Constructeur et destructeur
 */

Carte::Carte(int _immatriculation, int _id, std::string _nom, std::string _description)
        :m_immatriculation(_immatriculation), m_id(_id), m_nom(_nom), m_description(_description)
{

}

Carte::Carte(int _immatriculation, int _id)
      :m_immatriculation(_immatriculation), m_id(_id)
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

int Carte::getImmatriculation() const{
    return m_immatriculation;
}
