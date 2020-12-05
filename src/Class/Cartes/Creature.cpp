//
// Created by bemat on 03/11/2020.
//

#include "../../Headers/Cartes/Creature.h"
#include "../../Headers/Affichage/Affichage.h"

/*
 * Constructeur et destructeur
 */

//Constructeur pour le chargement des cartes au début du jeu
Creature::Creature(int _immatriculation, int _id, std::string _nom, std::string _description,int _domaine, int _pdVInitial, std::vector<Attaque*> _attaques)
        :Carte(_immatriculation,_id,_nom,_description,_domaine), m_pdvInitial(_pdVInitial),m_pdv(_pdVInitial), m_vivant(true),m_attaques(_attaques)

{

}


Creature::~Creature() {

}

/*
 * Accesseurs et mutateurs
 */

int Creature::getPdv() const {
    return m_pdv;
}

void Creature::setPdv(int _pdv) {
    if(_pdv <=0)
        setVivant(false);
    else
        m_pdv = _pdv;
}

int Creature::getPdvInitial() const {
    return m_pdvInitial;
}

bool Creature::getVivant() const {
    return m_vivant;
}

void Creature::setVivant(bool _vivant) {
    m_vivant = _vivant;
}


std::vector<Attaque*> Creature::getAttaques() {
    return m_attaques;
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
    fileOutput << std::endl << std::to_string(getImmatriculation()) <<"*" << getNom() <<"*" << getDescription() << "*" << std::to_string(getDomaine()) << "*"<<std::to_string(getPdvInitial()) << "*" << std::to_string(getAttaques()[0]->getImmatriculation()) << " " <<std::to_string(getAttaques()[1]->getImmatriculation()) << "*" ;

}

void Creature::affiche(float x, float y)
{
    Carte::ajoutCarteDescription(x,y);

    sf::Text texte;
    Affichage::setPos(x,y, "Creature");
    Affichage::afficheImage("Creature");

    //Afiche le nom
    texte=Affichage::chargerTexte(getNom(),1,sf::Color::White,19,x+30,y+43);
    Affichage::getWindow().draw(texte);

    //Affiche les pdv
    texte=Affichage::chargerTexte(std::to_string(getPdv()),1,sf::Color::White,20,x+50,y+165);
    Affichage::getWindow().draw(texte);

    Carte::affiche(x,y);
}

void Creature::afficheDescription(){
    Carte::afficheDescriptionCarte("Creature");

    afficheDescriptionHerited();
    for(int i=0; i<2; i++){
        int xBase =490 +460*i;
        int yBase = 470;
        afficheDegat(xBase,yBase,i);
    }

}

void Creature::afficheDescriptionHerited(){
    //Afiche le nom
    sf::Text texte=Affichage::chargerTexte("Nom :",1,sf::Color(43,43,43,255),40,530,320,sf::Color::Black,1);
    Affichage::getWindow().draw(texte);
    texte=Affichage::chargerTexte(getNom(),1,sf::Color(233,233,233,255),40,680,320,sf::Color::Black,1);
    Affichage::getWindow().draw(texte);

    for(int i=0; i<2; i++){
        int xBase =490 +460*i;
        int yBase = 470;

        afficheAttaqueImage(xBase,yBase);

        afficheAttaqueNom(xBase,yBase,i);
        afficheAttaqueConsommation(xBase,yBase,i);

    }

}



void Creature::afficheAttaques(const int& _terrainActuel){
    for(int i=0 ; i<getAttaques().size(); i++){
        afficheAttaqueDeBase(i,_terrainActuel);
    }
}


void Creature::afficheAttaqueDeBase(int i, const int& _terrainActuel){
    sf::Text tempTexte;
    int xBase =400 +650*i;
    int yBase = 800;

    afficheAttaqueImage(xBase,yBase);
    afficheAttaqueNom(xBase,yBase,i);

    afficheDegat(xBase,yBase,i);

    if(getDomaine()==_terrainActuel){ //Si domaine == terrainActuel alors buffer de 5 de dégat
        tempTexte=Affichage::chargerTexte("+ 5",1,sf::Color::White,20,xBase+170,yBase+100,sf::Color::Black,1);
        Affichage::getWindow().draw(tempTexte);
    }

    afficheAttaqueConsommation(xBase,yBase,i);
}

void Creature::afficheAttaqueImage(int xBase, int yBase){
    //Affiche le rectangle d'attaque
    Affichage::setPos(xBase, yBase, "afficheAttaque");
    Affichage::afficheImage("afficheAttaque");
}

void Creature::afficheAttaqueNom(int xBase, int yBase, int i){


    sf::Text tempTexte;
    //Affiche le nom
    tempTexte=Affichage::chargerTexte("Nom de l'attaque :",1,sf::Color(198,27,27),30,xBase+30,yBase +10,sf::Color::Black,2);
    Affichage::getWindow().draw(tempTexte);
    tempTexte=Affichage::chargerTexte(getAttaques()[i]->getNom(),1,sf::Color::White,20,xBase+30,yBase +50,sf::Color::Black,1);
    Affichage::getWindow().draw(tempTexte);
}

void Creature::afficheAttaqueConsommation(int xBase, int yBase, int i){
    sf::Text tempTexte;
    //Affiche la consommation
    tempTexte=Affichage::chargerTexte("Consommation :",1,sf::Color(198,27,27),30,xBase+30,yBase +150,sf::Color::Black,2);
    Affichage::getWindow().draw(tempTexte);

    int domainesDiff=0;
    for(int j=0 ; j<4; j++){
        int nbPoints = getAttaques()[i]->getNbPoints()[j].nbPoints;


        if(nbPoints>0){


            sf::Text texte=Affichage::chargerTexte(std::to_string(nbPoints),1,sf::Color::White, 30,xBase+70+60*domainesDiff,yBase+190);

            std::string temp="Energie_" + std::to_string(j);
            Affichage::setPos(xBase+70+60*domainesDiff-30, yBase+190, temp);
            Affichage::afficheImage(temp);
            Affichage::getWindow().draw(texte);
            domainesDiff++;
        }
    }
}

void Creature::afficheDegat(int xBase,int yBase,int i){
    sf::Text tempTexte;
    //Affiche les dégats
    tempTexte=Affichage::chargerTexte("Degat : " ,1,sf::Color(198,27,27),20,xBase+30,yBase+100,sf::Color::Black,1);
    Affichage::getWindow().draw(tempTexte);

    tempTexte=Affichage::chargerTexte(std::to_string(getAttaques()[i]->getDegat()),1,sf::Color::White,20,xBase+130,yBase+100,sf::Color::Black,1);
    Affichage::getWindow().draw(tempTexte);


}