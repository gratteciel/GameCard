//
// Created by bemat on 26/11/2020.
//

#include "../../Headers/Cartes/DragCarte.h"

/*
 * Constructeur et destructeur
 */

DragCarte::DragCarte()
         :m_actif(false)
{


}

DragCarte::~DragCarte() {

}


/*
 * Méthodes
 */

int DragCarte::interaction(int x1, int y1, int x2, int y2){
    /*SI DRAG & DROP ACTIF*/
    if(getActif()){
        //Si plus appuyé sur le bouton de la souris
        if(!sf::Mouse::isButtonPressed(sf::Mouse::Left)){
            setActif(false); //On arrete le drag & drop


                //Si le curseur est dans le deck du joueur
                if(Affichage::getMousePosition().x>=x1 && Affichage::getMousePosition().x<=x1 + x2 &&
                        Affichage::getMousePosition().y>=y1 && Affichage::getMousePosition().y<=y1+y2){
                    return getId();
                }


        }

    }
    return 666;
}


void DragCarte::afficheCarte(const Collection &_cartesBase) {
    if(getActif()){
        Affichage::afficheCarte(_cartesBase, getImm(),Affichage::getMousePosition().x-75, Affichage::getMousePosition().y-100,getId());
    } //Si le drag & drop est actif

}


/*
 * Accesseurs et mutateurs
 */



bool DragCarte::getActif() const{
    return m_actif;
}

void DragCarte::setActif(bool _actif){
    m_actif=_actif;
}


void DragCarte::setId(int _id){
    m_id=_id;
}

int DragCarte::getId() const{
    return m_id;
}

void DragCarte::setImm(int _imm){
    m_imm=_imm;
}

int DragCarte::getImm() const{
    return m_imm;
}