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

    setPos(50,1000,"Retour_no");
    setPos(50,1000,"Retour_yes");
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

    setPos(50,1000,"Retour_no");
    setPos(50,1000,"Retour_yes");

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

/*Menu création de carte créature*/
void Menu::menu6Affichage()
{
    afficheImage("Intro");
    m_window.draw(chargerTexte("Nom :", 1, sf::Color::White, 25, 85, 30));
    m_window.draw(chargerTexte("DESCRIPTION :", 1, sf::Color::White, 25, 85, 180));
    m_window.draw(chargerTexte("DOMAINE (0=FEU, 1=EAU, 2=ELECTRIQUE, 3=NATURE) :", 1, sf::Color::White, 25, 85, 330));

    m_window.draw(chargerTexte("Point de vie initiaux :", 1, sf::Color::White, 25, 85, 480));

    m_window.draw(chargerTexte("Une fois que le domaine est rempli, vous pourrez cliquer sur les immatriculation des attaques :", 1, sf::Color::White, 25, 85, 650));

    m_window.draw(chargerTexte("Attaque 1 (Immatriculation) :", 1, sf::Color::White, 25, 85, 700));
    m_window.draw(chargerTexte(std::to_string(m_creationCarte.attaque1), 1, sf::Color::Red, 25, 560, 700));
    m_window.draw(chargerTexte("Attaque 2 (Immatriculation) :", 1, sf::Color::White, 25, 85, 780));
    m_window.draw(chargerTexte(std::to_string(m_creationCarte.attaque2), 1, sf::Color::Red, 25, 560, 780));

    for(int i=0; i<m_creationCarte.creaCarte.size(); i++){
        setPos(85,60+150*i,"rectInscription");
        afficheImage("rectInscription");

        if(i==m_creationCarte.section)
        {
            sf::RectangleShape rectangle;
            rectangle.setSize(sf::Vector2f(500-6, 85-6));
            rectangle.setFillColor(sf::Color(255,0,0,30));

            rectangle.setPosition(85+3, 60+150*i+3);
            Affichage::getWindow().draw(rectangle);
        }
    }
    //Affiche bouton creer
    if(m_creationCarte.creaCarte[0] != "" && m_creationCarte.creaCarte[1] != "" && m_creationCarte.creaCarte[2] != "" && m_creationCarte.creaCarte[3] != ""&& m_creationCarte.attaque1!=0 && m_creationCarte.attaque2!=0) {
        if(getBoutonActuel()=="creer")
            m_window.draw(chargerTexte("Creer", 0, sf::Color::Red, 100, 1700, 900, sf::Color::Black, 2));
        else
            m_window.draw(chargerTexte("Creer", 0, sf::Color::Green, 100, 1700, 900, sf::Color::Black, 2));
    }


    //Affiche les inputs entrées
    for(int i=0; i<m_creationCarte.creaCarte.size(); i++){
        m_window.draw(chargerTexte(m_creationCarte.creaCarte[i], 1, sf::Color::Black, 40, 100, 75+150*i));
    }

    afficheAttaqueCreationCarte();



    btnRetourAffichage();

}



void Menu::menu7Affichage() {

    afficheImage("Intro");
    m_window.draw(chargerTexte("Nom :", 1, sf::Color::White, 25, 85, 30));
    m_window.draw(chargerTexte("DESCRIPTION :", 1, sf::Color::White, 25, 85, 180));
    m_window.draw(chargerTexte("DOMAINE (0=FEU, 1=EAU, 2=ELECTRIQUE, 3=NATURE) :", 1, sf::Color::White, 25, 85, 330));

    m_window.draw(chargerTexte("Point de vie initiaux :", 1, sf::Color::White, 25, 85, 480));
    m_window.draw(chargerTexte("Type (0 = reine, 1=roi)", 1, sf::Color::White, 25, 85, 630));
    m_window.draw(chargerTexte("Une fois que le domaine est rempli, vous pourrez cliquer sur les immatriculation des attaques :", 1, sf::Color::White, 25, 85, 800));


    m_window.draw(chargerTexte("Attaque 1 (Immatriculation) :", 1, sf::Color::White, 25, 85, 880));
    m_window.draw(chargerTexte(std::to_string(m_creationCarte.attaque1), 1, sf::Color::Red, 25, 560, 880));

    for(int i=0; i<m_creationCarte.creaCarte.size(); i++){
        setPos(85,60+150*i,"rectInscription");
        afficheImage("rectInscription");

        if(i==m_creationCarte.section)
        {
            sf::RectangleShape rectangle;
            rectangle.setSize(sf::Vector2f(500-6, 85-6));
            rectangle.setFillColor(sf::Color(255,0,0,30));

            rectangle.setPosition(85+3, 60+150*i+3);
            Affichage::getWindow().draw(rectangle);
        }
    }
    //Affiche bouton creer
    if(m_creationCarte.creaCarte[0] != "" && m_creationCarte.creaCarte[1] != "" && m_creationCarte.creaCarte[2] != "" && m_creationCarte.creaCarte[3] != ""&& m_creationCarte.attaque1!=0) {
        if(getBoutonActuel()=="creer")
            m_window.draw(chargerTexte("Creer", 0, sf::Color::Red, 100, 1700, 900, sf::Color::Black, 2));
        else
            m_window.draw(chargerTexte("Creer", 0, sf::Color::Green, 100, 1700, 900, sf::Color::Black, 2));
    }


    //Affiche les inputs entrées
    for(int i=0; i<m_creationCarte.creaCarte.size(); i++){
        m_window.draw(chargerTexte(m_creationCarte.creaCarte[i], 1, sf::Color::Black, 40, 100, 75+150*i));
    }

    afficheAttaqueCreationCarte();



    btnRetourAffichage();

}

void Menu::choixCreatureAffichage(){
    int i=1,j=0;
    setPos(0,0,"Rectangle_inscription");
    afficheImage("Rectangle_inscription");
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
    setPos(0,0,"Rectangle_inscription");
    afficheImage("Rectangle_inscription");
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
    setPos(0,0,"Rectangle_inscription");
    afficheImage("Rectangle_inscription");
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
        _tempTexte.setString(elem.getPseudo());

        //Vérifie si son deck est valide
        if(!elem.getDeck(elem.getDeckActif()).getDeckActuValide()){
            decksPasValides.push_back(elem.getPseudo());
        }


        //Si le curseur est sur le pseudo actuel
        if(elem.getPseudo()==getBoutonActuel())
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
    if(getGestionUtilisateur()!=-1){

        afficheImage("Background_utilisateur");
        /*AFFICHE LE PSEUDO*/
        sf::Text texte=chargerTexte(m_jeu.getUsersConnectes()[getGestionUtilisateur()].getPseudo(),0,sf::Color(198,27,27),100,10,10,sf::Color::White,0);
        m_window.draw(texte);

        /*AFFICHE le bouton de déconnexion*/
        texte=chargerTexte("Deconnexion",1,sf::Color(233,233,233,255),20,20,120,sf::Color::Black,2);
        texte.setString(L"Déconnexion");

        if(getBoutonActuel()=="deconnexion")
            texte.setFillColor(sf::Color(230,213,23));
        m_window.draw(texte);

        gestionAffichageDeckJoueur();


    }


}


void Menu::gestionAffichageDeckJoueur(){

    sf::Color couleur = sf::Color(233,233,233,255);
    sf::Text texte;
    std::string temp;
    int nbreDecks= m_jeu.getUsersConnectes()[getGestionUtilisateur()].getNombreDeck();//affiche le deck 0 car un seul deck
    int prix = 0;
    std::string argent;


    switch (getModeAffichageJoueur()) {
        case 1: //affiche les truc de bases
            /* Cette partie permet d'afficher les cartes du deck du joueur selectionner */

            if(getBoutonActuel()=="voir ses decks")
                m_window.draw(chargerTexte("Voir ses decks",1,sf::Color(198,27,27),100,150,300));
            else
                m_window.draw(chargerTexte("Voir ses decks",1,sf::Color(233,233,233,255),100,150,300));

            if(getBoutonActuel()=="creer un deck")
                m_window.draw(chargerTexte("Creer un deck",1,sf::Color(198,27,27),100,850,500));
            else
                m_window.draw(chargerTexte("Creer un deck",1,sf::Color(233,233,233,255),100,850,500));
            if(getBoutonActuel()=="shop")
                m_window.draw(chargerTexte("Shop",1,sf::Color(198,27,27),70,50,825));
            else
                m_window.draw(chargerTexte("Shop",1,sf::Color(233,233,233,255),70,50,825));
            break;




        case 2://quand on appuie sur voir ses decks et cliquer sur le deck qu'on veut afficher
            m_window.draw(chargerTexte("Cartes Seules",1,couleur,50,700,100,sf::Color(0,0,0,255),5));

            // ici colore tous les deck car boucle for ...??????
            for(int i(0);i<nbreDecks;i++){
                std::string temp=  "Deck "+ std::to_string(i+1);
                if(getBoutonActuel()=="choixDeck" + std::to_string(i)){
                    m_window.draw(chargerTexte(temp,1,sf::Color(198,27,27),40,300+300*i,20));
                }
                else
                    m_window.draw(chargerTexte(temp,1,sf::Color(233,233,233,255),40,300+300*i,20));

            }


            /* Affichage des cartes seules */
            for(int i(0) ; i< m_jeu.getUsersConnectes()[getGestionUtilisateur()].getCartesSeules().size();i++) {

                Affichage::afficheCarte(m_jeu.getCartesBases(),m_jeu.getUsersConnectes()[getGestionUtilisateur()].getCartesSeules()[i],50 + 170 * i, 200,m_jeu.getUsersConnectes()[getGestionUtilisateur()].getCartesSeules()[i]);


                //contour autour des cartes seules
                if(getBoutonActuel()=="cartesSeulesnum" + std::to_string(i)){
                    sf::RectangleShape rectangle;
                    rectangle.setSize(sf::Vector2f(150, 200));
                    rectangle.setFillColor(sf::Color(255,255,255,30));
                    rectangle.setOutlineColor(sf::Color(255,0,0,200));
                    rectangle.setOutlineThickness(2);
                    rectangle.setPosition(50 + 170 * i, 200);
                    Affichage::getWindow().draw(rectangle);
                }
            }




            if(getAffichageDeck()!=-1){//correspond a l'affichage du deck selectionné

                texte = chargerTexte("Selectionner ce deck pour jouer",1,sf::Color::White,40,500,500,sf::Color::Black,2);
                if(getBoutonActuel()=="changerDeck")
                    sf::Text texte = chargerTexte("Selectionner ce deck pour jouer",1,sf::Color::Red,40,500,500,sf::Color::Black,2);

                m_window.draw(texte);
                /* Affichage partie du bas */

                setPos(10,690,"Rectangle_deck");
                afficheImage("Rectangle_deck");
                m_window.draw(chargerTexte("Mon deck",1,sf::Color(233,233,233,255),30,1700,900,sf::Color(233,0,0,255),3));

                /* Affichage des cartes */

                for(int j(0);j < m_jeu.getUsersConnectes()[getGestionUtilisateur()].getDeck(getAffichageDeck()).getCartes().size();j++) {

                    afficheCarte(m_jeu.getCartesBases(), m_jeu.getUsersConnectes()[getGestionUtilisateur()].getDeck(getAffichageDeck()).getCartes()[j],50 + 170 * j, 700,m_jeu.getUsersConnectes()[getGestionUtilisateur()].getDeck(getAffichageDeck()).getCartes()[j]);

                    if(getBoutonActuel()=="carteDecknum" + std::to_string(j)) {
                        sf::RectangleShape rectangle;
                        rectangle.setSize(sf::Vector2f(150, 200));
                        rectangle.setFillColor(sf::Color(255, 255, 255, 30));
                        rectangle.setOutlineColor(sf::Color(255, 0, 0, 200));
                        rectangle.setOutlineThickness(2);
                        rectangle.setPosition(50 + 170 * j, 700);
                        Affichage::getWindow().draw(rectangle);
                    }
                }
            }
            break;




        case 3://quand on veut créer un deck



            temp+= "Creation du deck numero "+ std::to_string(nbreDecks+1);
            m_window.draw(chargerTexte(temp,1,sf::Color(198,100,200),40,300,20));
            if(getBoutonActuel()=="shop")
                m_window.draw(chargerTexte("Shop",1,sf::Color(198,27,27),70,1650,20));
            else
                m_window.draw(chargerTexte("Shop",1,sf::Color(233,233,233,255),70,1650,20));

            setPos(10,690,"Rectangle_deck");
            afficheImage("Rectangle_deck");
            m_window.draw(chargerTexte("Mon deck",1,sf::Color(233,233,233,255),30,1700,900,sf::Color(233,0,0,255),3));

            //Affiche le deck actuel avec les cartes
            texte=chargerTexte("Choisissez 10 cartes",1,sf::Color::White,30,300,900,sf::Color::Black,1);
            m_window.draw(texte);

            /*AFFICHE LES CARTES DU DECK*/

            for(int j(0);j < m_choixInscription.imm.size();j++) {

                Affichage::afficheCarte(m_jeu.getCartesBases(), m_choixInscription.imm[j],50 + 170 * j, 700,m_choixInscription.imm[j]);

                if(getBoutonActuel()=="carteDecknum" + std::to_string(j)){
                    sf::RectangleShape rectangle;
                    rectangle.setSize(sf::Vector2f(150, 200));
                    rectangle.setFillColor(sf::Color(255,255,255,30));
                    rectangle.setOutlineColor(sf::Color(255,0,0,200));
                    rectangle.setOutlineThickness(2);
                    rectangle.setPosition(50 + 170 * j, 700);
                    Affichage::getWindow().draw(rectangle);
                }
            }

            /* Affichage des cartes seules */

            for(int i(0) ; i< m_jeu.getUsersConnectes()[getGestionUtilisateur()].getCartesSeules().size();i++) {

                Affichage::afficheCarte(m_jeu.getCartesBases(),m_jeu.getUsersConnectes()[getGestionUtilisateur()].getCartesSeules()[i],50 + 170 * i, 200,m_jeu.getUsersConnectes()[getGestionUtilisateur()].getCartesSeules()[i]);
                if(getBoutonActuel()=="cartesSeulesnum" + std::to_string(i)){
                    sf::RectangleShape rectangle;
                    rectangle.setSize(sf::Vector2f(150, 200));
                    rectangle.setFillColor(sf::Color(255,255,255,30));
                    rectangle.setOutlineColor(sf::Color(255,0,0,200));
                    rectangle.setOutlineThickness(2);
                    rectangle.setPosition(50 + 170 * i, 200);
                    Affichage::getWindow().draw(rectangle);
                }
            }


            if(m_choixInscription.valide){
                texte=chargerTexte("Creer", 1, sf::Color(79,210,30,255),70,1600, 975,sf::Color::Black, 2);
                if(getBoutonActuel()=="Creer")
                    texte.setFillColor(sf::Color(198,27,27));
                m_window.draw(texte);
            }

            break;



        case 4: // Le shop
            // on affiche les differents sets des cartes

            /* AFFICHE LES CLIQUABLES POUR LES CREATURES */
            int i = 1, j = 0, k = 0;

            setPos(1100, 50, "Creature");
            afficheImage("Creature");
            texte = chargerTexte("Afficher", 1, sf::Color::White, 20, 1120, 125);
            m_window.draw(texte);
            texte = chargerTexte("CREATURES", 1, sf::Color::White, 20, 1108, 150);
            m_window.draw(texte);

            /* AFFICHE LES CLIQUABLES POUR LES SPECIALES */
            setPos(1300, 50, "Speciale");
            afficheImage("Speciale");
            texte = chargerTexte("Afficher", 1, sf::Color::White, 20, 1320, 125);
            m_window.draw(texte);
            texte = chargerTexte("SPECIALES", 1, sf::Color::White, 20, 1310, 150);
            m_window.draw(texte);

            /* AFFICHE LES CLIQUABLES POUR LES ENERGIES */
            setPos(1500, 50, "Energie");
            afficheImage("Energie");
            texte = chargerTexte("Afficher", 1, sf::Color::White, 20, 1520, 125);
            m_window.draw(texte);
            texte = chargerTexte("ENERGIES", 1, sf::Color::White, 20, 1510, 150);
            m_window.draw(texte);

            if(getAffichageCartes()==1) {
                prix= 30;

                for (auto &elem : m_jeu.getCartesBases().getCreatures()) {// boucle pour afficher les cartes sur les différentes lignes
                    elem.affiche(-150 + 170 * i, 200 + 220 * j);
                    if (i % 6 == 0) {
                        i = 0;
                        j++;
                    }
                    if (getBoutonActuel() == "cartesShop" + std::to_string(i) + std::to_string(j)) {
                        sf::RectangleShape rectangle;
                        rectangle.setSize(sf::Vector2f(150, 200));
                        rectangle.setFillColor(sf::Color(255, 255, 255, 30));
                        rectangle.setOutlineColor(sf::Color(255, 0, 0, 200));
                        rectangle.setOutlineThickness(2);
                        rectangle.setPosition(-150 + 170 * i, 200 + 220 * j);
                        Affichage::getWindow().draw(rectangle);
                    }
                    i++;
                }
            }

            if(getAffichageCartes()==2) {
                prix = 20;
                for (auto &elem : m_jeu.getCartesBases().getSpeciales()) {// boucle pour afficher les cartes sur les différentes lignes
                    elem.affiche(-150 + 170 * i, 200 + 220 * j);
                    if (i % 6 == 0) {
                        i = 0;
                        j++;
                    }
                    if (getBoutonActuel() == "cartesShop" + std::to_string(i) + std::to_string(j)) {
                        sf::RectangleShape rectangle;
                        rectangle.setSize(sf::Vector2f(150, 200));
                        rectangle.setFillColor(sf::Color(255, 255, 255, 30));
                        rectangle.setOutlineColor(sf::Color(255, 0, 0, 200));
                        rectangle.setOutlineThickness(2);
                        rectangle.setPosition(-150 + 170 * i, 200 + 220 * j);
                        Affichage::getWindow().draw(rectangle);
                    }
                    i++;
                }

            }
            if(getAffichageCartes()==3) {
                prix = 50;
                for (auto &elem : m_jeu.getCartesBases().getEnergies()) {// boucle pour afficher les cartes sur les différentes lignes
                    elem.affiche(-150 + 170 * i, 200 + 220 * j);
                    if (i % 6 == 0) {
                        i = 0;
                        j++;
                    }
                    if (getBoutonActuel() == "cartesShop" + std::to_string(i) + std::to_string(j)) {
                        sf::RectangleShape rectangle;
                        rectangle.setSize(sf::Vector2f(150, 200));
                        rectangle.setFillColor(sf::Color(255, 255, 255, 30));
                        rectangle.setOutlineColor(sf::Color(255, 0, 0, 200));
                        rectangle.setOutlineThickness(2);
                        rectangle.setPosition(-150 + 170 * i, 200 + 220 * j);
                        Affichage::getWindow().draw(rectangle);
                    }
                    i++;
                }

            }

            if(getImCarteShop()!=0) {
                std::string prixS = std::to_string(prix);
                sf::Text prixT = Affichage::chargerTexte("Prix : " + prixS,1,sf::Color::White,50,1200,500);
                m_window.draw(prixT);

                temp = "Acheter la carte " + std::to_string(getImCarteShop());

                argent = "Il vous reste " + std::to_string(m_jeu.getUsersConnectes()[getGestionUtilisateur()].getArgent());

                getWindow().draw(chargerTexte(argent, 1, sf::Color(255, 0, 0, 255), 40, 1000, 700));
                if (getBoutonActuel() == "curseurAcheter") {
                    getWindow().draw(chargerTexte(temp, 1, sf::Color(255, 0, 0, 255), 40, 1000, 800));
                } else {

                    getWindow().draw(chargerTexte(temp, 1, sf::Color(255, 255, 255, 255), 40, 1000, 800));
                }
            }



            break;
    }
}

void Menu::sfmlLeave() {
    afficheImage("Leave");
}

void Menu::affichePermuterJoueurs(){
    Affichage::afficheImage("changementDeTour");
    sf::Text texte=chargerTexte("Changement de joueur",1,sf::Color::White,80,400,300,sf::Color::Black,2);
    getWindow().draw(texte);
    m_bool.sleep=true;
}

void Menu::afficheAttaqueCreationCarte(){
    //Affiches les attaques
    m_window.draw(chargerTexte("Attaques : ", 1, sf::Color::White, 40,900,20));
    m_window.draw(chargerTexte("Domaine    Im      Nom                                     Degats", 1, sf::Color::Red, 25,900,80));

    for(int i(0);i<m_jeu.getCartesBases().getAttaques().size()-8;i++){
        auto elem= m_jeu.getCartesBases().getAttaques()[i];
        if(elem.getDomaine()==-3)
            m_window.draw(chargerTexte("Aucun",1,sf::Color::White,25,900,120+30*i));
        else
            m_window.draw(chargerTexte(std::to_string(elem.getDomaine()),1,sf::Color::White,25,900,120+30*i));
    }


    for(int i(0);i<m_jeu.getCartesBases().getAttaques().size()-8;i++){
        auto elem= m_jeu.getCartesBases().getAttaques()[i];
        if(getBoutonActuel()=="imm"+std::to_string(i)){
            m_window.draw(chargerTexte(std::to_string(elem.getImmatriculation()),1,sf::Color::Red,25,1050,120+30*i));
        }
        else
            m_window.draw(chargerTexte(std::to_string(elem.getImmatriculation()),1,sf::Color::White,25,1050,120+30*i));

    }

    for(int i(0);i<m_jeu.getCartesBases().getAttaques().size()-8;i++){
        auto elem= m_jeu.getCartesBases().getAttaques()[i];
        m_window.draw(chargerTexte(elem.getNom(),1,sf::Color::White,25,1150,120+30*i));
    }

    for(int i(0);i<m_jeu.getCartesBases().getAttaques().size()-8;i++){
        auto elem= m_jeu.getCartesBases().getAttaques()[i];
        m_window.draw(chargerTexte(std::to_string(elem.getDegat()),1,sf::Color::White,25,1600,120+30*i));
    }


    //Fin affiche d'attaques
}