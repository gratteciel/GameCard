//
// Created by bemat on 05/11/2020.
//

#include "../../Headers/Match/Joueur.h"

/*
 * Constructeur et destructeur
 */

Joueur::Joueur(Utilisateur *_user, int _numDeck)
       :m_user(_user), m_numDeck(_numDeck), m_pdv(100)
{

}

Joueur::~Joueur(){

}
/*
 * Accesseurs et mutateurs
 */

int Joueur::getNumDeck() const {
    return m_numDeck;
}
int Joueur::getPdv() const {
    return m_pdv;
}
Utilisateur* Joueur::getUser() const {
    return m_user;
}
void Joueur::setNumDeck(int _numDeck) {
    if(_numDeck>=0)
        m_numDeck=_numDeck;
}

/*
 * Méthodes
 */

void Joueur::chargerCartes(const Collection& _cartesBase){
    m_pioche.chargerPioche(getUser()->getDeck(getNumDeck()).getCartes(),_cartesBase);

}


