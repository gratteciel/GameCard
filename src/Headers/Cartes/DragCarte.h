//
// Created by bemat on 26/11/2020.
//

#ifndef CARDGAME_DRAGCARTE_H
#define CARDGAME_DRAGCARTE_H


#include "../Affichage/Affichage.h"
#include "../Collection.h"
#include "../Cartes/DragCarte.h"


class DragCarte{
private:
    int m_id;
    int m_imm;

    bool m_actif;
public:
    //Constructeur et destucteur
    DragCarte();
    ~DragCarte();

    //Méthodes

    void afficheCarte(const Collection& _cartesBase);
    int interaction(int x1, int y1,int x2, int y2);
    //Accessseurs et mutateurs

    bool getActif() const;

    void setActif(bool _actif);
    void setId(int _id);

    int getId() const;
    void setImm(int _imm);

    int getImm() const;

};


#endif //CARDGAME_DRAGCARTE_H
