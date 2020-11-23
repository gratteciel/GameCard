//
// Created by mitue on 09/11/2020.
//

#ifndef CARDGAME_AFFICHAGE_H
#define CARDGAME_AFFICHAGE_H
#include "../biblio.h"



class Affichage {//permet l'affichage sfml
private:
    std::map <std::string, sf::Sprite> m_imageMap;
    int m_menuActuel;
    std::string m_boutonActuel;

public:
    //Constructeur et Destructeur
    Affichage();
    ~Affichage();

    //Methodes
    void sfmlMenuBase();
    void sfmlLancement();

    void sfmlLeave();

    void sfmlLoadImages();
    void sfmlInscription();
    void sfmlConnection();
    sf::Sprite recupSprite(const std::string& _nom);

    sf::Vector2i getMousePosition()const;
    void chargerImage(const std::string& _nomFichier, const std::string& _posFichier,const std::string& _type);
    sf::Texture* chargerTexture(const std::string& _nomFichier);

    void setPos(float x, float y, const std::string& _nomFichier);

    void afficheImage(const std::string& _nom);

    void menu0Init();
    void menu0Interaction();
    void menu0Affichage();
    void menu1Affichage();
    void menu1Interaction();
    void menu1Init();
    void menu2Affichage();
    void menu2Interaction();
    void menu2Init();
    //Getter et Setter
    void setMenuActuel(int _menuActuel);
    int getMenuActuel() const;
    void setBoutonActuel(const std::string& _boutonActuel);
    std::string getBoutonActuel() const;
};


#endif //CARDGAME_AFFICHAGE_H