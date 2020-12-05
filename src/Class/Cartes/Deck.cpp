//
// Created by bemat on 04/11/2020.
//

#include "../../Headers/Cartes/Deck.h"

//Nombre de cartes par deck
const unsigned int Deck::m_numCartes = 10;

/*
 * Constructeur et destructeur
 */
Deck::Deck(std::vector<int>& _cartes)
     :m_cartes(_cartes)
{

}

Deck::~Deck(){

}

const unsigned int Deck::getNumCartes()  {
    return Deck::m_numCartes;
}



/*
 * Accesseurs et mutateurs
 */

std::vector<int>& Deck::getCartes(){
    return m_cartes;
}

/*
 * Méthodes
 */

bool Deck::getDeckActuValide(){
    if(getCartes().size()==Deck::getNumCartes())
        return true;
    else
        return false;
}


 
 