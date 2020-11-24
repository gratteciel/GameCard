//
// Created by bemat on 24/11/2020.
//

#include "../../Headers/Affichage/Menu.h"

Menu::Menu()
     :Affichage(), m_menuActuel(0), m_boutonActuel("none")
{

}

Menu::~Menu()
{

}

/*
 * Accesseur et mutateur
 */

void Menu::setMenuActuel(int _menuActuel){
    if(_menuActuel>=-1){
        m_menuActuel=_menuActuel;
    }
}

int Menu::getMenuActuel() const{
    return m_menuActuel;
}

void Menu::setBoutonActuel(const std::string& _boutonActuel){
    m_boutonActuel=_boutonActuel;
}

std::string Menu::getBoutonActuel() const{
    return m_boutonActuel;
}

/*
 * Méthodes
 */

void Menu::sfmlMenuBase() {//fonction pour initialiser sfml
    bool fin=false;
    bool leave=false;

    int temp=-2;
    while (!fin) {
        //obliger de le mettre dans la boucle pour réactualiser tout le temps

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)){
            if(getMenuActuel()!=0) {
                sf::sleep(sf::milliseconds(150));
                setMenuActuel(0);
            }
            else
                fin=true;

        }

        getMousePosition();
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();//permet de fermer la fenetre
        }

        if(getMenuActuel()!=temp || getMenuActuel()!=-1){
            temp=getMenuActuel();
            switch(getMenuActuel()){
                case 0:
                    menu0Init();
                    break;
                case 1:
                    menu1Init();
                    break;
                case 2:
                    menu2Init();
                    break;
                case 3:
                    menu3Init();
                    break;
                default:
                    break;
            }
        }

        window.clear();

        //affiche le menu actuel + interaction
        switch(getMenuActuel()){
            case -1:
                sfmlLeave();
                fin=true;
                leave=true;
                break;
            case 0://menu de base
                menu0Affichage();
                menu0Interaction();
                break;
            case 1://menu avec Insciription connection et lancement partie
                menu1Affichage();
                menu1Interaction();
                break;
            case 2:// menu avec les regles
                menu2Affichage();
                menu2Interaction();
                break;
            case 3 : //Parametres
                menu3Affichage();
                menu3Interaction();
                break;
        }

        window.display();

        if(leave)
            sf::sleep(sf::seconds(2));
        else
            sf::sleep(sf::milliseconds(10));
    }

}

void Menu::menu0Init(){
    setPos(1439, 550, "Jouer_no");
    setPos(1439, 550, "Jouer_yes");
    setPos(1418, 700, "Regles_no");
    setPos(1418, 700, "Regles_yes");
    setPos(1400, 850, "Quitter_no");
    setPos(1400, 850, "Quitter_yes");
    setPos(50,900,"Parametres_yes");
    setPos(50,900,"Parametres_no");
}

void Menu::menu0Affichage(){
    afficheImage("Intro");

    if(getBoutonActuel()=="Jouer")
        afficheImage("Jouer_yes");
    else
        afficheImage("Jouer_no");

    if(getBoutonActuel()=="Regles")
        afficheImage("Regles_yes");
    else
        afficheImage("Regles_no");

    if(getBoutonActuel()=="Quitter")
        afficheImage("Quitter_yes");
    else
        afficheImage("Quitter_no");

    if(getBoutonActuel()=="Parametres")
        afficheImage("Parametres_yes");
    else
        afficheImage("Parametres_no");


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

void Menu::menu1Init(){
    setPos(500,500,"connecter_yes");
    setPos(500,500,"connecter_no");
    setPos(714,700,"LancerPartie_no");
    setPos(714,700,"LancerPartie_yes");
    setPos(1020,500,"Inscription_yes");
    setPos(1020,500,"Inscription_no");
    setPos(50,1000,"Retour_no");
    setPos(50,1000,"Retour_yes");

}

void Menu::menu1Affichage() {
    afficheImage("Login");

    if(getBoutonActuel()=="connecter")
        afficheImage("connecter_yes");
    else
        afficheImage("connecter_no");

    if(getBoutonActuel()=="Inscription")
        afficheImage("Inscription_yes");
    else
        afficheImage("Inscription_no");

    if(getBoutonActuel()=="LancerPartie")
        afficheImage("LancerPartie_yes");
    else
        afficheImage("LancerPartie_no");

    if(getBoutonActuel()=="Retour")
        afficheImage("Retour_yes");
    else
        afficheImage("Retour_no");

}

void Menu::menu1Interaction() {

    if (getMousePosition().x < recupSprite("connecter_no").getPosition().x + 391 &&
        getMousePosition().x > recupSprite("connecter_no").getPosition().x &&
        getMousePosition().y < recupSprite("connecter_no").getPosition().y + 35 &&
        getMousePosition().y > recupSprite("connecter_no").getPosition().y) {
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
            sfmlConnection();
        setBoutonActuel("connecter");
    }

    else if (getMousePosition().x < recupSprite("Inscription_no").getPosition().x + 318 &&
             getMousePosition().x > recupSprite("Inscription_no").getPosition().x &&
             getMousePosition().y < recupSprite("Inscription_no").getPosition().y + 35 &&
             getMousePosition().y > recupSprite("Inscription_no").getPosition().y) {
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
            sfmlInscription();
        setBoutonActuel("Inscription");
    }
    else if(getMousePosition().x < recupSprite("Retour_no").getPosition().x + 270 &&
            getMousePosition().x > recupSprite("Retour_no").getPosition().x &&
            getMousePosition().y < recupSprite("Retour_no").getPosition().y + 46 &&
            getMousePosition().y > recupSprite("Retour_no").getPosition().y) {
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)){

            setMenuActuel(0);
            sfmlMenuBase();
        }
        setBoutonActuel("Retour");
    }
    else if(getMousePosition().x < recupSprite("LancerPartie_no").getPosition().x + 492 &&
            getMousePosition().x > recupSprite("LancerPartie_no").getPosition().x &&
            getMousePosition().y < recupSprite("LancerPartie_no").getPosition().y + 35 &&
            getMousePosition().y > recupSprite("LancerPartie_no").getPosition().y){
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)){
            window.clear();

        }
        setBoutonActuel("LancerPartie");

    }
    else
        setBoutonActuel("none");
}

void Menu::menu2Init(){
    setPos(50,1000,"Retour_no");
    setPos(50,1000,"Retour_yes");

}

void Menu::menu2Affichage(){
    afficheImage("Regles");

    if(getBoutonActuel()=="Retour")
        afficheImage("Retour_yes");
    else
        afficheImage("Retour_no");
}

void Menu::menu2Interaction(){
    if(getMousePosition().x < recupSprite("Retour_no").getPosition().x + 270 &&
       getMousePosition().x > recupSprite("Retour_no").getPosition().x &&
       getMousePosition().y < recupSprite("Retour_no").getPosition().y + 46 &&
       getMousePosition().y > recupSprite("Retour_no").getPosition().y) {
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)){

            setMenuActuel(0);
            sfmlMenuBase();
        }
        setBoutonActuel("Retour");
    }
    else
        setBoutonActuel("none");
}

void Menu::sfmlLeave() {
    afficheImage("Leave");
}

void Menu::menu3Init() {
    setPos(700,500,"Inscription_yes");// correspond à créer une carte
    setPos(700,500,"Inscription_no");// correspond à créer une carte
    setPos(50,1000,"Retour_no");
    setPos(50,1000,"Retour_yes");

}

void Menu::menu3Affichage() {
    afficheImage("Intro");

    if(getBoutonActuel()=="Inscription")
        afficheImage("Inscription_yes");
    else
        afficheImage("Inscription_no");

    if(getBoutonActuel()=="Retour")
        afficheImage("Retour_yes");
    else
        afficheImage("Retour_no");

}

void Menu::menu3Interaction() {
    if (getMousePosition().x<(recupSprite("Inscription_no").getPosition().x + 318) && getMousePosition().x>(
            recupSprite("Inscription_no").getPosition().x) &&
        getMousePosition().y<(recupSprite("Inscription_no").getPosition().y + 35) && getMousePosition().y>(
                recupSprite("Inscription_no").getPosition().y)) {
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
            creerUneCarte();
        setBoutonActuel("Inscription");
    }
    else if (getMousePosition().x < recupSprite("Retour_no").getPosition().x + 270 &&
             getMousePosition().x > recupSprite("Retour_no").getPosition().x &&
             getMousePosition().y < recupSprite("Retour_no").getPosition().y + 46 &&
             getMousePosition().y > recupSprite("Retour_no").getPosition().y) {
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)){

            setMenuActuel(0);
            sfmlMenuBase();
        }
        setBoutonActuel("Retour");
    }
    else
        setBoutonActuel("none");


}

void Menu::creerUneCarte() {

}

void Menu::sfmlInscription() {

}

void Menu::sfmlConnection() {

}

