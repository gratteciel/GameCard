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
    void sfml_initialisation();
    void sfml_lancement();
    void sfml_play();
    void sfml_leave();
    void sfml_regles();
    void sfml_loadImages();
    sf::Sprite sfml_SearchingImages(std::string _nom);

    //Getter et Setter
    std::map <std::string, sf::Sprite> getImageMap() const;


};


#endif //CARDGAME_AFFICHAGE_H
