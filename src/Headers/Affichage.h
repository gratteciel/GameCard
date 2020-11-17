//
// Created by mitue on 09/11/2020.
//

#ifndef CARDGAME_AFFICHAGE_H
#define CARDGAME_AFFICHAGE_H
#include "../biblio.h"


class Affichage {//permet l'affichage sfml
private:

public:
    //Constructeur et Destructeur
    Affichage();
    ~Affichage();

    //Methodes
    void sfml_initialisation();
    void sfml_lancement();
    void sfml_loadImages();
    void sfml_play();

    //Getter et Setter


};


#endif //CARDGAME_AFFICHAGE_H
