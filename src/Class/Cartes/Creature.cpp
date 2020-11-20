//
// Created by bemat on 03/11/2020.
//

#include "../../Headers/Cartes/Creature.h"

/*
 * Constructeur et destructeur
 */

//Constructeur pour le chargement des cartes au début du jeu
Creature::Creature(int _immatriculation, int _id, std::string _nom, std::string _description, int _pdVInitial)
        : Carte(_immatriculation,_id,_nom,_description), m_pdvInitial(_pdVInitial),m_pdv(_pdVInitial), m_vivant(true)

{

}

//Constructeur pour la copie d'une carte en fonction de la collection de carte dans le jeu
Creature::Creature(int _immatriculation, int _id, std::vector<int> _cartesBase)
         : Carte(_immatriculation, _id), m_vivant(true)

{

}

Creature::~Creature() {

}

/*
 * Accesseurs et mutateurs
 */

short Creature::getPdv() const {
    return m_pdv;
}

void Creature::setPdv(short _pdv) {
    if(_pdv <=0)
        setVivant(false);
    else if(_pdv>getPdvInitial()) //si erreur
        m_pdv = getPdvInitial();
    else
        m_pdv = _pdv;
}

short Creature::getPdvInitial() const {
    return m_pdvInitial;
}

bool Creature::getVivant() const {
    return m_vivant;
}

void Creature::setVivant(bool _vivant) {
    m_vivant = _vivant;
}

/*
 * Méthodes
 */



/*
 * Permet d'ajouter une carte Creature dans le jeu:
 *  ajout dans le fichier creatures.txt
 */
void Creature::creer(std::ofstream& fileOutput){
    // Ajout dans le fichier creature
    fileOutput << std::endl << std::to_string(getImmatriculation()) <<"*" << getNom() <<"*" << getDescription() << "*" << std::to_string(getPdvInitial()) << "*";

}

