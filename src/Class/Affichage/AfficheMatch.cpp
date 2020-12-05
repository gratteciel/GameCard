//
// Created by bemat on 24/11/2020.
//

#include "../../Headers/Affichage/AfficheMatch.h"

//Constructeur et Destructeur
AfficheMatch::AfficheMatch()
{

}

AfficheMatch::~AfficheMatch() {

}

void AfficheMatch::lancement(Utilisateur *_user1, Utilisateur *_user2,  const Collection& _cartesBase){

    m_match.lancementMatch(_user1, _user2, _cartesBase);

    animationDebutDeCombat();

}

Match& AfficheMatch::getMatch(){
    return m_match;
}

void AfficheMatch::animationDebutDeCombat(){
    affichageTerrain();
    sf::Text texteDebutDeCombat;
    texteDebutDeCombat.setFont(getFonts()[1]);
    texteDebutDeCombat.setPosition(325,475);
    texteDebutDeCombat.setFillColor(sf::Color::White);
    texteDebutDeCombat.setCharacterSize(90); // choix de la taille des caractères exprimée en pixel
    texteDebutDeCombat.setOutlineColor(sf::Color::Black); // Couleur du contour
    texteDebutDeCombat.setOutlineThickness(1); //Taille des contours
    texteDebutDeCombat.setString("Le Combat Commence !");
    m_window.draw(texteDebutDeCombat);
    texteDebutDeCombat.setString(L"Les dekcs sont mélangés et une carte est retirée au hasard !");
    texteDebutDeCombat.setPosition(210,600);
    texteDebutDeCombat.setCharacterSize(35);
    m_window.draw(texteDebutDeCombat);
}



int AfficheMatch::affichage(const Collection& _cartesBase){

    affichageTerrain();
    afficheEnjeux();
    afficheCimetiere(_cartesBase);
    m_match.getJoueurEnnemie().afficheModeEnnemie();
    m_match.getJoueur().afficherSurTerrain(m_match.getJoueurEnnemie().getActives().size(), m_match.getTypeTerrain());

}


void AfficheMatch::affichageTerrain(){
    switch (m_match.getTypeTerrain()) {
        case 5 :
            afficheImage("imageFond");
            break;
        case 3:
            afficheImage("Nature");
            break;
        case 2:
            afficheImage("Electric");
            break;
        case 1:
            afficheImage("Water");
            break;
        case 0:
            afficheImage("Fire");
    }

    afficheImage("Terrain_cartes");
}

void AfficheMatch::afficheEnjeux(){
    sf::Text texte=chargerTexte("Enjeux", 1, sf::Color::White,20, 70, 550, sf::Color::Black, 1);
    for(int i=0; i<2; i++){
        setPos(50-10*i, 350-10*i,"Face_cache_no");
        afficheImage("Face_cache_no");
    }
    m_window.draw(texte);
}


void AfficheMatch::afficheCimetiere(const Collection& _cartesBase){
    std::vector<int> cimetiere = m_match.getCimetiere();
    if(cimetiere.size()>0){
        sf::Text texte=Affichage::chargerTexte("Cimetiere", 1, sf::Color::Red,20, 1740, 500, sf::Color::Black, 1);
        texte.setString(L"Cimetière");


        for(int i=0; i<cimetiere.size(); i++){
            auto elem=cimetiere[i];
            Affichage::afficheCarte(_cartesBase,elem,1725-5*i,300-5*i, elem);

            sf::RectangleShape rectangle;
            rectangle.setSize(sf::Vector2f(150, 200));
            rectangle.setFillColor(sf::Color(255,0,100,80));
            rectangle.setPosition(1725-5*i, 300-5*i);
            Affichage::getWindow().draw(rectangle);
        }

        Affichage::getWindow().draw(texte);
    }
}