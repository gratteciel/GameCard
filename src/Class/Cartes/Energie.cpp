//
// Created by bemat on 03/11/2020.
//

#include "../../Headers/Cartes/Energie.h"

/*
 * Constructeur et destructeur
 */

//Constructeur pour le chargement des cartes au début du jeu
Energie::Energie(int _immatriculation, int _id, std::string _nom, std::string _description, int _domaine, int _domaine2)
        : Carte(_immatriculation,_id,_nom,_description,_domaine), m_domaine2(_domaine2)

{

}

Energie::~Energie() {

}

/*
 * Accesseurs et mutateurs
 */

int Energie::getDomaine2() const {
    return m_domaine2;
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

void Energie::affiche(float x, float y){

    Carte::ajoutCarteDescription(x,y);

    sf::Text texte;
    Affichage::setPos(x,y, "Energie");
    Affichage::afficheImage("Energie");


    if(getDomaine2()==getDomaine()){
        sf::Text texte = Affichage::chargerTexte("2", 1, sf::Color::White,30, x+30, y+100, sf::Color::Black, 1);
        Affichage::getWindow().draw(texte);
        Carte::affiche(x+20,y);
    }

    else{
        Carte::affiche(x-30,y);
        //Affiche le domaine
        std::string nomFichier = "Energie_"+std::to_string(getDomaine2());
        Affichage::setPos(x+90,y+100,nomFichier);
        Affichage::afficheImage(nomFichier);
    }

}

void Energie::afficheDescription() {
    Carte::afficheDescriptionCarte("Energie");

    std::string nomFichier = "Energie_"+std::to_string(getDomaine2());
    Affichage::setPos(1200,380,nomFichier);
    Affichage::afficheImage(nomFichier);

}
