//
// Created by mitue on 09/11/2020.
//

#ifndef CARDGAME_AFFICHAGE_H
#define CARDGAME_AFFICHAGE_H
#include "../../biblio.h"



class Affichage {//permet l'affichage sfml
private:
    std::map <std::string, sf::Sprite> m_imageMap;

public:
    //Constructeur et Destructeur
    Affichage();
    ~Affichage();

    //Methodes
    void sfmlMenuBase();
    void sfmlLancement();
    void sfmlPlay();
    void sfmlLeave();
    void sfmlRegles();
    void sfmlLoadImages();
    sf::Sprite recupSprite(const std::string& _nom);
    void chargerImage(const std::string& _nomFichier, const std::string& _posFichier,const std::string& _type);
    void setPos(int x, int y, const std::string& _nomFichier);
    void afficheImage(const std::string& _nom);

    //Getter et Setter


};


#endif //CARDGAME_AFFICHAGE_H