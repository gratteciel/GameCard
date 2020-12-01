//
// Created by bemat on 03/11/2020.
//

#include "../../Headers/Cartes/Energie.h"

/*
 * Constructeur et destructeur
 */

//Constructeur pour le chargement des cartes au début du jeu
Energie::Energie(int _immatriculation, int _id, std::string _nom, std::string _description, int _domaine)
        : Carte(_immatriculation,_id,_nom,_description),  m_domaine(_domaine)

{

}





Energie::~Energie() {

}

/*
 * Accesseurs et mutateurs
 */

int Energie::getDomaine() const{
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

void Energie::affiche(float x, float y){

    sf::Text texte;
    Affichage::setPos(x,y, "Energie");//changer ici pour les energies
    Affichage::afficheImage("Energie");//changer ici pour les energies

    //Afiche le nom
    texte=Affichage::chargerTexte(getNom(),1,sf::Color::White,19,x+30,y+43);
    Affichage::getWindow().draw(texte);

    //Affiche le domaine
    texte=Affichage::chargerTexte(std::to_string(getDomaine()),1,sf::Color::White,20,x+50,y+165);
    Affichage::getWindow().draw(texte);
}