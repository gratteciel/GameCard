//
// Created by bemat on 04/11/2020.
//

#include "../../Headers/Cartes/Deck.h"

/*
 * Constructeur et destructeur
 */
Deck::Deck(bool _tailleConst)
     :m_tailleConst(_tailleConst)
{

}

Deck::~Deck(){

}



/*
 * Accesseurs et mutateurs
 */

bool Deck::getTailleConst() const {
    return m_tailleConst;
}

/*
 * Méthodes
 */

unsigned int Deck::nombreCartes() const {
    //+ m_speciales.size();
    return m_creatures.size() + m_energies.size();
}

 
 