//
// Created by bemat on 24/11/2020.
//

#include "../../Headers/Affichage/AfficheMatch.h"


void AfficheMatch::AnimationDebutDeCombat(){
    setPos(550,400,"Jouer_no");
    afficheImage("Jouer_no");
    m_window.display();
    sf::sleep(sf::seconds(2));
    m_window.clear();

}
//faire un setter vis a vis de l'élement du terrain

void AfficheMatch::LancementPartieAffichage() {

    AnimationDebutDeCombat();
    while (!sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)){
        m_window.clear();
        AffichageTerrain();

        m_window.display();
        sf::sleep(sf::milliseconds(10));

    }


}

void AfficheMatch::AffichageTerrain(){


}