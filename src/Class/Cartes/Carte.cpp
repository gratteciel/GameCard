//
// Created by bemat on 03/11/2020.
//

#include "../../Headers/Cartes/Carte.h"
#include "../../Headers/Affichage/Affichage.h"

/*
 * Constructeur et destructeur
 */

Carte::Carte(int _immatriculation, int _id, std::string _nom, std::string _description, int _domaine)
        :m_immatriculation(_immatriculation), m_id(_id), m_nom(_nom), m_description(_description), m_domaine(_domaine)
{

}

Carte::Carte(int _immatriculation, int _id)
      :m_immatriculation(_immatriculation), m_id(_id)
{

}

Carte::~Carte() {

}

/*
 * Accesseurs et mutateurs
 */

std::string Carte::getNom() const{
    return m_nom;
}


std::string Carte::getDescription() const{
    return m_description;
}

int Carte::getId() const{
    return m_id;
}

int Carte::getImmatriculation() const{
    return m_immatriculation;
}

int Carte::getDomaine() const {
    return m_domaine;
}

/*
 * Méthodes
 */

void Carte::affiche(float x, float y){

    /*Affiche le domaine*/
    std::string nomFichier = "Energie_"+std::to_string(getDomaine());
    Affichage::setPos(x+50,y+100,nomFichier);
    Affichage::afficheImage(nomFichier);
}


void Carte::ajoutCarteDescription(float x, float y){
    /* On ajoute la carte au vecteur de toutes les cartes */
    t_posCartes temp;
    temp.imm=getImmatriculation();
    temp.x=x;
    temp.y=y;
    Affichage::getPosCartes().push_back(temp);
}

void Carte::afficheDescriptionCarte(const std::string& _type) {
    sf::Text texte;

    Affichage::afficheImage("Terrain_cartes");

    //Afiche "Carte Type"
    texte=Affichage::chargerTexte("Carte",1,sf::Color(233,233,233),60,630,250,sf::Color::Black,1);
    Affichage::getWindow().draw(texte);
    texte=Affichage::chargerTexte(_type,1,sf::Color(198,27,27),60,880,250,sf::Color::Black,1);
    Affichage::getWindow().draw(texte);

    //Affiche sa description
    texte=Affichage::chargerTexte("Description :",1,sf::Color(43,43,43,255),40,480,370,sf::Color::Black,1);
    Affichage::getWindow().draw(texte);
    texte=Affichage::chargerTexte(getDescription(),1,sf::Color(233,233,233,255),20,470,415,sf::Color::Black,1);
    Affichage::getWindow().draw(texte);

    //Affiche le type
    texte=Affichage::chargerTexte("Type :",1,sf::Color(43,43,43,255),40,1000,370,sf::Color::Black,1);
    Affichage::getWindow().draw(texte);

    std::string nomFichier = "Energie_"+std::to_string(getDomaine());
    Affichage::setPos(1150,380,nomFichier);
    Affichage::afficheImage(nomFichier);

}