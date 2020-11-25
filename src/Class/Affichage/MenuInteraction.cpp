//
// Created by bemat on 25/11/2020.
//


#include "../../Headers/Affichage/Menu.h"


void Menu::interactionPseudoUtilisateurs() {
    unsigned int i=0;
    bool fin=false, decksValides=true;

    for(const auto& elem :m_jeu.getUsersConnectes()){
        if(!elem.second.getDeck(elem.second.getDeckActif()).getDeckActuValide())
            decksValides=false;

        if (getMousePosition().x>(600+elem.first.size()*40*i) && getMousePosition().x<(600+elem.first.size()*40*i+elem.first.size()*24) && getMousePosition().y>(970) && getMousePosition().y<(970+70) ){
            fin=true;
            setBoutonActuel(elem.first);

            if (sf::Mouse::isButtonPressed(sf::Mouse::Left)){
                //implementer
            }
            break;
        }
        i++;
    }


   if(!fin){
       //Si 2 personnes connectées et leurs decks sont valides
       std::string bouton= getBoutonActuel();
       if(m_jeu.getUsersConnectes().size()==2 && decksValides)
       {
           if(getMousePosition().x < recupSprite("LancerPartie_no").getPosition().x + 492 &&
              getMousePosition().x > recupSprite("LancerPartie_no").getPosition().x &&
              getMousePosition().y < recupSprite("LancerPartie_no").getPosition().y + 35 &&
              getMousePosition().y > recupSprite("LancerPartie_no").getPosition().y){


               if (sf::Mouse::isButtonPressed(sf::Mouse::Left)){//lancer le match
                   m_window.clear();
                   m_affichageMatch.LancementPartieAffichage();
               }
               setBoutonActuel("LancerPartie");
           }
           else if(bouton!="connecter" && bouton!="Retour" && bouton !="Inscription")
               setBoutonActuel("none");
       }
   }
}



void Menu::menu0Interaction(){

    if (getMousePosition().x<(recupSprite("Jouer_no").getPosition().x + 162) && getMousePosition().x>(
            recupSprite("Jouer_no").getPosition().x) &&
        getMousePosition().y<(recupSprite("Jouer_no").getPosition().y + 43) && getMousePosition().y>(
                recupSprite("Jouer_no").getPosition().y)) {
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
            setMenuActuel(1);
        setBoutonActuel("Jouer");
    }

    else if ((getMousePosition().x<(recupSprite("Regles_no").getPosition().x + 204) && getMousePosition().x>(
            recupSprite("Regles_no").getPosition().x)) &&
             (getMousePosition().y<(recupSprite("Regles_no").getPosition().y + 36) && getMousePosition().y>(
                     recupSprite("Regles_no").getPosition().y))) {
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
            setMenuActuel(2);
        setBoutonActuel("Regles");
    }

    else if (getMousePosition().x<
            (recupSprite("Quitter_no").getPosition().x + 240) && getMousePosition().x>(
            recupSprite("Quitter_no").getPosition().x) &&
             getMousePosition().y<(recupSprite("Quitter_no").getPosition().y + 46) && getMousePosition().y>(
                     recupSprite("Quitter_no").getPosition().y)) {
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
            setMenuActuel(-1);
        setBoutonActuel("Quitter");
    }
    else if (getMousePosition().x<
            (recupSprite("Parametres_no").getPosition().x + 236) && getMousePosition().x>(
            recupSprite("Parametres_no").getPosition().x) &&
             getMousePosition().y<(recupSprite("Parametres_no").getPosition().y + 29) && getMousePosition().y>(
                     recupSprite("Parametres_no").getPosition().y)) {
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)){
            setMenuActuel(3);
        }
        setBoutonActuel("Parametres");
    }
    else
        setBoutonActuel("none");


}

void Menu::menu1Interaction() {

    if (getMousePosition().x < recupSprite("connecter_no").getPosition().x + 391 &&
        getMousePosition().x > recupSprite("connecter_no").getPosition().x &&
        getMousePosition().y < recupSprite("connecter_no").getPosition().y + 35 &&
        getMousePosition().y > recupSprite("connecter_no").getPosition().y) {
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
            setMenuActuel(4);
        setBoutonActuel("connecter");
    }

    else if (getMousePosition().x < recupSprite("Inscription_no").getPosition().x + 318 &&
             getMousePosition().x > recupSprite("Inscription_no").getPosition().x &&
             getMousePosition().y < recupSprite("Inscription_no").getPosition().y + 35 &&
             getMousePosition().y > recupSprite("Inscription_no").getPosition().y) {
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)){
            setMenuActuel(5);
        }
        setBoutonActuel("Inscription");
    }
    else if(btnRetourInteraction()){
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)){
            setMenuActuel(0);
        }
    }

    else
        setBoutonActuel("none");
}

void Menu::menu2Interaction(){
    if(btnRetourInteraction()){
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)){
            setMenuActuel(0);
        }
    }
    else
        setBoutonActuel("none");
}

void Menu::menu3Interaction() {
    if (getMousePosition().x<(recupSprite("Inscription_no").getPosition().x + 318) && getMousePosition().x>(
            recupSprite("Inscription_no").getPosition().x) &&
        getMousePosition().y<(recupSprite("Inscription_no").getPosition().y + 35) && getMousePosition().y>(
                recupSprite("Inscription_no").getPosition().y)) {
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)){

        }

        setBoutonActuel("Inscription");
    }
    else if(btnRetourInteraction()){
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)){
            setMenuActuel(0);
        }
    }

    else
        setBoutonActuel("none");


}

void Menu::menu4Interaction(std::string& pseudoCouleur, int& erreur){
    unsigned int i=0;
    bool fin=false;

    if(btnRetourInteraction()){
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)){
            setMenuActuel(1);
        }
    }
    else
        setBoutonActuel("none");

    for(const auto& elem : m_jeu.getUsersPseudo()){
        if (getMousePosition().x>(200) && getMousePosition().x<(200+elem.size()*24) &&
                                                               getMousePosition().y>(200+70*i) && getMousePosition().y<(200+70*i+70) ){
            pseudoCouleur=elem;
            fin=true;
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left)){
                int x = m_jeu.connectionUser(pseudoCouleur);

                if(x==0||x==2)
                    erreur=x;
            }
            break;
        }
        i++;
    }
    if(!fin)
        pseudoCouleur="none";

}

void Menu::menu5Interaction() {
    if(btnRetourInteraction()){
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)){
            setMenuActuel(1);
        }
    }
    else
        setBoutonActuel("none");




}

bool Menu::btnRetourInteraction(){
    //Interaction pour le bouton retour
    if(getMousePosition().x < recupSprite("Retour_no").getPosition().x + 270 &&
       getMousePosition().x > recupSprite("Retour_no").getPosition().x &&
       getMousePosition().y < recupSprite("Retour_no").getPosition().y + 46 &&
       getMousePosition().y > recupSprite("Retour_no").getPosition().y) {

        setBoutonActuel("Retour");
        return true;
    }
    return false;
}