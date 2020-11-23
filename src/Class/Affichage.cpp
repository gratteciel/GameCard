//
// Created by mitue on 09/11/2020.
//

#include "../Headers/Affichage.h"

sf::RenderWindow window(sf::VideoMode(1920, 1080), "GameCard", sf::Style::Fullscreen);//variable globale pour la fenetre afin de l'utiliser dans tous les programmes

/*
 * Constructeur et destructeur
 */

Affichage::Affichage()
        :m_menuActuel(0), m_boutonActuel("none")
{
    sfmlLoadImages();
}

Affichage::~Affichage() {

}

/*
 * Accesseur et mutateur
 */
void Affichage::setMenuActuel(int _menuActuel){
    if(_menuActuel>=-1){
        m_menuActuel=_menuActuel;
    }
}

int Affichage::getMenuActuel() const{
    return m_menuActuel;
}

void Affichage::setBoutonActuel(const std::string& _boutonActuel){
    m_boutonActuel=_boutonActuel;
}

std::string Affichage::getBoutonActuel() const{
    return m_boutonActuel;
}

/*
 * Méthodes
 */

sf::Vector2i Affichage::getMousePosition() const {
    return sf::Mouse::getPosition();
}

void Affichage::sfmlLancement(){
    sfmlMenuBase();
}

void Affichage::chargerImage(const std::string& _nomFichier, const std::string& _posFichier,const std::string& _type){
    /** Partie Intro **/
    sf::Texture* img= chargerTexture("../Images/"+_posFichier+"/"+_nomFichier+"."+_type);

    sf::Sprite sprite;
    sprite.setTexture(*img);
    m_imageMap[_nomFichier] = sprite;
}

sf::Texture* Affichage::chargerTexture(const std::string& _nomFichier){
    sf::Texture* text= new (sf::Texture);

    if(!text->loadFromFile(_nomFichier)){
        std::cout << "Probleme ouverture fichier "<< _nomFichier << std::endl;
    }
    return text;
}

void Affichage::setPos(float x, float y, const std::string& _nomFichier){
    auto it=m_imageMap.find(_nomFichier);
    if(it!=m_imageMap.end()){
        //Set la position du sprite
        it->second.setPosition(x,y);
    }
}

void Affichage::sfmlLoadImages() {
    chargerImage("connecter_no", "Bouton", "png");
    chargerImage("Inscription_no", "Bouton", "png");
    chargerImage("Jouer_no", "Bouton", "png");
    chargerImage("Quitter_no", "Bouton", "png");
    chargerImage("Retour_no", "Bouton", "png");
    chargerImage("Regles_no", "Bouton", "png");

    chargerImage("connecter_yes", "Bouton", "png");
    chargerImage("Inscription_yes", "Bouton", "png");
    chargerImage("Jouer_yes", "Bouton", "png");
    chargerImage("Quitter_yes", "Bouton", "png");
    chargerImage("Retour_yes", "Bouton", "png");
    chargerImage("Regles_yes", "Bouton", "png");

    chargerImage("Intro", "Intro","jpg");
    chargerImage("Login", "Play/Login","jpg");
    chargerImage("Fire", "Play/Terrain","jpg");
    chargerImage("Water", "Play/Terrain","jpg");
    chargerImage("Electric","Play/Terrain","jpg");
    chargerImage("Nature","Play/Terrain","jpg");
    chargerImage("Regles", "Regles","jpg");
    chargerImage("Leave", "Quitter","jpg");
}

void Affichage::afficheImage(const std::string& _nom){
    window.draw(recupSprite(_nom));
}

sf::Sprite Affichage::recupSprite(const std::string& _nom){
    auto it=m_imageMap.find(_nom);
    if(it!=m_imageMap.end())
        return it->second;
}

void Affichage::sfmlMenuBase() {//fonction pour initialiser sfml
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
            case 0:
                menu0Affichage();
                menu0Interaction();
                break;
            case 1:
                menu1Affichage();
                menu1Interaction();
                break;
            case 2:
                menu2Affichage();
                menu2Interaction();
                break;
        }

        window.display();

        if(leave)
            sf::sleep(sf::seconds(2));
        else
            sf::sleep(sf::milliseconds(10));
    }

}

void Affichage::menu0Init(){
    setPos(1439, 550, "Jouer_no");
    setPos(1439, 550, "Jouer_yes");
    setPos(1418, 700, "Regles_no");
    setPos(1418, 700, "Regles_yes");
    setPos(1400, 850, "Quitter_no");
    setPos(1400, 850, "Quitter_yes");
}

void Affichage::menu0Interaction(){

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
    else
        setBoutonActuel("none");


}

void Affichage::menu0Affichage(){
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


}

void Affichage::menu1Init(){
    setPos(500,500,"connecter_yes");
    setPos(500,500,"connecter_no");
    setPos(1020,500,"Inscription_yes");
    setPos(1020,500,"Inscription_no");

}

void Affichage::menu1Affichage() {
    afficheImage("Login");

    if(getBoutonActuel()=="connecter")
        afficheImage("connecter_yes");
    else
        afficheImage("connecter_no");

    if(getBoutonActuel()=="Inscription")
        afficheImage("Inscription_yes");
    else
        afficheImage("Inscription_no");


}

void Affichage::menu1Interaction() {


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
    else
        setBoutonActuel("none");
}

void Affichage::menu2Init(){

}

void Affichage::menu2Interaction(){
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
        //ajouteur ici
    }

}

void Affichage::menu2Affichage(){
    afficheImage("Regles");
    //bouton retour
}

void Affichage::sfmlLeave() {
    afficheImage("Leave");
}

void Affichage::sfmlInscription() {

}

void Affichage::sfmlConnection() {

}
