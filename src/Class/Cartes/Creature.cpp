//
// Created by bemat on 03/11/2020.
//

#include "../../Headers/Cartes/Creature.h"

/*
 * Constructeur et destructeur
 */

Creature::Creature(int _immatriculation)
         : Carte(_immatriculation)

{

}

Creature::~Creature() {

}

/*
 * Accesseurs et mutateurs
 */

short Creature::getPdv() const {
    return m_pdv;
}

void Creature::setPdv(short _pdv) {
    if(_pdv <=0)
        setVivant(false);
    else if(_pdv>getPdvInitial()) //si erreur
        m_pdv = getPdvInitial();
    else
        m_pdv = _pdv;
}

short Creature::getPdvInitial() const {
    return m_pdvInitial;
}

bool Creature::getVivant() const {
    return m_vivant;
}

void Creature::setVivant(bool _vivant) {
    m_vivant = _vivant;
}

/*
 * Méthodes
 */

void Creature::afficheDescription() {
    std::cout << getDescription() <<std::endl;
}