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
}


int AfficheMatch::boucleMatch(){
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)){ //POUR L'INSTANT
        m_match.getJoueurs().clear();
        return 1;
    }
    affichageTerrain();
    afficheEnjeux();
    m_match.getJoueurEnnemie().afficheModeEnnemie();
    m_match.getJoueur().afficherSurTerrain();
    m_match.interaction();
    return 0;
}


void AfficheMatch::affichageTerrain(){
    switch (m_match.getTypeTerrain()) {
        case 1 :
            afficheImage("imageFond");
            break;
        case 2:
            afficheImage("Nature");
            break;
        case 3:
            afficheImage("Electric");
            break;
        case 4:
            afficheImage("Water");
            break;
        case 5:
            afficheImage("Fire");
    }

    afficheImage("Terrain_cartes");
}

void AfficheMatch::afficheEnjeux(){
    sf::Text texte=chargerTexte("Enjeux", 1, sf::Color::White,20, 70, 700, sf::Color::Black, 1);
    for(int i=0; i<2; i++){
        setPos(50-10*i, 500-10*i,"Face_cache_no");
        afficheImage("Face_cache_no");
    }
    m_window.draw(texte);
}

