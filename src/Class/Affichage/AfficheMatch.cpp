//
// Created by bemat on 24/11/2020.
//

#include "../../Headers/Affichage/AfficheMatch.h"

//Constructeur et Destructeur
AfficheMatch::AfficheMatch()
{

}

AfficheMatch::~AfficheMatch() {

}

void AfficheMatch::lancement(Utilisateur *_user1, Utilisateur *_user2,  const Collection& _cartesBase){

    m_match.lancementMatch(_user1, _user2, _cartesBase);

    animationDebutDeCombat();

}

Match& AfficheMatch::getMatch(){
    return m_match;
}

void AfficheMatch::animationDebutDeCombat(){
    affichageTerrain();
    sf::Text texteDebutDeCombat;
    texteDebutDeCombat.setFont(getFonts()[1]);
    texteDebutDeCombat.setPosition(325,475);
    texteDebutDeCombat.setFillColor(sf::Color::White);
    texteDebutDeCombat.setCharacterSize(90); // choix de la taille des caractères exprimée en pixel
    texteDebutDeCombat.setOutlineColor(sf::Color::Black); // Couleur du contour
    texteDebutDeCombat.setOutlineThickness(1); //Taille des contours
    texteDebutDeCombat.setString("Le Combat Commence !");
    m_window.draw(texteDebutDeCombat);
    texteDebutDeCombat.setString(L"Les dekcs sont mélangés et une carte est retirée au hasard !");
    texteDebutDeCombat.setPosition(210,600);
    texteDebutDeCombat.setCharacterSize(35);
    m_window.draw(texteDebutDeCombat);
}



int AfficheMatch::affichage(const Collection& _cartesBase){

    affichageTerrain();
    afficheEnjeux();
    afficheCimetiere(_cartesBase);
    m_match.getJoueurEnnemie().afficheModeEnnemie();
    m_match.getJoueur().afficherSurTerrain(m_match.getJoueurEnnemie().getActives().size(), m_match.getTypeTerrain());

}


void AfficheMatch::affichageTerrain(){
    switch (m_match.getTypeTerrain()) {
        case 5 :
            afficheImage("imageFond");
            break;
        case 3:
            afficheImage("Nature");
            break;
        case 2:
            afficheImage("Electric");
            break;
        case 1:
            afficheImage("Water");
            break;
        case 0:
            afficheImage("Fire");
    }

    afficheImage("Terrain_cartes");
}

void AfficheMatch::afficheEnjeux(){
    sf::Text texte=chargerTexte("Enjeux", 1, sf::Color::White,20, 70, 550, sf::Color::Black, 1);
    for(int i=0; i<2; i++){
        setPos(50-10*i, 350-10*i,"Face_cache_no");
        afficheImage("Face_cache_no");
    }
    m_window.draw(texte);
}


void AfficheMatch::afficheCimetiere(const Collection& _cartesBase){
    std::vector<int> cimetiere = m_match.getCimetiere();
    if(cimetiere.size()>0){
        sf::Text texte=Affichage::chargerTexte("Cimetiere", 1, sf::Color::Red,20, 1760, 550, sf::Color::Black, 1);
        texte.setString(L"Cimetière");


        for(int i=0; i<cimetiere.size(); i++){
            auto elem=cimetiere[i];
            Affichage::afficheCarte(_cartesBase,elem,1750-15*i,350, elem);

            sf::RectangleShape rectangle;
            rectangle.setSize(sf::Vector2f(150, 200));
            rectangle.setFillColor(sf::Color(255,0,100,80));
            rectangle.setPosition(1750-15*i, 350);
            Affichage::getWindow().draw(rectangle);
        }

        Affichage::getWindow().draw(texte);
    }
}

bool AfficheMatch::afficheFinPartie(bool& _matchFini){
    afficheImage("Terrain_cartes");
    int x= Affichage::recupSprite("Terrain_cartes").getPosition().x;
    int y=Affichage::recupSprite("Terrain_cartes").getPosition().y;

   sf::Text texte;

    std::string pseudoWin,pseudoLoose;
    if(m_match.getJoueur().getStatueLoose()!=0){//Si a perdu
        pseudoWin= m_match.getJoueurEnnemie().getUser()->getPseudo();
        pseudoLoose=m_match.getJoueur().getUser()->getPseudo();

    }

    else{
        pseudoWin= m_match.getJoueur().getUser()->getPseudo();
        pseudoLoose=m_match.getJoueurEnnemie().getUser()->getPseudo();
    }


    texte = chargerTexte(pseudoWin+" a gagne !",1,sf::Color::Red,50,x+300,y+50,sf::Color::Black,1);
    m_window.draw(texte);



    texte=chargerTexte("Cartes enjeux : ",1,sf::Color::Red,30,x+400,y+200,sf::Color::Black,1);
    m_window.draw(texte);

    afficheCarte(m_match.getJoueur().getCartes(),m_match.getJoueur().getEnjeu().imm,x+310,y+250,m_match.getJoueur().getEnjeu().id);
    texte = chargerTexte(m_match.getJoueur().getUser()->getPseudo(),1,sf::Color::White,20,x+330,y+450,sf::Color::Black,1);
    m_window.draw(texte);

    afficheCarte(m_match.getJoueurEnnemie().getCartes(),m_match.getJoueurEnnemie().getEnjeu().imm,x+600,y+250,m_match.getJoueurEnnemie().getEnjeu().id);
    texte = chargerTexte(m_match.getJoueurEnnemie().getUser()->getPseudo(),1,sf::Color::White,20,x+630,y+450,sf::Color::Black,1);
    m_window.draw(texte);

    texte = chargerTexte(pseudoWin + " gagne ces deux cartes !",1,sf::Color::White,20,x+350,y+500,sf::Color::Black,1);
    m_window.draw(texte);

    if(sf::Mouse::isButtonPressed(sf::Mouse::Left)||sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)){
        //Si clique sur qqch
        getMatch().effacerMatch();
        _matchFini=false;
        return true;
    }



    return false;
}