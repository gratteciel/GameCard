//
// Created by bemat on 07/11/2020.
//

#include "../../Headers/Cartes/Speciale.h"
#include "../../Headers/Affichage/Affichage.h"

/*
 * Constructeur et destructeur
 */

Speciale::Speciale(int _immatriculation, int _id, std::string _nom, std::string _description,int _domaine, int _pdVInitial, std::vector<Attaque*> _attaques, int _type)
        : Creature(_immatriculation,_id,_nom,_description, _domaine, _pdVInitial, _attaques), m_type(_type)

{

}



Speciale::~Speciale() {

}



/*
 * Accesseurs et mutateurs
 */

int Speciale::getType() const{
    return m_type;
}

/*
 * Méthodes
 */


/*
 * Permet d'ajouter une carte Speciale dans le jeu:
 *  ajout dans le fichier speciales.txt
 */
void Speciale::creer(std::ofstream& fileOutput){
    // Ajout dans le fichier energie
    Creature::creer(fileOutput);
    fileOutput << std::to_string(getType()) << "*";
}

void Speciale::affiche(float x, float y){

    Carte::ajoutCarteDescription(x,y);

    sf::Text texte;
    Affichage::setPos(x,y, "Speciale");//changer ici pour les spéciales
    Affichage::afficheImage("Speciale");//changer ici pour les spéciales

    //Afiche le nom
    texte=Affichage::chargerTexte(getNom(),1,sf::Color::White,19,x+30,y+43);
    Affichage::getWindow().draw(texte);

    if(getType()!=2){
        //Affiche les pdv
        texte=Affichage::chargerTexte(std::to_string(getPdv()),1,sf::Color::White,20,x+50,y+165);
        Affichage::getWindow().draw(texte);
        //Affiche le domaine
        Carte::affiche(x-30,y);
    }

    if(getType()!=2){
        //Affiche roi ou renne
        std::string type;
        if(getType()==1)
            type="ROI";
        else if(getType()==0)
            type="Reine";


        texte=Affichage::chargerTexte(type,1,sf::Color::White,20,x+55,y+105);
        Affichage::getWindow().draw(texte);
    }
    else{//SI defense
        Affichage::setPos(x+50, y+90,"bouclier_petit");
        Affichage::afficheImage("bouclier_petit");
    }





}

void Speciale::afficheAttaques(const int& _terrainActuel) {
    //1ere attaque : memme style d'attaque que les créatures
    Creature::afficheAttaqueDeBase(0, _terrainActuel);

    //2eme attaque : attaque spéciale OU soigner
    int xBase =400 +650;
    int yBase = 800;

    Creature::afficheAttaqueImage(xBase,yBase);

    sf::RectangleShape rectangle;
    rectangle.setSize(sf::Vector2f(453-18, 241-18));
    rectangle.setFillColor(sf::Color(240,37,34,50));
    rectangle.setPosition(xBase+9, yBase+9);
    Affichage::getWindow().draw(rectangle);

    Creature::afficheAttaqueNom(xBase,yBase,1);
    Creature::afficheAttaqueConsommation(xBase,yBase,1);

    afficheRoiReineDescription(xBase,yBase);

}

void Speciale::afficheDescription() {
    int xBase =490;
    int yBase = 470;


    if(getType()!=2){ //SI n'est pas de type defense
        Carte::afficheDescriptionCarte("Speciale");
        Creature::afficheDescriptionHerited();

        afficheDegat(xBase,yBase,0);
        xBase+=460;

        afficheRoiReineDescription(xBase,yBase);
    }
    else{ //Si de type defense
        Carte::afficheDescriptionCarte("Speciale2");
        //Afiche le nom
        sf::Text texte=Affichage::chargerTexte("Nom :",1,sf::Color(43,43,43,255),40,530,320,sf::Color::Black,1);
        Affichage::getWindow().draw(texte);
        texte=Affichage::chargerTexte(getNom(),1,sf::Color(233,233,233,255),40,680,320,sf::Color::Black,1);
        Affichage::getWindow().draw(texte);
    }


}

void Speciale::afficheRoiReineDescription(int xBase, int yBase){
    if(getType()==1){ //Si roi
        sf::Text tempTexte=Affichage::chargerTexte("Inflige immediatement 25",1,sf::Color::White,20,xBase+30,yBase+90,sf::Color::Black,1);
        Affichage::getWindow().draw(tempTexte);
        tempTexte=Affichage::chargerTexte("degats aux cartes adverses",1,sf::Color::White,20,xBase+30,yBase+110,sf::Color::Black,1);
        Affichage::getWindow().draw(tempTexte);
    }
    else if(getType()==0){ //si reine
        sf::Text tempTexte=Affichage::chargerTexte("Soigne une carte alliee",1,sf::Color::White,20,xBase+30,yBase+90,sf::Color::Black,1);
        Affichage::getWindow().draw(tempTexte);
        tempTexte=Affichage::chargerTexte("de 30 point de vie",1,sf::Color::White,20,xBase+30,yBase+110,sf::Color::Black,1);
        Affichage::getWindow().draw(tempTexte);
    }
}

