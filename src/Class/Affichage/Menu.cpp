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

void Menu::gestionChangementMenu(){
    if(getMenuActuel()>=0&&getMenuActuel()<=3)
        setMenuActuel(0);
    else if(getMenuActuel()==4||getMenuActuel()==5)
        setMenuActuel(1);
}

void Menu::gestionInputCarac(sf::Event& event, std::string& pseudoInscription){
    if (event.text.unicode < 128){
        char carac= (event.text.unicode);
        if((carac >='a' && carac<='z')||(carac >='A' && carac<='Z')){
            if(getMenuActuel()==5){
                //Si le pseudo n'est  pas trop grand
                if(pseudoInscription.size()<=15){
                    pseudoInscription+=carac;
                }
            }
            else
                pseudoInscription="";
        }
    }

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::BackSpace)){
        if(getMenuActuel()==5){
            if(!pseudoInscription.empty()){
                pseudoInscription.pop_back();
            }
        }
        sf::sleep(sf::milliseconds(100));
    }

}

void Menu::sfmlMenuBase() {//fonction pour initialiser sfml
    bool fin=false, leave=false, ancienEchap = false, ancienClick=false;
    std::string pseudoCouleur, pseudoInscripton;
    char caracInput;
    int temp=-2, erreur=-1;

    while (!fin) {
        getMousePosition();//obliger de le mettre dans la boucle pour réactualiser tout le temps
        sf::Event event;

        while (m_window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                m_window.close();//permet de fermer la fenetre

            gestionInputCarac(event,pseudoInscripton);


        }


        if(getMenuActuel()!=temp){
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
                case 4:
                    menu4Init();
                    break;
                default:
                    break;
            }
        }

        m_window.clear();

        //Affichage des menus
        menuBaseAffichage(fin,leave,pseudoCouleur,pseudoInscripton);

        //Si il y a une erreur en cours
        if(erreur>=0){
            Erreur(erreur);
        }
        else {
            //Si on ne reste pas appuyé sur échap
            if(!ancienEchap){
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
                    if (getMenuActuel() != 0) {
                        gestionChangementMenu();
                    } else
                        fin = true;
                }
            }

            //Si on ne reste pas appuyé sur clique gauche
            if(!ancienClick){
                //Interaction des menus
                switch(getMenuActuel()){
                    case 0://menu de base
                        menu0Interaction();
                        break;
                    case 1://menu avec Insciription connection et lancement partie
                        menu1Interaction();
                        break;
                    case 2:// menu avec les regles
                        menu2Interaction();
                        break;
                    case 3 : //Parametres
                        menu3Interaction();
                        break;
                    case 4 : //Connection
                        menu4Interaction(pseudoCouleur, erreur);
                        break;
                    case 5:
                        menu5Interaction();
                        break;
                }
                if(getMenuActuel()==1||getMenuActuel()==4){

                    if(m_jeu.getUsersConnectes().size()>0){

                        interactionPseudoUtilisateurs();
                    }
                }

            }

        }

        m_window.display();

        contrerResterAppuye(ancienClick,ancienEchap);


        if(leave)
            sf::sleep(sf::seconds(2));
        else
            sf::sleep(sf::milliseconds(50));
    }
}




void Menu::contrerResterAppuye(bool& ancienClick, bool& ancienEchap){
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)){
        if(!ancienEchap)
            ancienEchap=true;
    }
    else
        ancienEchap=false;

    if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
        if(!ancienClick)
            ancienClick=true;
    }
    else
        ancienClick=false;

}

void Menu::Erreur(int& erreur){
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
        erreur=-1;
    }
    else{
        afficheImage("Erreur");
        sf::Text texte;
        texte.setPosition(750,530);
        texte.setFont(getFonts()[1]); // choix de la police
        texte.setFillColor(sf::Color(233,233,233,255));//couleur du texte
        texte.setCharacterSize(18); // choix de la taille des caractères exprimée en pixel


        if(erreur==2)
            texte.setString(L"Cet utilisateur est deja connecté!");
        else if(erreur==0)
            texte.setString(L"Il y a deja 2 personnes connectées");
        m_window.draw(texte);
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
    setPos(85,202,"rectInscription");
}


void Menu::menu1Init(){
    setPos(500,500,"connecter_yes");
    setPos(500,500,"connecter_no");
    setPos(1400,1000,"LancerPartie_no");
    setPos(1400,1000,"LancerPartie_yes");
    setPos(1020,500,"Inscription_yes");
    setPos(1020,500,"Inscription_no");
    setPos(50,1000,"Retour_no");
    setPos(50,1000,"Retour_yes");

}


void Menu::menu2Init(){
    setPos(50,1000,"Retour_no");
    setPos(50,1000,"Retour_yes");

}


void Menu::menu3Init() {
    setPos(700,500,"Inscription_yes");// correspond à créer une carte
    setPos(700,500,"Inscription_no");// correspond à créer une carte
    setPos(50,1000,"Retour_no");
    setPos(50,1000,"Retour_yes");
}


void Menu::menu4Init(){
    setPos(150,100,"Rectangle_bois");
    setPos(730,415,"Erreur");
}


