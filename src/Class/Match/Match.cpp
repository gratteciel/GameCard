//
// Created by mitue on 07/11/2020.
//

#include "../../Headers/Match/Match.h"

Match::Match()

{

}



void Match::setJoueur(Utilisateur *_user, int numDeck) {
    m_joueur.push_back(Joueur(_user,numDeck));
}


Match::~Match() {

}

void Match::lancementmatch(Utilisateur *_user1, int numDeck1, Utilisateur *_user2, int numDeck2, const Collection& _cartesBase) {
    m_cartesBase = _cartesBase;
    setJoueur(_user1,numDeck1);
    setJoueur(_user2,numDeck2);
    m_joueur[0].chargerCartes(m_cartesBase);
    m_joueur[1].chargerCartes(m_cartesBase);

}

Plateau Match::getPlateau() const {
    return m_plateau;
}