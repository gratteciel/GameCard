//
// Created by bemat on 30/11/2020.
//

#include "../../Headers/Match/Joueur.h"

void Joueur::afficherSurTerrain(){

    affichePioche();
    afficheMain(false);
    afficheFinTour();
    afficheNom(false);
    afficheActives(false);
    afficheCimetiere();
    getDrag().afficheCarte(getCartes());
}

void Joueur::afficheModeEnnemie(){
    afficheMain(true);
    getPioche().affiche(true);
    afficheNom(true);
    afficheActives(true);
}

void Joueur::afficheActives(bool _ennemie){
    int x= Affichage::recupSprite("Terrain_cartes").getPosition().x+230;
    int y=Affichage::recupSprite("Terrain_cartes").getPosition().y;

    if(_ennemie)
        y=Affichage::recupSprite("Terrain_cartes").getPosition().y-250;

    for(int i=0; i<m_actives.size(); i++){
        auto elem = m_actives[i];
        Affichage::afficheCarte(getCartes(), elem.imm, x+155*i,y+350, elem.id);
        if(_ennemie){
            sf::RectangleShape rectangle;
            rectangle.setSize(sf::Vector2f(150, 200));
            rectangle.setFillColor(sf::Color(255,0,0,30));
            rectangle.setOutlineColor(sf::Color(255,0,0,200));
            rectangle.setOutlineThickness(2);
            rectangle.setPosition(x+155*i, y+350);
            Affichage::getWindow().draw(rectangle);
        }

    }
}

void Joueur::affichePioche(){

    if(getPioche().getCartes().size()>0){ //Si il y a des cartes dans la pioche
        if(!m_prop.aPioche&& getMain().size()<5){
            if(getClignotage()>=30){
                sf::RectangleShape rectangle;
                rectangle.setSize(sf::Vector2f(230, 270));
                rectangle.setFillColor(sf::Color::Transparent);
                rectangle.setOutlineColor(sf::Color(255,215,0));
                rectangle.setOutlineThickness(10);
                rectangle.setPosition(1650, 770);
                Affichage::getWindow().draw(rectangle);

                if(getClignotage()>=50)
                    setClignotage(0);
            }
            setClignotage(getClignotage()+1);
        }

        getPioche().affiche(false,getEndroitActu());
    }

}

void Joueur::afficheMain(bool _ennemie){

    for(int i=0; i<getMain().size(); i++){
        auto elem=getMain()[i];

        if(_ennemie)
        {
            Affichage::setPos(580+155*i,5,"Face_cache_no");
            Affichage::afficheImage("Face_cache_no");
        }

        else{
            if(!getDrag().getActif() || getDrag().getId()!=elem.id) //Si pas actuellement en train de se faire bouger
                Affichage::afficheCarte(getCartes(),elem.imm,580+155*i,850, elem.id);
        }
    }
}

void Joueur::afficheCimetiere(){
    if(m_cimetiere.size()>0){
        sf::Text texte=Affichage::chargerTexte("Cimetiere", 1, sf::Color::Red,20, 1740, 500, sf::Color::Black, 1);
        texte.setString(L"Cimetière");


        for(int i=0; i<m_cimetiere.size(); i++){
            auto elem=m_cimetiere[i];
            Affichage::afficheCarte(getCartes(),elem.imm,1725-2*i,300-2*i, elem.id);

            sf::RectangleShape rectangle;
            rectangle.setSize(sf::Vector2f(150, 200));
            rectangle.setFillColor(sf::Color(255,0,100,80));
            rectangle.setPosition(1725-2*i, 300-2*i);
            Affichage::getWindow().draw(rectangle);
        }

        Affichage::getWindow().draw(texte);
    }
}

void Joueur::afficheFinTour(){
    sf::Text texte= Affichage::chargerTexte("Fin du tour", 1, sf::Color(79,210,30,255), 40, 1600, 700,sf::Color::Black, 2);
    if(getEndroitActu()=="finPioche")
        texte.setFillColor(sf::Color(198,27,27));

    Affichage::getWindow().draw(texte);

}



void Joueur::afficheNom(bool ennemie){
    int x=50,y=850, taille=100,posPdv=0;
    if(ennemie){
        x=1600;
        y=30;
        taille=65;
        posPdv=-35;
    }

    sf::Text tempTexte=Affichage::chargerTexte(getUser()->getPseudo(),0, sf::Color::White,taille,x,y,sf::Color::Black, 1);
    Affichage::getWindow().draw(tempTexte);

    tempTexte=Affichage::chargerTexte("PDV : ",0, sf::Color::White,30,x,y+140+posPdv,sf::Color::Black, 1);
    Affichage::getWindow().draw(tempTexte);
    tempTexte=Affichage::chargerTexte(std::to_string(getPdv()),0, sf::Color::Red,30,x+60,y+140+posPdv,sf::Color::Black, 1);
    Affichage::getWindow().draw(tempTexte);


    affichePtsEnergies(x,y, taille, ennemie);

}


void Joueur::affichePtsEnergies(int x, int y, int taille, bool ennemie){

    if(ennemie){
        y-=40;
        taille+=45;
    }
    else
        taille+=5;

    sf::Text texte=Affichage::chargerTexte(std::to_string(m_ptEnergie[0]),1,sf::Color::White, 30,x+20,y+taille);

    Affichage::setPos(x-10,y+taille,"Energie_feu");
    Affichage::afficheImage("Energie_feu");
    Affichage::getWindow().draw(texte);

    texte=Affichage::chargerTexte(std::to_string(m_ptEnergie[1]),1,sf::Color::White, 30,x+80,y+taille);
    Affichage::setPos(x+50,y+taille,"Energie_eau");
    Affichage::afficheImage("Energie_eau");
    Affichage::getWindow().draw(texte);

    texte=Affichage::chargerTexte(std::to_string(m_ptEnergie[2]),1,sf::Color::White, 30,x+140,y+taille);
    Affichage::setPos(x+110,y+taille,"Energie_electrique");
    Affichage::afficheImage("Energie_electrique");
    Affichage::getWindow().draw(texte);

    texte=Affichage::chargerTexte(std::to_string(m_ptEnergie[3]),1,sf::Color::White, 30,x+200,y+taille);
    Affichage::setPos(x+170,y+taille,"Energie_nature");
    Affichage::afficheImage("Energie_nature");
    Affichage::getWindow().draw(texte);

}