//
// Created by mitue on 07/11/2020.
//

#include "../../Headers/Match/Match.h"

/*
 * Constructeur et destructeur
 */

Match::Match()

{

}

Match::~Match() {

}

/*
 * Accesseurs et mutateurs
 */

void Match::setJoueur(Utilisateur *_user) {
    m_joueur.push_back(Joueur(_user));
}

Plateau Match::getPlateau() const {
    return m_plateau;
}

/*
 * Méthodes
 */


void Match::lancementMatch(Utilisateur *_user1, Utilisateur *_user2, const Collection& _cartesBase) {

    setJoueur(_user1);
    setJoueur(_user2);

    m_joueur[0].setPioche(_cartesBase);
    m_joueur[1].setPioche(_cartesBase);
}

