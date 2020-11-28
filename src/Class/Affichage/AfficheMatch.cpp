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

void AfficheMatch::boucleMatch(){

    affichageTerrain();
    afficheCaracJoueur();
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


void AfficheMatch::affichageTerrain(){
    switch (m_match.getTypeTerrain()) {
        case 1 :
            afficheImage("AreneDeBase");
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

}

void AfficheMatch::affichePioche(){
    setPos(1700,800,"Face_cache");
    afficheImage("Face_cache");
    std::string nombreCartes = std::to_string(m_match.getJoueur().getPioche().getCartesId().size()) + " cartes";
    m_window.draw(chargerTexte(nombreCartes,1,sf::Color::White,26,1700,1000));

}

void AfficheMatch::afficheMain(){
    for(const auto& elem: m_match.getJoueur().getMain()){
        afficheCarte(m_match.getJoueur().getCartes(),elem.imm,700,800);
    }
}

void AfficheMatch::afficheCaracJoueur(){

    affichePioche();
    m_match.interactionPioche();
    afficheMain();
}