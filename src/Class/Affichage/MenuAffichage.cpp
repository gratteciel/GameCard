//
// Created by bemat on 24/11/2020.
//

#include "../../Headers/Affichage/Menu.h"

void Menu::menuBaseAffichage(bool& fin, bool& leave,const std::string& pseudoCouleur,const std::string& pseudoInscription){
    int menuActu=getMenuActuel();
    switch (menuActu) {
        case -1:
            sfmlLeave();
            fin = true;
            leave = true;
            break;
        case 0://menu de base
            menu0Affichage();
            break;
        case 1://menu avec Insciription connection et lancement partie
            menu1Affichage();
            break;
        case 2:// menu avec les regles
            menu2Affichage();
            break;
        case 3 : //Parametres
            menu3Affichage();
            break;
        case 4 : //Connection
            menu4Affichage(pseudoCouleur);
            break;
        case 5:
            menu5Affichage(pseudoInscription);
            break;
    }
    //Affichage des utilisateurs
    if(menuActu==1||menuActu==4){
        if(m_jeu.getUsersConnectes().size()>0){
            affichePseudoUtilisateurs();
        }
    }

}

//1er menu du jeu
void Menu::menu0Affichage(){
    afficheImage("Intro");

    if(getBoutonActuel()=="Jouer")
        afficheImage("Jouer_yes");
    else
        afficheImage("Jouer_no");

    if(getBoutonActuel()=="Regles")
        afficheImage("Regles_yes");
    else
        afficheImage("Regles_no");

    if(getBoutonActuel()=="Quitter")
        afficheImage("Quitter_yes");
    else
        afficheImage("Quitter_no");

    if(getBoutonActuel()=="Parametres")
        afficheImage("Parametres_yes");
    else
        afficheImage("Parametres_no");
}

//Menu choix entre connection et inscription
void Menu::menu1Affichage() {
    afficheImage("Login");

    if(getBoutonActuel()=="connecter")
        afficheImage("connecter_yes");
    else
        afficheImage("connecter_no");

    if(getBoutonActuel()=="Inscription")
        afficheImage("Inscription_yes");
    else
        afficheImage("Inscription_no");


    btnRetourAffichage();

}

//Menu des regles
void Menu::menu2Affichage(){
    afficheImage("Regles");

    btnRetourAffichage();
}

//Menu des paramètres
void Menu::menu3Affichage() {
    afficheImage("Intro");

    if(getBoutonActuel()=="Inscription")
        afficheImage("Inscription_yes");
    else
        afficheImage("Inscription_no");

    btnRetourAffichage();

}

//Menu de connection
void Menu::menu4Affichage(const std::string& pseudoCouleur) {

    unsigned short i=0;

    sf::Text _tempTexte;
    _tempTexte.setFont(getFonts()[0]); // choix de la police
    _tempTexte.setFillColor(sf::Color::White);//couleur du texte
    _tempTexte.setCharacterSize(70); // choix de la taille des caractères exprimée en pixel
    _tempTexte.setOutlineColor(sf::Color::Black); // Couleur du contour
    _tempTexte.setOutlineThickness(1); //Taille des contours

    sf::Text texte;
    texte.setPosition(100,100);
    texte.setFont(getFonts()[1]); // choix de la police
    texte.setFillColor(sf::Color::White);//couleur du texte
    texte.setCharacterSize(40); // choix de la taille des caractères exprimée en pixel
    texte.setOutlineColor(sf::Color::Black); // Couleur du contour
    texte.setOutlineThickness(1); //Taille des contours
    texte.setString("LISTE DES PSEUDOS :");


    afficheImage("Login");//Affiche l'image "login"

    btnRetourAffichage();


    m_window.draw(texte);

    for(auto& elem: m_jeu.getUsersPseudo()){

        _tempTexte.setString(elem); //affiche le pseudo

        _tempTexte.setPosition(200,200+70*i);
        if(elem==pseudoCouleur)
            _tempTexte.setFillColor(sf::Color::Red);//couleur du texte
        else
            _tempTexte.setFillColor(sf::Color::White);//couleur du texte
        m_window.draw(_tempTexte);
        i++;
    }
}

//Menu d'inscription
void Menu::menu5Affichage(const std::string& pseudoInscription){
    afficheImage("Login");//Affiche l'image "login"
    btnRetourAffichage();

    sf::Text texte;

    /*AFFICHE "ENTREZ VOTRE PSEUDO : */
    texte.setPosition(100,100);
    texte.setFont(getFonts()[1]); // choix de la police
    texte.setFillColor(sf::Color::White);//couleur du texte
    texte.setCharacterSize(50); // choix de la taille des caractères exprimée en pixel
    texte.setOutlineColor(sf::Color::Black); // Couleur du contour
    texte.setOutlineThickness(1); //Taille des contours
    texte.setString("Entrez votre pseudo :");
    texte.setStyle( sf::Text::Underlined);
    m_window.draw(texte);
    afficheImage("rectInscription");

    /*AFFICHE LE PSEUDO ECRIT*/
    texte.setPosition(100,200);
    texte.setFont(getFonts()[0]); // choix de la police
    texte.setFillColor(sf::Color::Black);//couleur du texte
    texte.setCharacterSize(70); // choix de la taille des caractères exprimée en pixel
    texte.setString(pseudoInscription);
    texte.setStyle( sf::Text::Regular);
    m_window.draw(texte);



}



void Menu::btnRetourAffichage(){
    if(getBoutonActuel()=="Retour")
        afficheImage("Retour_yes");
    else
        afficheImage("Retour_no");
}
void Menu::affichePseudoUtilisateurs(){
    sf::Text _tempTexte;
    _tempTexte.setFont(getFonts()[0]); // choix de la police

    _tempTexte.setCharacterSize(70); // choix de la taille des caractères exprimée en pixel
    _tempTexte.setOutlineColor(sf::Color::Black); // Couleur du contour
    _tempTexte.setOutlineThickness(1); //Taille des contours

    int i=0;
    std::vector<std::string> decksPasValides;
    for(const auto& elem :m_jeu.getUsersConnectes()){
        _tempTexte.setString(elem.first);

        //Vérifie si son deck est valide
        if(!elem.second.getDeck(elem.second.getDeckActif()).getDeckActuValide()){
            decksPasValides.push_back(elem.first);
        }


        //Si le curseur est sur le pseudo actuel
        if(elem.first==getBoutonActuel())
            _tempTexte.setFillColor(sf::Color(230,213,23,255));//couleur du texte
        else
            _tempTexte.setFillColor(sf::Color::White);//couleur du texte

        _tempTexte.setPosition(600+elem.first.size()*40*i,970);
        i++;
        m_window.draw(_tempTexte);

    }

    if(m_jeu.getUsersConnectes().size()==2)
    {
        if(decksPasValides.size()==0){
            if(getBoutonActuel()=="LancerPartie")
                afficheImage("LancerPartie_yes");
            else
                afficheImage("LancerPartie_no");
        }
        //Afficher que les decks des joueurs ne sont pas valides
        else{
            sf::Text texte;

            texte.setFont(getFonts()[1]); // choix de la police
            texte.setFillColor(sf::Color::White);//couleur du texte
            texte.setCharacterSize(17); // choix de la taille des caractères exprimée en pixel
            texte.setOutlineColor(sf::Color::Black); // Couleur du contour
            texte.setOutlineThickness(1); //Taille des contours

            if(decksPasValides.size()==1)
                texte.setString("Le deck actif de " + decksPasValides[0] + " n'est pas valide!");
            else
                texte.setString("Les decks actifs de " + decksPasValides[0] + " et de "+ decksPasValides[1] +" ne sont pas valides!");
            texte.setPosition(1250,980);
            m_window.draw(texte);
            texte.setPosition(1250,1010);
            texte.setString("(Un deck doit contenir exactement "+ std::to_string(Deck::getNumCartes()) +" cartes)");
            m_window.draw(texte);
        }
    }
}

void Menu::sfmlLeave() {
    afficheImage("Leave");
}