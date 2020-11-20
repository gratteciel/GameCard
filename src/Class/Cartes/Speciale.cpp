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

Speciale::Speciale(int _immatriculation, int _id,  std::vector<int> _cartesBase)
         : Carte(_immatriculation,_id)

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


/*
 * Permet d'ajouter une carte Speciale dans le jeu:
 *  ajout dans le fichier speciales.txt
 */
void Speciale::creer(std::ofstream& fileOutput){
    // Ajout dans le fichier energie
    fileOutput << std::endl << std::to_string(getImmatriculation()) <<"*" << getNom() <<"*" << getDescription() << "*";


}

