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
Energie::Energie(int _immatriculation)
        :Carte(_immatriculation)
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

void Energie::afficheDescription() {
    std::cout << getDescription() <<std::endl;
}