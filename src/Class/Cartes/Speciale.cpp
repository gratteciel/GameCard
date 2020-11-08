//
// Created by bemat on 07/11/2020.
//

#include "../../Headers/Cartes/Speciale.h"

/*
 * Constructeur et destructeur
 */

Speciale::Speciale(int _immatriculation, int _id, std::string _nom, std::string _description)
        : Carte(_immatriculation,_id,_nom,_description)

{

}

Speciale::Speciale(int _immatriculation)
         : Carte(_immatriculation)

{

}

Speciale::~Speciale() {

}



/*
 * Accesseurs et mutateurs
 */

/*
 * Méthodes
 */

void Speciale::afficheDescription() {
    std::cout << getDescription() <<std::endl;
}



