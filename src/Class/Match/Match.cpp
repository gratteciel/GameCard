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

void Match::setTypeTerrain(int _typeTerrain) {
    if(_typeTerrain>=0)
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

Joueur& Match::getJoueurEnnemie(){
    if(getJoueurActuel()==0)
        return m_joueur[1];
    else
        return m_joueur[0];
}

std::vector<Joueur>& Match::getJoueurs(){
    return m_joueur;
}

std::vector<int>& Match::getCimetiere(){
    return m_cimetiere;
}

/*
 * Méthodes
 */

void Match::permuterJoueur(){
    if(getJoueurActuel()==0)
        setJoueurActuel(1);
    else
        setJoueurActuel(0);
    getJoueur().initiatlisationProp();
}

void Match::lancementMatch(Utilisateur *_user1, Utilisateur *_user2, const Collection& _cartesBase) {

    setJoueur(_user1);

    setJoueur(_user2);
    m_joueur[0].setPioche(_cartesBase);
    m_joueur[1].setPioche(_cartesBase);
    setJoueurActuel(0);
    getJoueur().initiatlisationProp();
    setTypeTerrain(5);
}



int Match::interaction(){
    int temp = getTypeTerrain();

    int returnInteraction = getJoueur().interaction(getJoueurEnnemie(),getCimetiere(),temp);

    if(returnInteraction==1){ //Changement de tour
        permuterJoueur();
        return 1;
    }//Si fin de tour du joueurActuel

    else if(returnInteraction==2){//QUITTER
        getJoueurs().clear(); //On efface les joueurs
        getCimetiere().clear();//on efface le cimetiere
        return 2;
    }


    if(temp!=getTypeTerrain()){
        setTypeTerrain(temp);
    }
    return 0;
}

