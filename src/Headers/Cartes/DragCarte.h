//
// Created by bemat on 26/11/2020.
//

#ifndef CARDGAME_DRAGCARTE_H
#define CARDGAME_DRAGCARTE_H


#include "../Affichage/Affichage.h"
#include "../Collection.h"


class DragCarte : public Affichage{
private:
    int m_imm;
    bool m_actif;
public:
    //Constructeur et destucteur
    DragCarte();
    ~DragCarte();

    //Méthodes

    void afficheCarte(const Collection& _cartesBase);
    void interaction(std::vector<int>& imm);
    //Accessseurs et mutateurs

    bool getActif() const;

    void setActif(bool _actif);
    void setImm(int _imm);

    int getImm() const;

};


#endif //CARDGAME_DRAGCARTE_H
