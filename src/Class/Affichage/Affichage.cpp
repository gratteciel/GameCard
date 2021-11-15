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

std::vector<t_posCartes> Affichage::m_posCartes;

/*
 * Constructeur et destructeur
 */

Affichage::Affichage()

{
    sfmlLoadImages();
    initialisationPos();
    chargementFonts();
}

Affichage::~Affichage() {
    for(const auto& elem: m_imageMap){
        delete elem.second.getTexture();
    }
}

sf::Vector2i Affichage::getMousePosition(){
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
    chargerImage("Rectangle_inscription", "Play/login", "png");
    chargerImage("Rectangle_deck", "Play/login", "jpg");
    chargerImage("Erreur", "Play/login", "png");
    chargerImage("rectInscription", "Intro", "png");
    chargerImage("Background_utilisateur", "Intro", "png");

    chargerImage("afficheAttaque", "Play/Terrain", "png");



    chargerImage("Creature", "Cartes", "jpg");
    chargerImage("Speciale", "Cartes", "jpg");
    chargerImage("Energie", "Cartes", "jpg");
    chargerImage("Face_cache_no", "Cartes", "jpg");
    chargerImage("Face_cache_yes", "Cartes", "jpg");
    chargerImage("IntroJeu", "Intro", "jpg");
    chargerImage("Terrain_cartes", "Play/Terrain", "png");
    chargerImage("imageFond", "Play/Terrain", "jpg");


    chargerImage("Energie_0", "Cartes", "png");
    chargerImage("Energie_1", "Cartes", "png");
    chargerImage("Energie_2", "Cartes", "png");
    chargerImage("Energie_3", "Cartes", "png");

    chargerImage("changementDeTour", "Play/Terrain", "png");
    chargerImage("bouclier", "Play/Terrain", "png");
    chargerImage("bouclier_petit", "Play/Terrain", "png");

}

void Affichage::initialisationPos(){
    setPos(415,205,"Terrain_cartes");
}


void Affichage::afficheImage(const std::string& _nom){
    m_window.draw(recupSprite(_nom));
}

sf::Sprite Affichage::recupSprite(const std::string& _nom){
    auto it=m_imageMap.find(_nom);
    if(it!=m_imageMap.end())
        return it->second;
}

void Affichage::chargerFont(const std::string& _nom){
    sf::Font font;
    if (!font.loadFromFile("../Font/"+_nom+".ttf"))
    {
        std::cout << "Erreur : n'arrive pas à charger le font !" << std::endl;
    }
    else
        m_fonts.push_back(font);

}

void Affichage::chargementFonts(){
    chargerFont("americanCaptain");
    chargerFont("distantGalaxy");
    chargerFont("scribish");
}

sf::Text Affichage::chargerTexte(const std::string& _textEcrit, int _choixDePolice, sf::Color _couleurTexte,
                                 int _tailleCarac, int _x, int _y, sf::Color _couleurContourTexte,
                                 double _tailleContourTexte) {
    sf::Text _temp;
    _temp.setPosition(_x,_y);
    _temp.setFont(getFonts()[_choixDePolice]);
    _temp.setCharacterSize(_tailleCarac);
    _temp.setOutlineColor(_couleurContourTexte);
    _temp.setOutlineThickness(_tailleContourTexte);
    _temp.setFillColor(_couleurTexte);
    _temp.setString(_textEcrit);

    return _temp;
}



void Affichage::afficheCarte(const Collection& _carteBase, int imm, int x, int y, int id) {
    int type=imm/100;

    switch(type){ //type
        case 1://Créature
            //Si Créature
            for (auto &elem : _carteBase.getCreatures()) {
                if (elem.getId() == id) {//Si meme id
                    elem.affiche(x,y);
                    break;
                }

            }
            break;
        case 2:
            for(auto &elem: _carteBase.getSpeciales()){
                if(elem.getId() == id){
                    elem.affiche(x,y);//faire l'affichage pour les spéciales
                    break;
                }
            }
            break;

        case 3:
            for(auto &elem: _carteBase.getEnergies()){
                if(elem.getId() == id){
                    elem.affiche(x,y);//faire l'affichage pour les spéciales
                    break;
                }
            }
            break;
    }
}



sf::RenderWindow& Affichage::getWindow(){
    return m_window;
}
std::map<std::string, sf::Sprite>& Affichage::getImageMap(){
    return m_imageMap;
}

std::vector<t_posCartes>& Affichage::getPosCartes(){
    return m_posCartes;
}