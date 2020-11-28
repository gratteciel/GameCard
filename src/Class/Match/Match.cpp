//
// Created by mitue on 07/11/2020.
//

#include "../../Headers/Match/Match.h"
#include "../../Headers/Affichage/Affichage.h"
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

void Match::setTypeTerrain(int _typeTerrain) {
    if(_typeTerrain>0)
        m_typeTerrain=_typeTerrain;
    else
        std::cout << "Numero du terrain invalide" << std::endl;
}
int Match::getTypeTerrain() const {
    return m_typeTerrain;
}

int Match::getJoueurActuel() const{
    return m_joueurActuel;
}
void Match::setJoueurActuel(int _joueurActuel){
    m_joueurActuel=_joueurActuel;
}

Joueur& Match::getJoueur() {
    return m_joueur[getJoueurActuel()];
}

/*
 * Méthodes
 */


void Match::lancementMatch(Utilisateur *_user1, Utilisateur *_user2, const Collection& _cartesBase) {
    setJoueur(_user1);
    setJoueur(_user2);
    m_joueur[0].setPioche(_cartesBase);
    m_joueur[1].setPioche(_cartesBase);
    setJoueurActuel(0);
    setTypeTerrain(1);
}

void Match::interactionPioche(){


}

