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
    else if(getMenuActuel()==4)
        setMenuActuel(1);
}

void Menu::sfmlMenuBase() {//fonction pour initialiser sfml
    bool fin=false;
    bool leave=false;
    std::string pseudoCouleur;
    int temp=-2;
    while (!fin) {
        //obliger de le mettre dans la boucle pour réactualiser tout le temps

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)){
            if(getMenuActuel()!=0) {
                sf::sleep(sf::milliseconds(150));
                gestionChangementMenu();
            }
            else
                fin=true;

        }

        getMousePosition();
        sf::Event event;
        while (m_window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                m_window.close();//permet de fermer la fenetre
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
                default:
                    break;
            }
        }

        m_window.clear();

        //affiche le menu actuel + interaction
        switch(getMenuActuel()){
            case -1:
                sfmlLeave();
                fin=true;
                leave=true;
                break;
            case 0://menu de base
                menu0Interaction();
                menu0Affichage();
                break;
            case 1://menu avec Insciription connection et lancement partie
                menu1Interaction();
                menu1Affichage();
                break;
            case 2:// menu avec les regles
                menu2Interaction();
                menu2Affichage();
                break;
            case 3 : //Parametres
                menu3Interaction();
                menu3Affichage();
                break;
            case 4 : //Connexction
                menu4Interaction(pseudoCouleur);
                menu4Affichage(pseudoCouleur);
                break;

        }

        m_window.display();

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
            setMenuActuel(4);
        setBoutonActuel("connecter");
    }

    else if (getMousePosition().x < recupSprite("Inscription_no").getPosition().x + 318 &&
             getMousePosition().x > recupSprite("Inscription_no").getPosition().x &&
             getMousePosition().y < recupSprite("Inscription_no").getPosition().y + 35 &&
             getMousePosition().y > recupSprite("Inscription_no").getPosition().y) {
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)){
            //sfmlInscription();
        }
        setBoutonActuel("Inscription");
    }
    else if(getMousePosition().x < recupSprite("Retour_no").getPosition().x + 270 &&
            getMousePosition().x > recupSprite("Retour_no").getPosition().x &&
            getMousePosition().y < recupSprite("Retour_no").getPosition().y + 46 &&
            getMousePosition().y > recupSprite("Retour_no").getPosition().y) {
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)){

            setMenuActuel(0);

        }
        setBoutonActuel("Retour");
    }
    else if(getMousePosition().x < recupSprite("LancerPartie_no").getPosition().x + 492 &&
            getMousePosition().x > recupSprite("LancerPartie_no").getPosition().x &&
            getMousePosition().y < recupSprite("LancerPartie_no").getPosition().y + 35 &&
            getMousePosition().y > recupSprite("LancerPartie_no").getPosition().y){
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)){
            m_window.clear();

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

        }
        setBoutonActuel("Retour");
    }
    else
        setBoutonActuel("none");


}

void Menu::creerUneCarte() {

}


void Menu::menu4Affichage(const std::string& pseudoCouleur) {
    unsigned short i=0;

    sf::Text _tempTexte;
    _tempTexte.setFont(getFonts()[0]); // choix de la police
    _tempTexte.setFillColor(sf::Color::White);//couleur du texte
    _tempTexte.setCharacterSize(70); // choix de la taille des caractères exprimée en pixel
    _tempTexte.setOutlineColor(sf::Color::Black); // Couleur du contour
    _tempTexte.setOutlineThickness(1); //Taille des contours

    sf::Text texte;
    texte.setPosition(100,100);
    texte.setFont(getFonts()[1]); // choix de la police
    texte.setFillColor(sf::Color::White);//couleur du texte
    texte.setCharacterSize(40); // choix de la taille des caractères exprimée en pixel
    texte.setOutlineColor(sf::Color::Black); // Couleur du contour
    texte.setOutlineThickness(1); //Taille des contours
    texte.setString("LISTE DES PSEUDOS :");


    afficheImage("Login");//Affiche l'image "login"
    m_window.draw(texte);

    for(auto& elem: m_jeu.getUsersPseudo()){

        _tempTexte.setString(elem); //affiche le pseudo

        _tempTexte.setPosition(200,200+70*i);
        if(elem==pseudoCouleur)
            _tempTexte.setFillColor(sf::Color::Red);//couleur du texte
        else
            _tempTexte.setFillColor(sf::Color::White);//couleur du texte
        m_window.draw(_tempTexte);
        i++;
    }

}

void Menu::menu4Interaction(std::string& pseudoCouleur){
    unsigned int i=0;
    bool fin=false;
    for(const auto& elem : m_jeu.getUsersPseudo()){
        if (getMousePosition().x>(200) && getMousePosition().x<(200+elem.size()*24) &&
            getMousePosition().y>(200+70*i) && getMousePosition().y<(200+70*i+70) ){

            pseudoCouleur=elem;
            fin=true;
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left)){
                m_jeu.connectionUser(pseudoCouleur);
                sf::sleep(sf::milliseconds(50));
            }

            break;

        }

        i++;
    }
    if(!fin)
        pseudoCouleur="none";

}