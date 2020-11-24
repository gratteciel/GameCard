//
// Created by mitue on 09/11/2020.
//

#ifndef CARDGAME_AFFICHAGE_H
#define CARDGAME_AFFICHAGE_H
#include "../../biblio.h"

extern sf::RenderWindow window;
extern std::map <std::string, sf::Sprite> imageMap;

class Affichage {//permet l'affichage sfml
public:

    //Constructeur et Destructeur
    Affichage();
    ~Affichage();

    //Méthodes
    void sfmlLoadImages();
    sf::Sprite recupSprite(const std::string& _nom);
    void chargerImage(const std::string& _nomFichier, const std::string& _posFichier,const std::string& _type);
    sf::Texture* chargerTexture(const std::string& _nomFichier);
    void setPos(float x, float y, const std::string& _nomFichier);
    void afficheImage(const std::string& _nom);

    //Getter et Setter
    sf::Vector2i getMousePosition() const;



};


#endif //CARDGAME_AFFICHAGE_H