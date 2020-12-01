//
// Created by bemat on 24/11/2020.
//

#include "../../Headers/Affichage/Menu.h"

void Menu::menuBaseAffichage(const std::string& pseudoCouleur){
    int menuActu=getMenuActuel();
    switch (menuActu) {
        case -1:
            sfmlLeave();
            m_bool.fin = true;
            m_bool.sleep = true;
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
            menu5Affichage();
            break;
        case 6:
            menu6Affichage();
            break;
        case 7:
            menu7Affichage();
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
    if(getBoutonActuel()=="Creer une Carte Creature"){
        m_window.draw(chargerTexte("Creer une Carte Creature",1,sf::Color(230,213,23,255),40,150,350));
    }
    else
        m_window.draw(chargerTexte("Creer une Carte Creature",1,sf::Color(233,233,233,255),40,150,350));
    if(getBoutonActuel()=="Creer une Carte Speciale"){
        m_window.draw(chargerTexte("Creer une Carte Speciale",1,sf::Color(230,213,23,255),40,1100,350));
    }
    else
        m_window.draw(chargerTexte("Creer une Carte Speciale",1,sf::Color(233,233,233,255),40,1100,350));

    btnRetourAffichage();

}

//Menu de connection
void Menu::menu4Affichage(const std::string& pseudoCouleur) {

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
    unsigned short j=0;
    unsigned short i=0;
    for(auto& elem: m_jeu.getUsersPseudo()){

        if(i%10==0&&i!=0){
            i=1;
            j++;
        }

        _tempTexte.setString(elem); //affiche le pseudo

        _tempTexte.setPosition(100+500*j,200+70*i);
        if(elem==pseudoCouleur)
            _tempTexte.setFillColor(sf::Color::Red);//couleur du texte
        else
            _tempTexte.setFillColor(sf::Color::White);//couleur du texte
        m_window.draw(_tempTexte);

        i++;
    }
}

//Menu d'inscription
void Menu::menu5Affichage(){
    afficheImage("Login");//Affiche l'image "login"

    //Affiche le bouton Retour
    setPos(50,800,"Retour_no");
    setPos(50,800,"Retour_yes");
    btnRetourAffichage();
    setPos(50,1000,"Retour_no");
    setPos(50,1000,"Retour_yes");

    /*AFFICHE "ENTREZ VOTRE PSEUDO : */
    sf::Text texte=chargerTexte("Entrez votre pseudo :",1,sf::Color(233,233,233,255),50,100,100,sf::Color::Black,1);
    texte.setStyle( sf::Text::Underlined);
    m_window.draw(texte);

    //Affiche rectangle blanc pour écrire son pseudo
    afficheImage("rectInscription");


    //Affiche le deck actuel avec les cartes
    texte=chargerTexte("Choisissez 11 cartes, les " + std::to_string(Deck::getNumCartes()) +" premieres formeront votre 1er deck.",1,sf::Color::White,30,600,815,sf::Color::Black,1);


    /*AFFICHE LES CARTES DU DECK*/
    m_window.draw(texte);
    setPos(10,855,"Rectangle_deck");
    afficheImage("Rectangle_deck");
    for(int i=0; i<m_choixInscription.imm.size();i++){
        int x=65+155*i;
        int y=865;
        afficheCarte(m_jeu.getCartesBases(), m_choixInscription.imm[i], x, y,m_choixInscription.imm[i]);

    }

    /*SI INSCRIPTION EST VALIDE*/
    if(m_choixInscription.valide){
        texte=chargerTexte("Creer", 1, sf::Color(79,210,30,255),80,420, 720,sf::Color::Black, 2);
        if(getBoutonActuel()=="Creer")
            texte.setFillColor(sf::Color(198,27,27));
        m_window.draw(texte);
    }


    if(m_choixInscription._choixTypeCarte=="none"){
        /*AFFICHE LE PSEUDO ECRIT*/
        texte=chargerTexte(m_choixInscription.pseudoInscription,0,sf::Color::Black,70,100,200,sf::Color::Black,0);
        texte.setStyle( sf::Text::Regular);
        m_window.draw(texte);

        /*AFFICHE LES CLIQUABLES*/

        /* AFFICHE LES CLIQUABLES POUR LES CREATURES */
        setPos(1100,200, "Creature");
        afficheImage("Creature");
        texte=chargerTexte("Afficher",1,sf::Color::White,20,1120,275);
        m_window.draw(texte);
        texte=chargerTexte("CREATURES",1,sf::Color::White,20,1108,300);
        m_window.draw(texte);

        /* AFFICHE LES CLIQUABLES POUR LES SPECIALES */
        setPos(1300,200, "Speciale");
        afficheImage("Speciale");
        texte=chargerTexte("Afficher",1,sf::Color::White,20,1320,275);
        m_window.draw(texte);
        texte=chargerTexte("SPECIALES",1,sf::Color::White,20,1310,300);
        m_window.draw(texte);

        /* AFFICHE LES CLIQUABLES POUR LES ENERGIES */
        setPos(1500,200, "Energie");
        afficheImage("Energie");
        texte=chargerTexte("Afficher",1,sf::Color::White,20,1520,275);
        m_window.draw(texte);
        texte=chargerTexte("ENERGIES",1,sf::Color::White,20,1510,300);
        m_window.draw(texte);

    }
    else{
        if(m_choixInscription._choixTypeCarte=="Creature")
            choixCreatureAffichage();
        else if(m_choixInscription._choixTypeCarte=="Speciale")
            choixSpecialeAffichage();
        else if(m_choixInscription._choixTypeCarte=="Energie")
            choixEnergieAffichage();

        m_choixInscription.drag.afficheCarte(m_jeu.getCartesBases());
    }

}

void Menu::menu6Affichage()
{
    afficheImage("Intro");
    m_window.draw(chargerTexte("Veuillez mettre le nom de la creature", 1, sf::Color::White, 35, 25, 100));
    m_window.draw(chargerTexte("Veuillez mettre l'attaque 1 de la creature (IM) ", 1, sf::Color::White, 35, 25, 400));
    m_window.draw(chargerTexte("Veuillez mettre l'attaque 2 de la creature (IM)", 1, sf::Color::White, 35, 25, 700));
    setPos(85,170,"rectInscription");
    afficheImage("rectInscription");
    setPos(85,470,"rectInscription");
    afficheImage("rectInscription");
    setPos(85,770,"rectInscription");
    afficheImage("rectInscription");
    m_window.draw(chargerTexte(m_creationCarte.creaCarte[0], 1, sf::Color::Black, 40, 100, 180));
    m_window.draw(chargerTexte(m_creationCarte.creaCarte[1], 1, sf::Color::Black, 40, 100, 480));
    m_window.draw(chargerTexte(m_creationCarte.creaCarte[2], 1, sf::Color::Black, 40, 100, 780));
    m_window.draw(chargerTexte("  Im    Nom                   Degats", 1, sf::Color::Red, 25,1100,10));
    for(int i(0);i<m_jeu.getCartesBases().getAttaques().size()-8;i++){
        auto elem= m_jeu.getCartesBases().getAttaques()[i];
        m_window.draw(chargerTexte("  " + std::to_string(elem.getImmatriculation()) +"   "+elem.getNom()+"      "+std::to_string(elem.getDegat()),1,sf::Color::White,25,1100,50+30*i));
    }
    btnRetourAffichage();

}

void Menu::menu7Affichage() {

    afficheImage("Intro");
    m_window.draw(chargerTexte("Veuillez mettre le nom de la speciale", 1, sf::Color::White, 35, 25, 100));
    m_window.draw(chargerTexte("Veuillez mettre l'attaque 1 de la speciale (IM) ", 1, sf::Color::White, 35, 25, 400));
    m_window.draw(chargerTexte("Veuillez mettre l'attaque 2 de la speciale (IM)", 1, sf::Color::White, 35, 25, 700));
    setPos(85,170,"rectInscription");
    afficheImage("rectInscription");
    setPos(85,470,"rectInscription");
    afficheImage("rectInscription");
    setPos(85,770,"rectInscription");
    afficheImage("rectInscription");
    m_window.draw(chargerTexte(m_creationCarte.creaCarte[0], 1, sf::Color::Black, 40, 100, 180));
    m_window.draw(chargerTexte(m_creationCarte.creaCarte[1], 1, sf::Color::Black, 40, 100, 480));
    m_window.draw(chargerTexte(m_creationCarte.creaCarte[2], 1, sf::Color::Black, 40, 100, 780));
    m_window.draw(chargerTexte("  Im    Nom                   Degats", 1, sf::Color::Red, 25,1100,10));
    for(int i(0);i<m_jeu.getCartesBases().getAttaques().size();i++){
        auto elem= m_jeu.getCartesBases().getAttaques()[i];
        m_window.draw(chargerTexte("  " + std::to_string(elem.getImmatriculation()) +"   "+elem.getNom()+"      "+std::to_string(elem.getDegat()),1,sf::Color::White,25,1100,50+30*i));
    }
    btnRetourAffichage();

}

void Menu::choixCreatureAffichage(){
    int i=1,j=0;
    setPos(0,0,"Rectangle_bois");
    afficheImage("Rectangle_bois");
    for(auto& elem : m_jeu.getCartesBases().getCreatures()){
        elem.affiche(-65+170*i, 40+210*j);
        if(i%10==0){
            i=0;
            j++;
        }
        i++;
    }
}

void Menu::choixSpecialeAffichage(){
    int i=1,j=0;
    setPos(0,0,"Rectangle_bois");
    afficheImage("Rectangle_bois");
    for(auto& elem : m_jeu.getCartesBases().getSpeciales()){
        elem.affiche(-65+170*i, 40+210*j);
        if(i%10==0){
            i=0;
            j++;
        }
        i++;
    }
}
void Menu::choixEnergieAffichage(){
    int i=1,j=0;
    setPos(0,0,"Rectangle_bois");
    afficheImage("Rectangle_bois");
    for(auto& elem : m_jeu.getCartesBases().getEnergies()){
        elem.affiche(-65+170*i, 40+210*j);
        if(i%10==0){
            i=0;
            j++;
        }
        i++;
    }
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

        _tempTexte.setPosition(600+250*i,970);
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

    /*GESTION DES UTILISATEURS (AFFICHAGE)*/
    gestionUtilisateurAffichage();

}

void Menu::gestionUtilisateurAffichage(){
    if(getGestionUtilisateur()!="none"){
        afficheImage("Background_utilisateur");
        /*AFFICHE LE PSEUDO*/
        sf::Text texte=chargerTexte(getGestionUtilisateur(),0,sf::Color(198,27,27),100,10,10,sf::Color::White,0);
        m_window.draw(texte);

        /*AFFICHE le bouton de déconnexion*/
        texte=chargerTexte("Deconnexion",1,sf::Color(233,233,233,255),20,20,120,sf::Color::Black,2);
        texte.setString(L"Déconnexion");

        if(getBoutonActuel()=="deconnexion")
            texte.setFillColor(sf::Color(230,213,23));
        m_window.draw(texte);



    }


}

void Menu::sfmlLeave() {
    afficheImage("Leave");
}