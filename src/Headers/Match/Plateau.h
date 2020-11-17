//
// Created by mitue on 07/11/2020.
//

#ifndef CARDGAME_PLATEAU_H
#define CARDGAME_PLATEAU_H



#include "../../../biblio.h"
#include "Pioche.h"


class Plateau {
private:
    Pioche m_pioche;
public:
    //Constructeurs et Destructeurs
    Plateau();
    ~Plateau();
    //Methodes
    void affichageplateau();
    //Getters et Setters
};


#endif //CARDGAME_PLATEAU_H
