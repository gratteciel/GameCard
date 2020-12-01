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

void Speciale::affiche(float x, float y){

    sf::Text texte;
    Affichage::setPos(x,y, "Speciale");//changer ici pour les spéciales
    Affichage::afficheImage("Speciale");//changer ici pour les spéciales

    //Afiche le nom
    texte=Affichage::chargerTexte(getNom(),1,sf::Color::White,19,x+30,y+43);
    Affichage::getWindow().draw(texte);

    //Affiche l'immatriculation
    texte=Affichage::chargerTexte(std::to_string(getImmatriculation()),1,sf::Color::White,20,x+50,y+165);
    Affichage::getWindow().draw(texte);
}