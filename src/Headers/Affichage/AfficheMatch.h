//
// Created by bemat on 24/11/2020.
//

#ifndef CARDGAME_AFFICHEMATCH_H
#define CARDGAME_AFFICHEMATCH_H

#include "Affichage.h"

class AfficheMatch : public Affichage{
private:
    int m_typeTerrain;

public:
    //Constructeur et Destructeurs
    AfficheMatch();
    ~AfficheMatch();
    //Methodes
    void LancementPartieAffichage();
    void AnimationDebutDeCombat();
    void AffichageTerrain();

    //Getter et Setter
    int getTypeTerrain() const;
    void setTypeTerrain(int _typeTerrain);



};


#endif //CARDGAME_AFFICHEMATCH_H