//
// Created by bemat on 30/11/2020.
//

#include "../../Headers/Match/Joueur.h"

void Joueur::afficherSurTerrain(int _ennemieActives, const int& _terrainActuel){
    affichePioche();
    afficheMain(false);
    afficheFinTour();
    afficheNom(false);
    afficheActives(false, _ennemieActives);
    afficheAttaques(_terrainActuel);
    afficheChoixAttaque(_ennemieActives);
    getDrag().afficheCarte(getCartes());
    afficheQuitter();
    afficheDefense(false);
}

void Joueur::afficheModeEnnemie(){
    afficheMain(true);
    getPioche().affiche(true);
    afficheNom(true);
    afficheActives(true);
    afficheDefense(true);

}

void Joueur::afficheActives(bool _ennemie, int _ennemieActives){

    if(m_prop.affichePtsEnergies==0){
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
            else {
                if (getEndroitActu() == ("active" + std::to_string(i))) {

                    sf::Color couleur = sf::Color(255, 255, 255, 50);
                    if(m_prop.numAttaque==66 && m_actives[i].id == m_prop.propChoixAttaquer.id)//Si spéciale reine en trian de choisir qui soigner
                        couleur = sf::Color(255,0,0,60);

                    sf::RectangleShape rectangle;
                    rectangle.setSize(sf::Vector2f(150, 200));
                    rectangle.setFillColor(couleur);
                    rectangle.setPosition(x + 155 * i, y + 350);
                    Affichage::getWindow().draw(rectangle);
                }
            }
        }
        if(!_ennemie){


            for(int i=0; i<_ennemieActives; i++){
                if(getEndroitActu()=="ennemieActives"+std::to_string(i)){
                    sf::RectangleShape rectangle;
                    rectangle.setSize(sf::Vector2f(150, 200));
                    rectangle.setFillColor(sf::Color(255,255,255,50));
                    rectangle.setPosition(x+155*i, y+100);
                    Affichage::getWindow().draw(rectangle);
                }
            }
        }
    }

}

void Joueur::afficheDefense(bool _ennemie){
    if(m_prop.affichePtsEnergies==0){
        if(getDefense()){
            int x= Affichage::recupSprite("Terrain_cartes").getPosition().x+230;
            int y=Affichage::recupSprite("Terrain_cartes").getPosition().y+400;

            if(_ennemie)
                y-=250;

            Affichage::setPos(x-120,y,"bouclier");
            Affichage::afficheImage("bouclier");



        }


    }
}

void Joueur::afficheAttaques(const int& _terrainActuel){
    int tempId = m_prop.propChoixAttaquer.id;

    if(tempId!=-1){


        if(m_prop.numAttaque==-1){

            /*Affiche les 2 attaques*/
            switch(m_prop.propChoixAttaquer.imm/100){
                case 1://Créature
                    for(auto& elem : getCartes().getCreatures()){
                        if(tempId == elem.getId()){
                            elem.afficheAttaques(_terrainActuel);
                        }
                    }
                    break;
                case 2:
                    for(auto& elem : getCartes().getSpeciales()){
                        if(tempId == elem.getId()){
                            elem.afficheAttaques(_terrainActuel);
                        }
                    }
                    break;

            }

            /*AFFICHE LA CARTE PLUS LUMINEUSE SI JAMAIS ON A LE CURSEUR DESSSUS*/
            for(int i=0; i<2; i++){
                if(getEndroitActu()=="attaque"+std::to_string(i)){
                    int xBase =400 +650*i;
                    int yBase = 800;
                    sf::RectangleShape rectangle;
                    rectangle.setSize(sf::Vector2f(453-18, 241-18));
                    rectangle.setFillColor(sf::Color(255,255,255,40));
                    rectangle.setPosition(xBase+9, yBase+9);
                    Affichage::getWindow().draw(rectangle);
                }
            }
            /*Affichage d'un bouton retour*/
            std::string retour = "RETOUR";
            sf::Color couleur = sf::Color::White;
            if(getEndroitActu()=="RETOUR")
                couleur = sf::Color(230,213,23);
            for(int i=0; i<retour.size(); i++){
                sf::Text texte=Affichage::chargerTexte("",1,couleur,30,940,830+30*i,sf::Color::Black,1);
                texte.setString(retour[i]);
                Affichage::getWindow().draw(texte);
            }




        }
        else{
            /*Affichage d'un bouton retour*/
            sf::Color couleur = sf::Color::White;
            if(getEndroitActu()=="RETOUR1")
                couleur = sf::Color(230,213,23);

            sf::Text texte=Affichage::chargerTexte("RETOUR",1,couleur,30,900,900,sf::Color::Black,1);
            Affichage::getWindow().draw(texte);


        }




    }


}

void Joueur::afficheChoixAttaque(int _ennemieActives){
    if(m_prop.propChoixAttaquer.id!=-1 && m_prop.numAttaque!=-1){


        int x= Affichage::recupSprite("Terrain_cartes").getPosition().x+230;
        int y=Affichage::recupSprite("Terrain_cartes").getPosition().y+100;

        if(m_prop.numAttaque==66)
            y+=250;

        if(m_prop.numAttaque==66)//Si spéciale reine attaque (soigne)
            _ennemieActives=getActives().size();


        if(getClignotage()>=30&&_ennemieActives>0){
            sf::RectangleShape rectangle;
            rectangle.setSize(sf::Vector2f(150*_ennemieActives+30, 230));
            rectangle.setFillColor(sf::Color::Transparent);
            rectangle.setOutlineColor(sf::Color(255,215,0));
            rectangle.setOutlineThickness(10);
            rectangle.setPosition(x-15, y-15);
            Affichage::getWindow().draw(rectangle);
        }


    }
}

void Joueur::affichePioche(){

    if(getPioche().getCartes().size()>0){ //Si il y a des cartes dans la pioche
        if((!m_prop.aPioche&& getMain().size()<5)||m_prop.doitRepiocher){
            if(getClignotage()>=30&&m_prop.affichePtsEnergies==0){
                sf::RectangleShape rectangle;
                rectangle.setSize(sf::Vector2f(230, 270));
                rectangle.setFillColor(sf::Color::Transparent);
                rectangle.setOutlineColor(sf::Color(255,215,0));
                rectangle.setOutlineThickness(10);
                rectangle.setPosition(1650, 770);
                Affichage::getWindow().draw(rectangle);
            }

        }

        getPioche().affiche(false,getEndroitActu());
    }

}

void Joueur::afficheMain(bool _ennemie){

    if(m_prop.propChoixAttaquer.id==-1){//si est en train de choisir son attaque / attaquer
        for(int i=0; i<getMain().size(); i++){
            auto elem=getMain()[i];

            if(_ennemie)
            {
                Affichage::setPos(580+155*i,5,"Face_cache_no");
                Affichage::afficheImage("Face_cache_no");
            }

            else{
                if(!getDrag().getActif() || getDrag().getId()!=elem.id){
                    Affichage::afficheCarte(getCartes(),elem.imm,580+155*i,850, elem.id);
                }

            }
        }
    }

}



void Joueur::afficheFinTour(){
    sf::Text texte= Affichage::chargerTexte("Fin du tour", 1, sf::Color(79,210,30,255), 40, 1600, 700,sf::Color::Black, 2);
    if(getEndroitActu()=="finPioche")
        texte.setFillColor(sf::Color(198,27,27));

    Affichage::getWindow().draw(texte);

}

void Joueur::afficheQuitter(){

    if(getQuitter()==0){
        sf::Text texte= Affichage::chargerTexte("Quitter", 1, sf::Color(198,27,27), 40, 20, 700,sf::Color::Black, 2);
        if(getEndroitActu()=="quitter")
            texte.setFillColor(sf::Color(79,210,30,255));

        Affichage::getWindow().draw(texte);
    }
    else if(getQuitter()==1){
        Affichage::setPos(733,419,"afficheAttaque");
        Affichage::afficheImage("afficheAttaque");
        sf::Text texte= Affichage::chargerTexte("Etes-vous sur de quitter?", 1, sf::Color::White, 20, 763, 450,sf::Color::Black, 2);
        Affichage::getWindow().draw(texte);

        texte=Affichage::chargerTexte("Si vous quittez, rien ne sera", 1, sf::Color::White, 20, 753, 510,sf::Color::Black, 1);
        Affichage::getWindow().draw(texte);


        texte=Affichage::chargerTexte("sauvegarde!", 1, sf::Color::White, 20, 753, 540,sf::Color::Black, 1);
        Affichage::getWindow().draw(texte);

        texte= Affichage::chargerTexte("Quitter", 1, sf::Color(198,27,27), 30, 763, 600,sf::Color::Black, 2);
        if(getEndroitActu()=="quitter")
            texte.setFillColor(sf::Color(79,210,30,255));

        Affichage::getWindow().draw(texte);

        texte= Affichage::chargerTexte("Annuler", 1, sf::Color(198,27,27), 30, 1000, 600,sf::Color::Black, 2);
        if(getEndroitActu()=="annuler")
            texte.setFillColor(sf::Color(79,210,30,255));

        Affichage::getWindow().draw(texte);


    }


}


void Joueur::afficheNom(bool ennemie){
    int x=30,y=850, taille=100,posPdv=10;
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
    if(!ennemie){

        std::string texte;
        if(getNbAttaques()!=0)
            texte="action restante";
        else
            texte="actions restantes";

        tempTexte=Affichage::chargerTexte(std::to_string(2-getNbAttaques()),0, sf::Color::Red,45,x+765,y-105+posPdv,sf::Color::Black, 1);
        Affichage::getWindow().draw(tempTexte);
        tempTexte=Affichage::chargerTexte(texte,0, sf::Color::White,45,x+795,y-105+posPdv,sf::Color::Black, 1);
        Affichage::getWindow().draw(tempTexte);
    }
}


void Joueur::affichePtsEnergies(int x, int y, int taille, bool ennemie){

    if(ennemie){
        y-=40;
        taille+=45;
    }
    else{
        taille+=5;
        y+=3;
    }

    sf::Text texte=Affichage::chargerTexte(std::to_string(m_ptEnergie[0]),1,sf::Color::White, 30,x+20,y+taille);

    Affichage::setPos(x-10,y+taille,"Energie_0");
    Affichage::afficheImage("Energie_0");
    Affichage::getWindow().draw(texte);

    texte=Affichage::chargerTexte(std::to_string(m_ptEnergie[1]),1,sf::Color::White, 30,x+80,y+taille);
    Affichage::setPos(x+50,y+taille,"Energie_1");
    Affichage::afficheImage("Energie_1");
    Affichage::getWindow().draw(texte);

    texte=Affichage::chargerTexte(std::to_string(m_ptEnergie[2]),1,sf::Color::White, 30,x+140,y+taille);
    Affichage::setPos(x+110,y+taille,"Energie_2");
    Affichage::afficheImage("Energie_2");
    Affichage::getWindow().draw(texte);

    texte=Affichage::chargerTexte(std::to_string(m_ptEnergie[3]),1,sf::Color::White, 30,x+200,y+taille);
    Affichage::setPos(x+170,y+taille,"Energie_3");
    Affichage::afficheImage("Energie_3");
    Affichage::getWindow().draw(texte);

    if(!ennemie){
        if(m_prop.affichePtsEnergies==0){
            if(getEndroitActu()=="ptsEnergies"){
                sf::RectangleShape rectangle;
                rectangle.setSize(sf::Vector2f(231, 36));
                rectangle.setFillColor(sf::Color(233,233,233,20));
                rectangle.setOutlineColor(sf::Color(255,0,0));
                rectangle.setOutlineThickness(2);
                rectangle.setPosition(x-5, y+taille);
                Affichage::getWindow().draw(rectangle);
            }
        }
        else if(m_prop.affichePtsEnergies==1){
            Affichage::setPos(30,150,"Rectangle_inscription");
            Affichage::afficheImage("Rectangle_inscription");

            texte=Affichage::chargerTexte("Cartes energies posees",1,sf::Color::White, 40,100,300);
            Affichage::getWindow().draw(texte);

            Affichage::setPos(800,700,"Retour_yes");
            Affichage::setPos(800,700,"Retour_no");
            if(getEndroitActu()=="RetourAfficheEnergies")
                Affichage::afficheImage("Retour_yes");
            else
                Affichage::afficheImage("Retour_no");

            for(int i=0; i<m_cartesEnergie.size(); i++){
                Affichage::afficheCarte(getCartes(),m_cartesEnergie[i].imm,100+155*i,400,m_cartesEnergie[i].id);

            }

        }
    }


}