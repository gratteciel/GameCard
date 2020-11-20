//
// Created by bemat on 03/11/2020.
//

#include "../../Headers/Cartes/Energie.h"

/*
 * Constructeur et destructeur
 */

//Constructeur pour le chargement des cartes au début du jeu
Energie::Energie(int _immatriculation, int _id, std::string _nom, std::string _description, char _domaine)
        : Carte(_immatriculation,_id,_nom,_description),  m_domaine(_domaine)

{

}

//Constructeur pour la copie d'une carte en fonction de la collection de carte dans le jeu
Energie::Energie(int _immatriculation, int _id,  std::vector<int> _cartesBase)
        :Carte(_immatriculation,_id)
{


}

Energie::~Energie() {

}

/*
 * Accesseurs et mutateurs
 */

char Energie::getDomaine() const{
    return m_domaine;
}


/*
 * Méthodes
 */



/*
 * Permet d'ajouter une carte Energie dans le jeu:
 *  ajout dans le fichier energies.txt
 */
void Energie::creer(std::ofstream& fileOutput){
    // Ajout dans le fichier energie
    fileOutput << std::endl << std::to_string(getImmatriculation()) <<"*" << getNom() <<"*" << getDescription() << "*" << getDomaine() << "*";
}