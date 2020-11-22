//
// Created by mitue on 09/11/2020.
//

#ifndef CARDGAME_AFFICHAGE_H
#define CARDGAME_AFFICHAGE_H
#include "../../biblio.h"



class Affichage {//permet l'affichage sfml
private:

public:
    //Constructeur et Destructeur
    Affichage();
    ~Affichage();

    //Methodes
    void sfml_initialisation();
    void sfml_lancement();
    void sfml_play(std::map <std::string, sf::Texture> &imageMap);
    void sfml_leave(std::map <std::string, sf::Texture> &imageMap);
    void sfml_regles(std::map <std::string, sf::Texture> &imageMap);
    std::map <std::string, sf::Texture> sfml_loadImages();
    sf::Texture sfml_SearchingImages(std::map<std::string, sf::Texture> &imagesMap, std::string _nom);

    //Getter et Setter


};


#endif //CARDGAME_AFFICHAGE_H
