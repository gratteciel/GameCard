//
// Created by bemat on 30/11/2020.
//

#include "../../Headers/Match/Joueur.h"

bool Joueur::interaction(){
    setEtreSurBouton(false);

    if(interactionFinTour())
        return true;

    interactionPioche();
    interactionMain();
    interactionFromMainToActive();

    if(!getEtreSurBouton())
        setEndroitActu("none");

    //Si pas fin de tour
    return false;
}



void Joueur::interactionMain(){
    for(int i=0; i<getMain().size(); i++){
        auto elem=getMain()[i];
        int sourisX=Affichage::getMousePosition().x;
        int sourisY=Affichage::getMousePosition().y;
        if(sourisX>580+155*i && sourisX<(580+155*i+150) &&sourisY>850 && sourisY<(850+200)){
            //Si clique sur la carte
            if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
                /*Initialisation du drag drop*/
                getDrag().setActif(true); //Drag drop actif
                getDrag().setId(elem.id);
                getDrag().setImm(elem.imm);

            }
        }
    }

}


bool Joueur::interactionFinTour(){
    sf::Vector2<int> souris=Affichage::getMousePosition();

    //Si la souris est sur la carte
    if(souris.x>=1600&&souris.x<1920 && souris.y>=700&&souris.y<=740){
        setEndroitActu("finPioche");

        if(sf::Mouse::isButtonPressed(sf::Mouse::Left) && !getDrag().getActif()){
            sf::sleep(sf::milliseconds(200));
            return true;
        }

    }
    return false;

}

void Joueur::interactionPioche(){
    if(getPioche().etreSurLaPioche()){//Si curseur sur la pioche
        setEndroitActu("pioche");
        if(!m_prop.aPioche && getMain().size()<5){//Si n'a pas encore pioché & taille de la main <5

            if(sf::Mouse::isButtonPressed(sf::Mouse::Left))//si appuie sur la pioche
                piocher();
        }
    }
}

void Joueur::interactionFromMainToActive(){
    int x1=Affichage::recupSprite("Terrain_cartes").getPosition().x;
    int y1=Affichage::recupSprite("Terrain_cartes").getPosition().y;

    int tempId=getDrag().interaction(x1,y1,1079,649);



        if(tempId!=666){ //Si posé la carte au bon endoit

            for(int i=0; i<getMain().size(); i++){
                if(getMain()[i].id == tempId){ //On cherche la carte de la main qui correspond à celle qu'on vient de déplacer
                    t_carte temp;
                    temp.id = getMain()[i].id;
                    temp.imm= getMain()[i].imm;

                    if(m_actives.size()<4||(temp.imm>=300&&temp.id<=399)) {//Si moins de 4 cartes dans les cartes actives ou carte énergie
                        switch (temp.imm / 100) {
                            case 1: //Créature
                                m_actives.push_back(temp); //On ajoute la cartes aux actives
                                break;
                            case 2: //Spéciale
                                m_actives.push_back(temp); //On ajoute la cartes aux actives
                                break;
                            case 3://Energie
                                m_cartesEnergie.push_back(temp);
                                m_ptEnergie[temp.imm - 300]++;//On augmente le nombre d'énergie selon le domaine
                                break;

                        }
                        m_main.erase(m_main.begin() + i); //on efface la carte de la main

                    }

                    break;
                }
            }
        }



}