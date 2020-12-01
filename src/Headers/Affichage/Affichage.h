//
// Created by mitue on 09/11/2020.
//

#ifndef CARDGAME_AFFICHAGE_H
#define CARDGAME_AFFICHAGE_H
#include "../../biblio.h"
#include "../../Headers/Cartes/Creature.h"
#include "../../Headers/Collection.h"

typedef struct t_posCartes{
    int x;
    int y;
    int imm;
}t_posCartes;

class Collection;
class Affichage {//permet l'affichage sfml
protected:
    static sf::RenderWindow m_window;
    static std::map <std::string, sf::Sprite> m_imageMap;
    static std::vector<sf::Font> m_fonts;
    static std::vector<t_posCartes> m_posCartes;
public:

    //Constructeur et Destructeur
    Affichage();
    ~Affichage();

    //Méthodes
    void sfmlLoadImages();
    void initialisationPos();
    static sf::Sprite recupSprite(const std::string& _nom);
    void chargerImage(const std::string& _nomFichier, const std::string& _posFichier,const std::string& _type);
    sf::Texture* chargerTexture(const std::string& _nomFichier);
    static void setPos(float x, float y, const std::string& _nomFichier);
    static void afficheImage(const std::string& _nom);
    void chargementFonts();
    void chargerFont(const std::string& _nom);
    static sf::Text chargerTexte(const std::string& _textEcrit,int _choixDePolice, sf::Color _couleurTexte,int _tailleCarac, int _x, int _y, sf::Color _couleurContourTexte = sf::Color::White, double _tailleContourTexte=0);
    static void afficheCarte(const Collection& _carteBase, int imm, int x, int y, int i);

    //Getter et Setter
    static sf::Vector2i getMousePosition();
    static std::vector<sf::Font>& getFonts();
    static sf::RenderWindow& getWindow();
    static std::map<std::string, sf::Sprite>& getImageMap();
    static std::vector<t_posCartes>& getPosCartes();
};


#endif //CARDGAME_AFFICHAGE_H