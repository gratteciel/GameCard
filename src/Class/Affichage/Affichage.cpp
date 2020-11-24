//
// Created by mitue on 09/11/2020.
//

#include "../../Headers/Affichage/Affichage.h"

/*
 * Initialisation des attributs statique
 */

sf::RenderWindow Affichage::m_window(sf::VideoMode(1920, 1080), "GameCard", sf::Style::Fullscreen);//variable globale pour la fenetre afin de l'utiliser dans tous les programmes

std::map <std::string, sf::Sprite> Affichage::m_imageMap;

std::vector<sf::Font> Affichage::m_fonts;
/*
 * Constructeur et destructeur
 */

Affichage::Affichage()

{
    sfmlLoadImages();
    chargementFonts();
}

Affichage::~Affichage() {

}

sf::Vector2i Affichage::getMousePosition() const {
    return sf::Mouse::getPosition();
}

std::vector<sf::Font>& Affichage::getFonts(){
    return m_fonts;
}
/*
 * Méthodes
 */


void Affichage::chargerImage(const std::string& _nomFichier, const std::string& _posFichier,const std::string& _type){
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

    chargerImage("Jouer_no", "Bouton", "png");
    chargerImage("Quitter_no", "Bouton", "png");
    chargerImage("Regles_no", "Bouton", "png");
    chargerImage("Parametres_no","bouton","png");

    chargerImage("connecter_no", "Bouton", "png");
    chargerImage("Inscription_no", "Bouton", "png");
    chargerImage("LancerPartie_no","Bouton","png");

    chargerImage("Retour_no", "Bouton", "png");


    chargerImage("Jouer_yes", "Bouton", "png");
    chargerImage("Quitter_yes", "Bouton", "png");
    chargerImage("Parametres_yes","Bouton","png");
    chargerImage("Regles_yes", "Bouton", "png");

    chargerImage("connecter_yes", "Bouton", "png");
    chargerImage("Inscription_yes", "Bouton", "png");
    chargerImage("LancerPartie_yes","Bouton","png");

    chargerImage("Retour_yes", "Bouton", "png");


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
    m_window.draw(recupSprite(_nom));
}

sf::Sprite Affichage::recupSprite(const std::string& _nom){
    auto it=m_imageMap.find(_nom);
    if(it!=m_imageMap.end())
        return it->second;
}


void Affichage::chargementFonts(){
    sf::Font font;
    if (!font.loadFromFile("../Font/americanCaptain.ttf"))
    {
        std::cout << "Erreur : n'arrive pas à charger le font !" << std::endl;
    }
    else
        m_fonts.push_back(font);

    if (!font.loadFromFile("../Font/distantGalaxy.ttf"))
    {
        std::cout << "Erreur : n'arrive pas à charger le font !" << std::endl;
    }
    else
        m_fonts.push_back(font);
}

