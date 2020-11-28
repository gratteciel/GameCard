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

void DragCarte::interaction(std::vector<int>& imm){
    /*SI DRAG & DROP ACTIF*/
    if(getActif()){
        //Si plus appuyé sur le bouton de la souris
        if(!sf::Mouse::isButtonPressed(sf::Mouse::Left)){
            setActif(false); //On arrete le drag & drop

            if(imm.size()<=10){ //Si il y a moins de 11 cartes
                //Si le curseur est dans le deck du joueur
                if(getMousePosition().x>=(recupSprite("Rectangle_deck").getPosition().x) && getMousePosition().x<=(
                        recupSprite("Rectangle_deck").getPosition().x + 1900) &&
                   getMousePosition().y>=(recupSprite("Rectangle_deck").getPosition().y) && getMousePosition().y<=(
                        recupSprite("Rectangle_deck").getPosition().y+220)){
                    imm.push_back(getImm()); //ON AJOUTE LA CARTE AU DECK INSCRIPITON
                }
            }

        }

    }
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


void DragCarte::setImm(int _imm){
    if(_imm>=100 && _imm<=399)
        m_imm=_imm;
}

int DragCarte::getImm() const{
    return m_imm;
}
