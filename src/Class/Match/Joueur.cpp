//
// Created by bemat on 05/11/2020.
//

#include "../../Headers/Match/Joueur.h"

/*
 * Constructeur et destructeur
 */

Joueur::Joueur(Utilisateur *_user)
       :m_user(_user), m_pdv(100)
{

}

Joueur::~Joueur(){

  delete m_user;
}

/*
 * Accesseurs et mutateurs
 */


int Joueur::getPdv() const {
    return m_pdv;
}
Utilisateur* Joueur::getUser() const {
    return m_user;
}

void Joueur::setPioche(const Collection& _cartesBase){
    m_pioche.chargerPioche(getUser()->getDeck(getUser()->getDeckActif()).getCartes(),_cartesBase);

}

/*
 * Méthodes
 */




