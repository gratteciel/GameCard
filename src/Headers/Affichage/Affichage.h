//
// Created by mitue on 09/11/2020.
//

#ifndef CARDGAME_AFFICHAGE_H
#define CARDGAME_AFFICHAGE_H
#include "../../biblio.h"


class Affichage {//permet l'affichage sfml
protected:
    static sf::RenderWindow m_window;
    static std::map <std::string, sf::Sprite> m_imageMap;
    static std::vector<sf::Font> m_fonts;
public:

    //Constructeur et Destructeur
    Affichage();
    ~Affichage();

    //Méthodes
    static void sfmlLoadImages();
    sf::Sprite recupSprite(const std::string& _nom);
    static void chargerImage(const std::string& _nomFichier, const std::string& _posFichier,const std::string& _type);
    static sf::Texture* chargerTexture(const std::string& _nomFichier);
    static void setPos(float x, float y, const std::string& _nomFichier);
    void afficheImage(const std::string& _nom);
    void chargementFonts();
    //Getter et Setter
    sf::Vector2i getMousePosition() const;
    std::vector<sf::Font>& getFonts();


};


#endif //CARDGAME_AFFICHAGE_H