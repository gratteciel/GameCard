//
// Created by bemat on 24/11/2020.
//

#include "../../Headers/Affichage/AfficheMatch.h"

//Constructeur et Destructeur
AfficheMatch::AfficheMatch()
        :m_typeTerrain(1)
{

}

AfficheMatch::~AfficheMatch() {

}

void AfficheMatch::AnimationDebutDeCombat(){
    AffichageTerrain();
    sf::Text texteDebutDeCombat;
    texteDebutDeCombat.setFont(getFonts()[1]);
    texteDebutDeCombat.setPosition(325,475);
    texteDebutDeCombat.setFillColor(sf::Color::White);
    texteDebutDeCombat.setCharacterSize(90); // choix de la taille des caractères exprimée en pixel
    texteDebutDeCombat.setOutlineColor(sf::Color::Black); // Couleur du contour
    texteDebutDeCombat.setOutlineThickness(1); //Taille des contours
    texteDebutDeCombat.setString("Le Combat Commence !");
    m_window.draw(texteDebutDeCombat);
    m_window.display();
    sf::sleep(sf::seconds(2));
    m_window.clear();

}

void AfficheMatch::LancementPartieAffichage() {//pourquoi obligatoire le static?


    AnimationDebutDeCombat();

    while (!sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)){
        m_window.clear();
        AffichageTerrain();
        m_window.display();
        sf::sleep(sf::milliseconds(10));

    }


}

void AfficheMatch::AffichageTerrain(){


    switch (getTypeTerrain()) {
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

void AfficheMatch::setTypeTerrain(int _typeTerrain) {
    if(_typeTerrain>0)
        m_typeTerrain=_typeTerrain;
    else
        std::cout << "Numero du terrain invalide" << std::endl;
}
int AfficheMatch::getTypeTerrain() const {
    return m_typeTerrain;
}