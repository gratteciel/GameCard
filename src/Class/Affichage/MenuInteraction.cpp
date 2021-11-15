//
// Created by bemat on 25/11/2020.
//

#include "../../Headers/Affichage/Menu.h"

void Menu::interactionPseudoUtilisateurs() {
    unsigned int i=0;
    bool fin=false, decksValides=true;

    for(const auto& elem :m_jeu.getUsersConnectes()){
        if(!elem.getDeck(elem.getDeckActif()).getDeckActuValide())
            decksValides=false;

        if (getMousePosition().x>(600+250*i) && getMousePosition().x<(600+250*i+elem.getPseudo().size()*24) && getMousePosition().y>(970) && getMousePosition().y<(970+70) ){
            fin=true;
            setBoutonActuel(elem.getPseudo());

            if (sf::Mouse::isButtonPressed(sf::Mouse::Left)){//Si appuie sur pseudo
                if(getGestionUtilisateur()==-1)
                    setGestionUtilisateur(i);
                else
                    setGestionUtilisateur(-1);
            }
            break;
        }
        i++;
    }

   if(!fin){
       //Si 2 personnes connectées et leurs decks sont valides
       std::string bouton= getBoutonActuel();
       if(m_jeu.getUsersConnectes().size()==2 && decksValides)
       {
           if(getMousePosition().x < recupSprite("LancerPartie_no").getPosition().x + 492 &&
              getMousePosition().x > recupSprite("LancerPartie_no").getPosition().x &&
              getMousePosition().y < recupSprite("LancerPartie_no").getPosition().y + 35 &&
              getMousePosition().y > recupSprite("LancerPartie_no").getPosition().y){


               if (sf::Mouse::isButtonPressed(sf::Mouse::Left)){//lancer le match

                   m_jeu.lancerMatch();

                   setMode(1);
                   m_bool.sleep=true;
               }
               setBoutonActuel("LancerPartie");
           }

       }
   }

   /*GESTION DES UTILISATEURS (INTERACTION)*/
   gestionUtilisateurInteraction();
}

void Menu::gestionUtilisateurInteraction(){
    if(getGestionUtilisateur()!=-1){
        if(!btnRetourInteraction(40)){
            gestionInteractionDeckJoueur();

            if(getMousePosition().x >20&& getMousePosition().x<20+170 && getMousePosition().y >120 &&
               getMousePosition().y<150){
                setBoutonActuel("deconnexion");

                if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
                    m_jeu.deconnexionUser(getGestionUtilisateur());
                    setGestionUtilisateur(-1);
                }

            }


        }
    }
    else{
        //permet de refixe le numero du deck afin que le joueur suivant n'affiche le meme numero du deck que celui du précédent
        setModeAffichageJoueur(1);
        setAffichageDeck(-1);
    }


}



void Menu::gestionInteractionDeckJoueur() {

    /* Initialisation */
    m_choixInscription.valide = false;
    m_choixInscription.pseudoInscription = m_jeu.getUsersConnectes()[getGestionUtilisateur()].getPseudo();
    int prix = 0;

    switch (getModeAffichageJoueur()) {
        case 1: //Premier sous-menu : Voir decks /Creer deck / shop
            if ( getMousePosition().x > 150 && getMousePosition().x < 150 + 900 && getMousePosition().y > 300 &&
                 getMousePosition().y < 400 ) {
                setBoutonActuel("voir ses decks");

                if ( sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                    setModeAffichageJoueur(2);
                    setAffichageDeck(-1);
                }
            }
            if ( getMousePosition().x > 950 && getMousePosition().x < 950 + 900 && getMousePosition().y > 500 &&
                 getMousePosition().y < 600 ) {
                setBoutonActuel("creer un deck");
                if ( sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                    setModeAffichageJoueur(3);
                }
            }
            if ( getMousePosition().x > 50 && getMousePosition().x < 50 + 200 && getMousePosition().y > 825 &&
                 getMousePosition().y < 825 + 70 ) {
                setBoutonActuel("shop");
                if ( sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                    setModeAffichageJoueur(4);
                }
            }
            break;
        case 2: //Deuxieme sous-menu : Interaction des N decks + interaction cartes seules + interaction modification d'un deck (getAffichageDeck)


            for (int i(0); i < m_jeu.getUsersConnectes()[getGestionUtilisateur()].getDeckModifiable().size(); i++) {
                if ( getMousePosition().x > 300 + 300 * i && getMousePosition().x < 300 + 300 * i + 200 &&
                     getMousePosition().y > 20 && getMousePosition().y < 20 + 40 ) {
                    setBoutonActuel("choixDeck" + std::to_string(i));
                    if ( sf::Mouse::isButtonPressed(sf::Mouse::Left)) {//faire en sorte que les cartes reste affiches
                        if ( getAffichageDeck() == i )
                            setAffichageDeck(-1);
                        else
                            setAffichageDeck(i);
                    }
                }
            }



            if ( getAffichageDeck() != -1 ) {
                if ( getMousePosition().x > 500 && getMousePosition().x < 1250 &&
                     getMousePosition().y > 500 && getMousePosition().y < 500 + 50 ) {
                    setBoutonActuel("changerDeck");
                    if ( sf::Mouse::isButtonPressed(sf::Mouse::Left)) {//faire en sorte que les cartes reste affiches
                        m_jeu.getUsersConnectes()[m_gestionUtilisateur].setDeckActif(getAffichageDeck());
                        std::cout << getAffichageDeck() << std::endl;
                    }
                }

                for (int j(0); j <
                               m_jeu.getUsersConnectes()[getGestionUtilisateur()].getDeckModifiable()[getAffichageDeck()].getCartes().size(); j++) {
                    /* On enleve la carte qui est selectionné et on reload le deck pour l'affichage */

                    /* Ajout dans les cartes seules */
                    if ( getMousePosition().x > 50 + 170 * j && getMousePosition().x < 150 + 50 + 170 * j - 20 &&
                         getMousePosition().y > 700 && getMousePosition().y < 700 + 200 ) {
                        setBoutonActuel("carteDecknum" + std::to_string(j));
                        if ( sf::Mouse::isButtonPressed(sf::Mouse::Left)) {

                            m_jeu.getUsersConnectes()[getGestionUtilisateur()].getCartesSeules().push_back(
                                    m_jeu.getUsersConnectes()[getGestionUtilisateur()].getDeckModifiable()[getAffichageDeck()].getCartes()[j]);
                            m_jeu.getUsersConnectes()[getGestionUtilisateur()].getDeckModifiable()[getAffichageDeck()].getCartes().erase(
                                    m_jeu.getUsersConnectes()[getGestionUtilisateur()].getDeckModifiable()[getAffichageDeck()].getCartes().begin() +
                                    j);
                        }
                    }


                }

                /* Ajout dans le deck */
                for (int j(0); j < m_jeu.getUsersConnectes()[getGestionUtilisateur()].getCartesSeules().size(); j++) {
                    if ( getMousePosition().x > 50 + 170 * j && getMousePosition().x < 150 + 50 + 170 * j - 20 &&
                         getMousePosition().y > 200 && getMousePosition().y < 200 + 200 &&
                         m_jeu.getUsersConnectes()[getGestionUtilisateur()].getDeckModifiable()[getAffichageDeck()].getCartes().size() <
                         10 ) {
                        setBoutonActuel("cartesSeulesnum" + std::to_string(j));
                        if ( sf::Mouse::isButtonPressed(sf::Mouse::Left)) {

                            m_jeu.getUsersConnectes()[getGestionUtilisateur()].getDeckModifiable()[getAffichageDeck()].getCartes().push_back(
                                    m_jeu.getUsersConnectes()[getGestionUtilisateur()].getCartesSeules()[j]);
                            m_jeu.getUsersConnectes()[getGestionUtilisateur()].getCartesSeules().erase(
                                    m_jeu.getUsersConnectes()[getGestionUtilisateur()].getCartesSeules().begin() + j);
                        }
                    }
                }
            }

            break;

        case 3://Creation du deck


            /* Pour le shop */
            if ( getMousePosition().x > 1650 && getMousePosition().x < 1650 + 200 && getMousePosition().y > 20 &&
                 getMousePosition().y < 20 + 70 ) {
                setBoutonActuel("shop");
                if ( sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                    setModeAffichageJoueur(4);
                }
            }

            /* Pour la création du deck */

            for (int j(0); j < m_choixInscription.imm.size(); j++) {

                /* Ajout dans les cartes seules */
                if ( getMousePosition().x > 50 + 170 * j && getMousePosition().x < 150 + 50 + 170 * j - 20 &&
                     getMousePosition().y > 700 && getMousePosition().y < 700 + 200 ) {
                    setBoutonActuel("carteDecknum" + std::to_string(j));
                    if ( sf::Mouse::isButtonPressed(sf::Mouse::Left)) {

                        m_jeu.getUsersConnectes()[getGestionUtilisateur()].getCartesSeules().push_back(
                                m_choixInscription.imm[j]);
                        m_choixInscription.imm.erase(m_choixInscription.imm.begin() + j);
                    }
                }
            }
            /* Ajout dans le deck */
            for (int j(0); j < m_jeu.getUsersConnectes()[getGestionUtilisateur()].getCartesSeules().size(); j++) {
                if ( getMousePosition().x > 50 + 170 * j && getMousePosition().x < 150 + 50 + 170 * j - 20 &&
                     getMousePosition().y > 200 && getMousePosition().y < 200 + 200 &&
                     m_choixInscription.imm.size() < 10 ) {
                    setBoutonActuel("cartesSeulesnum" + std::to_string(j));
                    if ( sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                        m_choixInscription.imm.push_back(
                                m_jeu.getUsersConnectes()[getGestionUtilisateur()].getCartesSeules()[j]);
                        m_jeu.getUsersConnectes()[getGestionUtilisateur()].getCartesSeules().erase(
                                m_jeu.getUsersConnectes()[getGestionUtilisateur()].getCartesSeules().begin() + j);
                    }
                }
            }

            //Vérification du deck
            if ( m_choixInscription.imm.size() == 10 ) {

                m_choixInscription.valide = true;
                if ( getMousePosition().x < 1900 &&
                     getMousePosition().x > 1600 &&
                     getMousePosition().y < 1055 &&
                     getMousePosition().y > 975 ) {
                    setBoutonActuel("Creer");
                    if ( getBoutonActuel() == "Creer" ) {
                        if ( sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                            m_jeu.getUsersConnectes()[getGestionUtilisateur()].getDeckModifiable().push_back(
                                    m_choixInscription.imm);
                            m_choixInscription.imm.clear(); // permet d'éviter de créer 2 fois le meme deck
                            std::cout << "Deck Creer" << std::endl;
                        }

                    }

                }
            }
            break;

        case 4://shop
            // on affiche les differents set
            int i = 1, j = 0, k=0;
            if ( getMousePosition().x > (1100) && getMousePosition().x<(1250) && getMousePosition().y>(50) &&
                 getMousePosition().y < (250)) {

                sf::RectangleShape rectangle;
                rectangle.setSize(sf::Vector2f(150, 200));
                rectangle.setFillColor(sf::Color(255, 255, 255, 30));
                rectangle.setOutlineColor(sf::Color(255, 0, 0, 200));
                rectangle.setOutlineThickness(2);
                rectangle.setPosition(1100, 50);
                getWindow().draw(rectangle);

                if ( sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                    setAffichageCartes(1);
                }
            }
            if ( getAffichageCartes() == 1 ) {
                prix= 30;
                for (auto &elem : m_jeu.getCartesBases().getCreatures()) {
                    if ( i % 6 == 0 ) {
                        i = 0;
                        j++;
                    }
                    i++;
                    if ( getMousePosition().x > (-150 + 170 * i) && getMousePosition().x < (-150 + 170 * i + 150) &&
                         getMousePosition().y > 200 + 220 * j && getMousePosition().y < 200 + 220 * j + 200 ) {
                        setBoutonActuel("cartesShop" + std::to_string(i) + std::to_string(j));
                        if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
                            setImCarteShop(elem.getImmatriculation());
                    }
                }
            }


            if ( getMousePosition().x > (1300) &&
                 getMousePosition().x<(1450) && getMousePosition().y>(50) &&
                 getMousePosition().y < (250)) {//Pour les spéciales

                sf::RectangleShape rectangle;
                rectangle.setSize(sf::Vector2f(150, 200));
                rectangle.setFillColor(sf::Color(255, 255, 255, 30));
                rectangle.setOutlineColor(sf::Color(255, 0, 0, 200));
                rectangle.setOutlineThickness(2);
                rectangle.setPosition(1300, 50);
                getWindow().draw(rectangle);

                if ( sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                    setAffichageCartes(2);
                }
            }
            if ( getAffichageCartes() == 2 ) {
                prix = 20;
                for (auto &elem : m_jeu.getCartesBases().getSpeciales()) {

                    if ( i % 6 == 0 ) {
                        i = 0;
                        j++;
                    }
                    i++;
                    if ( getMousePosition().x > (-150 + 170 * i) &&
                         getMousePosition().x < (-150 + 170 * i + 150) && getMousePosition().y > 200 + 220 * j &&
                         getMousePosition().y < 200 + 220 * j + 200 ) {
                        setBoutonActuel("cartesShop" + std::to_string(i) + std::to_string(j));
                        if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
                            setImCarteShop(elem.getImmatriculation());
                    }
                }
            }

            if ( getMousePosition().x > (1500) &&
                 getMousePosition().x<(1650) && getMousePosition().y>(50) &&
                 getMousePosition().y < (250)) {//Pour les énergies

                sf::RectangleShape rectangle;
                rectangle.setSize(sf::Vector2f(150, 200));
                rectangle.setFillColor(sf::Color(255, 255, 255, 30));
                rectangle.setOutlineColor(sf::Color(255, 0, 0, 200));
                rectangle.setOutlineThickness(2);
                rectangle.setPosition(1500, 50);
                getWindow().draw(rectangle);

                if ( sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                    setAffichageCartes(3);
                }
            }
            if ( getAffichageCartes() == 3 ) {
                prix = 50;
                for (auto &elem : m_jeu.getCartesBases().getEnergies()) {
                    if ( i % 6 == 0 ) {
                        i = 0;
                        j++;
                    }
                    i++;
                    if ( getMousePosition().x > (-150 + 170 * i) && getMousePosition().x < (-150 + 170 * i + 150) &&
                         getMousePosition().y > 200 + 220 * j && getMousePosition().y < 200 + 220 * j + 200 ) {

                        setBoutonActuel("cartesShop" + std::to_string(i) + std::to_string(j));
                        if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
                            setImCarteShop(elem.getImmatriculation());
                    }
                }
            }
            if(getImCarteShop()!=0){
                if(getMousePosition().x > 1000 && getMousePosition().x < 1000+500 && getMousePosition().y >800 &&  getMousePosition().y< 860){
                    setBoutonActuel("curseurAcheter");
                    if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
                        setBoutonActuel("acheter");
                    }

                }
                if(getBoutonActuel()=="acheter"){
                    if (m_jeu.getUsersConnectes()[getGestionUtilisateur()].getArgent()>0) {
                        m_jeu.getUsersConnectes()[getGestionUtilisateur()].setArgent(
                                m_jeu.getUsersConnectes()[getGestionUtilisateur()].getArgent() - prix);
                        m_jeu.getUsersConnectes()[getGestionUtilisateur()].getCartesSeules().push_back(
                                getImCarteShop());
                    }
                }

            }
            break;
    }
    m_jeu.getUsersConnectes()[m_gestionUtilisateur].sauvegardeFichierPseudo();
}



void Menu::menu0Interaction(){

    if (getMousePosition().x<(recupSprite("Jouer_no").getPosition().x + 162) && getMousePosition().x>(
            recupSprite("Jouer_no").getPosition().x) &&
        getMousePosition().y<(recupSprite("Jouer_no").getPosition().y + 43) && getMousePosition().y>(
                recupSprite("Jouer_no").getPosition().y)) {
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
            setMenuActuel(1);
        setBoutonActuel("Jouer");
    }

    else if ((getMousePosition().x<(recupSprite("Regles_no").getPosition().x + 204) && getMousePosition().x>(
            recupSprite("Regles_no").getPosition().x)) &&
             (getMousePosition().y<(recupSprite("Regles_no").getPosition().y + 36) && getMousePosition().y>(
                     recupSprite("Regles_no").getPosition().y))) {
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
            setMenuActuel(2);
        setBoutonActuel("Regles");
    }

    else if (getMousePosition().x<
            (recupSprite("Quitter_no").getPosition().x + 240) && getMousePosition().x>(
            recupSprite("Quitter_no").getPosition().x) &&
             getMousePosition().y<(recupSprite("Quitter_no").getPosition().y + 46) && getMousePosition().y>(
                     recupSprite("Quitter_no").getPosition().y)) {
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
            setMenuActuel(-1);
        setBoutonActuel("Quitter");
    }
    else if (getMousePosition().x<
            (recupSprite("Parametres_no").getPosition().x + 236) && getMousePosition().x>(
            recupSprite("Parametres_no").getPosition().x) &&
             getMousePosition().y<(recupSprite("Parametres_no").getPosition().y + 29) && getMousePosition().y>(
                     recupSprite("Parametres_no").getPosition().y)) {
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)){
            setMenuActuel(3);
        }
        setBoutonActuel("Parametres");
    }



}

void Menu::menu1Interaction() {

    if (getMousePosition().x < recupSprite("connecter_no").getPosition().x + 391 &&
        getMousePosition().x > recupSprite("connecter_no").getPosition().x &&
        getMousePosition().y < recupSprite("connecter_no").getPosition().y + 35 &&
        getMousePosition().y > recupSprite("connecter_no").getPosition().y) {
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
            setMenuActuel(4);
        setBoutonActuel("connecter");
    }

    else if (getMousePosition().x < recupSprite("Inscription_no").getPosition().x + 318 &&
             getMousePosition().x > recupSprite("Inscription_no").getPosition().x &&
             getMousePosition().y < recupSprite("Inscription_no").getPosition().y + 35 &&
             getMousePosition().y > recupSprite("Inscription_no").getPosition().y) {
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)){
            setMenuActuel(5);
        }
        setBoutonActuel("Inscription");
    }
    else if(!btnRetourInteraction(0)){
        //ne fait rien x=)
    }

}

void Menu::menu2Interaction(){
    btnRetourInteraction(0);



}

void Menu::menu3Interaction() {
    if (getMousePosition().x<150+675 && getMousePosition().x>150 &&
        getMousePosition().y<350+35 && getMousePosition().y>350) {
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)){
            setMenuActuel(6);
        }
        setBoutonActuel("Creer une Carte Creature");
    }
    else if (getMousePosition().x<1100+665 && getMousePosition().x>1100 &&
             getMousePosition().y<350+35 && getMousePosition().y>350) {
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)){
            setMenuActuel(7);
        }
        setBoutonActuel("Creer une Carte Speciale");
    }
    else if(!btnRetourInteraction(0))
    {}


}

//Menu connection
void Menu::menu4Interaction(std::string& pseudoCouleur){
    bool fin=false;

    btnRetourInteraction(1);

    unsigned short i=0;
    unsigned short j=0;

    if(getGestionUtilisateur()==-1){
        for(const auto& elem : m_jeu.getUsersPseudo()){

            if(i%10==0&&i!=0){
                i=1;
                j++;
            }

            if (getMousePosition().x>(100+500*j) && getMousePosition().x<(100+500*j+elem.size()*24) &&
                                                                         getMousePosition().y>(200+70*i) && getMousePosition().y<(200+70*i+70) ){
                pseudoCouleur=elem;
                fin=true;
                if (sf::Mouse::isButtonPressed(sf::Mouse::Left)){
                    int x = m_jeu.connectionUser(pseudoCouleur);

                    if(x==0||x==2)
                        setErreur(x);
                }
                break;
            }
            i++;
        }
    }


    if(!fin)
        pseudoCouleur="none";

}

//Menu inscription
void Menu::menu5Interaction() {


    /*BOUTON RETOUR*/
    if(getMousePosition().x < 50 + 270 &&
       getMousePosition().x > 50 &&
       getMousePosition().y < 800+ 46 &&
       getMousePosition().y > 800) {
        setBoutonActuel("Retour");
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)){
            if(m_choixInscription._choixTypeCarte=="none")
                setMenuActuel(1);
            else
                m_choixInscription._choixTypeCarte="none";
        }
    }

    /*SI PSEUDO CORRECT ET BIEN 11 CARTES DANS LE DECK*/
    if(!m_choixInscription.pseudoInscription.empty() && m_choixInscription.imm.size() ==11){
        m_choixInscription.valide=true;

        if(getMousePosition().x < 420+290&&
           getMousePosition().x > 420 &&
           getMousePosition().y < 800 &&
           getMousePosition().y > 720)
        {
            setBoutonActuel("Creer");


            //SI APPUIE SUR CREER
            if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
                bool pseudoDejaExistant=false;

                /*Mettre le pseudo en MAJUSCULE*/
                std::for_each(m_choixInscription.pseudoInscription.begin(), m_choixInscription.pseudoInscription.end(), [](char & c){
                    c = ::toupper(c);
                });

                for(const auto& elem:m_jeu.getUsersPseudo()){

                    if(elem==m_choixInscription.pseudoInscription){
                        pseudoDejaExistant=true;
                        setErreur(3);

                    }
                }
                if(!pseudoDejaExistant)
                {
                    Utilisateur nouv= Utilisateur(m_choixInscription.pseudoInscription);
                    m_jeu.getUsersPseudo().insert(nouv.getPseudo());
                    nouv.creerDatabase(m_choixInscription.imm);
                    setMenuActuel(1);
                }


            }
        }

    }
    else{ //SINON
        m_choixInscription.valide=false;
    }

    /*SI DANS MENU DE BASE D'INSCRIPTION*/
    if(m_choixInscription._choixTypeCarte=="none"){
        if(getMousePosition().x>(1100) && getMousePosition().x<(1250) &&getMousePosition().y>(200) && getMousePosition().y<(400) ){

            if (sf::Mouse::isButtonPressed(sf::Mouse::Left)){
                m_choixInscription._choixTypeCarte="Creature";
            }
        }
        if(getMousePosition().x>(1300) && getMousePosition().x<(1450) &&getMousePosition().y>(200) && getMousePosition().y<(400) ){//Pour les spéciales

            if (sf::Mouse::isButtonPressed(sf::Mouse::Left)){
                m_choixInscription._choixTypeCarte="Speciale";
            }
        }
        if(getMousePosition().x>(1500) && getMousePosition().x<(1650) &&getMousePosition().y>(200) && getMousePosition().y<(400) ){//Pour les énergies

            if (sf::Mouse::isButtonPressed(sf::Mouse::Left)){
                m_choixInscription._choixTypeCarte="Energie";
            }
        }

    }

    /*SI DANS LA LISTE DES CARTES*/
    else{
        if(m_choixInscription._choixTypeCarte=="Creature")/*SI DANS LA LISTE DES CREATURES*/
            choixCreatureInteraction();

        if(m_choixInscription._choixTypeCarte=="Speciale")
            choixSpecialeInteraction();

        if(m_choixInscription._choixTypeCarte=="Energie")
            choixEnergieInteraction();

        /*INTERACTION DU DRAG & DROP*/
        int x1=recupSprite("Rectangle_deck").getPosition().x;
        int y1=recupSprite("Rectangle_deck").getPosition().y;
        int immDrag=m_choixInscription.drag.interaction(x1,y1,1900,220);
        if(immDrag!=666){ //Si ajout de cartes au deck
            if(m_choixInscription.imm.size()<11) //Si moins de 11 cartes
                m_choixInscription.imm.push_back(immDrag);
        }

    }




}

/*Menu création de carte créature*/
void Menu::menu6Interaction(){//menu 6 dans le getMenu
    //rectInscription correspond à l'encadré blanc pour écrire

    //Permet de changer de rectangle
    for(int i=0; i<m_creationCarte.creaCarte.size(); i++){
        if(getMousePosition().x>85 && getMousePosition().x<85+500 && getMousePosition().y>60+150*i && getMousePosition().y < 60+150*i+85)
        {
            if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
                m_creationCarte.section = i;
        }
    }

    //PErmet d'effacer les immatriculations des attaques
    if(m_creationCarte.creaCarte[2].size()==1)
    {
        if(m_creationCarte.creaCarte[2][0] != m_creationCarte.domaine){
            //Efface les attaques
            m_creationCarte.attaque1=0;
            m_creationCarte.attaque2=0;
            m_creationCarte.domaine=m_creationCarte.creaCarte[2][0];
        }
    }
    else{
        //Efface les attaques
        m_creationCarte.attaque1=0;
        m_creationCarte.attaque2=0;
        m_creationCarte.domaine=9;
    }


    //Permet d'ajouter les ataques
    for(int i(0);i<m_jeu.getCartesBases().getAttaques().size()-8;i++){
        auto elem= m_jeu.getCartesBases().getAttaques()[i];

        if((m_creationCarte.domaine-48 == elem.getDomaine())||elem.getDomaine()<0){
            if(getMousePosition().x>1050 && getMousePosition().x< 1050+80 && getMousePosition().y>120+30*i && getMousePosition().y < 120+30*i+25){
                setBoutonActuel("imm"+std::to_string(i));
                if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
                    //Ajoute l'attaque
                    if(m_creationCarte.attaque1==0){
                        if(m_creationCarte.attaque2!=elem.getImmatriculation())
                            m_creationCarte.attaque1=elem.getImmatriculation();
                    }
                    else{
                        if(m_creationCarte.attaque1!=elem.getImmatriculation())
                            m_creationCarte.attaque2=elem.getImmatriculation();
                    }
                }
            }
        }
    }

    //Permet de creer la carte en vérifiant les données
    if(m_creationCarte.creaCarte[0] != "" && m_creationCarte.creaCarte[1] != "" && m_creationCarte.creaCarte[2] != "" && m_creationCarte.creaCarte[3] != ""&& m_creationCarte.attaque1!=0 && m_creationCarte.attaque2!=0){

        if(getMousePosition().x>1700 && getMousePosition().x< 1700+190 && getMousePosition().y>900 && getMousePosition().y < 900+100){
            setBoutonActuel("creer");
            if(sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                //verif si bon domaine
                if (m_creationCarte.creaCarte[2].size() == 1 && m_creationCarte.creaCarte[2][0] >= '0' &&
                    m_creationCarte.creaCarte[2][0] <= '3') {
                    bool pdvOK=true;
                    //Verif si pdv bien des entiers
                    for(int i=0; i<m_creationCarte.creaCarte[3].size(); i++){
                        if(m_creationCarte.creaCarte[3][i]>='0' && m_creationCarte.creaCarte[3][i]<='9'){
                            //OK
                        }
                        else
                            pdvOK=false;
                    }

                    if(pdvOK){
                        int pdv = std::stoi(m_creationCarte.creaCarte[3]);
                        std::vector<Attaque*> _attaques;
                        for(int i=0; i<m_jeu.getCartesBases().getAttaques().size(); i++){
                            if(m_jeu.getCartesBases().getAttaques()[i].getImmatriculation()==m_creationCarte.attaque1 || m_jeu.getCartesBases().getAttaques()[i].getImmatriculation()==m_creationCarte.attaque2){
                                _attaques.push_back(&(m_jeu.getCartesBases().getAttaques()[i]));
                            }
                        }

                        Creature crea = Creature(m_jeu.getCartesBases().getCreaturesModif().size()+100,m_jeu.getCartesBases().getCreaturesModif().size()+100,m_creationCarte.creaCarte[0],m_creationCarte.creaCarte[1], m_creationCarte.domaine-48,pdv,_attaques);
                        m_jeu.getCartesBases().creerCarte(crea,m_jeu.getCartesBases().getCreaturesModif());


                            setMenuActuel(0);


                    }
                    else
                        setErreur(4);


                }
            }

        }


    }



    btnRetourInteraction(3);



}

void Menu::menu7Interaction(){
    //rectInscription correspond à l'encadré blanc pour écrire

    //Permet de changer de rectangle
    for(int i=0; i<m_creationCarte.creaCarte.size(); i++){
        if(getMousePosition().x>85 && getMousePosition().x<85+500 && getMousePosition().y>60+150*i && getMousePosition().y < 60+150*i+85)
        {
            if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
                m_creationCarte.section = i;
        }
    }

    //PErmet d'effacer les immatriculations des attaques
    if(m_creationCarte.creaCarte[2].size()==1)
    {
        if(m_creationCarte.creaCarte[2][0] != m_creationCarte.domaine){
            //Efface les attaques
            m_creationCarte.attaque1=0;
            m_creationCarte.domaine=m_creationCarte.creaCarte[2][0];
        }
    }
    else{
        //Efface les attaques
        m_creationCarte.attaque1=0;
        m_creationCarte.domaine=9;
    }


    //Permet d'ajouter les ataques
    for(int i(0);i<m_jeu.getCartesBases().getAttaques().size()-8;i++){
        auto elem= m_jeu.getCartesBases().getAttaques()[i];

        if((m_creationCarte.domaine-48 == elem.getDomaine())||elem.getDomaine()<0){
            if(getMousePosition().x>1050 && getMousePosition().x< 1050+80 && getMousePosition().y>120+30*i && getMousePosition().y < 120+30*i+25){
                setBoutonActuel("imm"+std::to_string(i));
                if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
                    //Ajoute l'attaque
                    m_creationCarte.attaque1=elem.getImmatriculation();
                }
            }
        }
    }

    //Permet de creer la carte en vérifiant les données
    if(m_creationCarte.creaCarte[0] != "" && m_creationCarte.creaCarte[1] != "" && m_creationCarte.creaCarte[2] != "" && m_creationCarte.creaCarte[3] != ""&& m_creationCarte.creaCarte[4] != ""&& m_creationCarte.attaque1!=0){

        if(getMousePosition().x>1700 && getMousePosition().x< 1700+190 && getMousePosition().y>900 && getMousePosition().y < 900+100){
            setBoutonActuel("creer");
            if(sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                //verif si bon domaine
                if (m_creationCarte.creaCarte[2].size() == 1 && m_creationCarte.creaCarte[2][0] >= '0' &&
                    m_creationCarte.creaCarte[2][0] <= '3') {
                    bool pdvOK=true;
                    //Verif si pdv bien des entiers
                    for(int i=0; i<m_creationCarte.creaCarte[3].size(); i++){
                        if(m_creationCarte.creaCarte[3][i]>='0' && m_creationCarte.creaCarte[3][i]<='9'){
                            //OK
                        }
                        else
                            pdvOK=false;
                    }

                    if(pdvOK){
                        //Si type valide
                        if(m_creationCarte.creaCarte[4].size()==1 && m_creationCarte.creaCarte[4][0]-48 == 0 || m_creationCarte.creaCarte[4][0]-48 == 1){
                            int type=m_creationCarte.creaCarte[4][0]-48;

                            int pdv = std::stoi(m_creationCarte.creaCarte[3]);
                            std::vector<Attaque*> _attaques;

                            for(int i=0; i<m_jeu.getCartesBases().getAttaques().size(); i++){
                                if(m_jeu.getCartesBases().getAttaques()[i].getImmatriculation()==m_creationCarte.attaque1){
                                    _attaques.push_back(&(m_jeu.getCartesBases().getAttaques()[i]));
                                }
                                if(i>=13){
                                    if(m_jeu.getCartesBases().getAttaques()[i].getDomaine()==m_creationCarte.domaine-48){
                                        if(type==0&&m_jeu.getCartesBases().getAttaques()[i].getDegat()==30){ //reine
                                            _attaques.push_back(&(m_jeu.getCartesBases().getAttaques()[i]));
                                        }
                                        else if(type==1&&m_jeu.getCartesBases().getAttaques()[i].getDegat()==25){ //roi
                                            _attaques.push_back(&(m_jeu.getCartesBases().getAttaques()[i]));
                                        }
                                    }
                                }
                            }


                            Speciale spe = Speciale(m_jeu.getCartesBases().getSpecialesModif().size()+200,m_jeu.getCartesBases().getSpecialesModif().size()+200,m_creationCarte.creaCarte[0],m_creationCarte.creaCarte[1], m_creationCarte.domaine-48,pdv,_attaques,type);
                            m_jeu.getCartesBases().creerCarte(spe,m_jeu.getCartesBases().getSpecialesModif());

                            setMenuActuel(0);

                        }
                        else
                            setErreur(5);


                    }
                    else
                        setErreur(4);


                }
            }

        }


    }



    btnRetourInteraction(3);


}


void Menu::choixCreatureInteraction(){
    int i=1,j=0;
    for(const auto& elem : m_jeu.getCartesBases().getCreatures()){
        int x=-65+170*i;
        int y=40+210*j;

        if(!m_choixInscription.drag.getActif()){
            if(getMousePosition().x>(x) && getMousePosition().x<(x+150) &&getMousePosition().y>(y) && getMousePosition().y<(y+200)){
                //Si clique sur la carte
                if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
                    /*Initialisation du drag drop*/
                    m_choixInscription.drag.setActif(true); //Drag drop actif
                    m_choixInscription.drag.setId(elem.getId());
                    m_choixInscription.drag.setImm(elem.getImmatriculation());
                }
            }
        }

        if(i%10==0){
            i=0;
            j++;
        }
        i++;
    }
}

void Menu::choixSpecialeInteraction(){
    int i=1,j=0;
    for(const auto& elem : m_jeu.getCartesBases().getSpeciales()){
        int x=-65+170*i;
        int y=40+210*j;

        if(!m_choixInscription.drag.getActif()){
            if(getMousePosition().x>(x) && getMousePosition().x<(x+150) &&getMousePosition().y>(y) && getMousePosition().y<(y+200)){
                //Si clique sur la carte
                if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
                    /*Initialisation du drag drop*/
                    m_choixInscription.drag.setActif(true); //Drag drop actif
                    m_choixInscription.drag.setImm(elem.getImmatriculation());
                    m_choixInscription.drag.setId(elem.getId());
                }
            }
        }

        if(i%10==0){
            i=0;
            j++;
        }
        i++;
    }
}

void Menu::choixEnergieInteraction(){
    int i=1,j=0;
    for(const auto& elem : m_jeu.getCartesBases().getEnergies()){
        int x=-65+170*i;
        int y=40+210*j;

        if(!m_choixInscription.drag.getActif()){
            if(getMousePosition().x>(x) && getMousePosition().x<(x+150) &&getMousePosition().y>(y) && getMousePosition().y<(y+200)){
                //Si clique sur la carte
                if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
                    /*Initialisation du drag drop*/
                    m_choixInscription.drag.setActif(true); //Drag drop actif
                    m_choixInscription.drag.setImm(elem.getImmatriculation());
                    m_choixInscription.drag.setId(elem.getId());
                }
            }
        }

        if(i%10==0){
            i=0;
            j++;
        }
        i++;
    }
}


bool Menu::btnRetourInteraction(int menuBase){
    //Interaction pour le bouton retour
    if(getMousePosition().x < recupSprite("Retour_no").getPosition().x + 270 &&
       getMousePosition().x > recupSprite("Retour_no").getPosition().x &&
       getMousePosition().y < recupSprite("Retour_no").getPosition().y + 46 &&
       getMousePosition().y > recupSprite("Retour_no").getPosition().y) {

        setBoutonActuel("Retour");
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)){

            if(getGestionUtilisateur()==-1){
                if(getMenuActuel()!=40){ //Si pas affichage du gestion Utilisateur
                    setMenuActuel(menuBase);
                }
            }


            setGestionUtilisateur(-1);


        }
        return true;
    }
  return false;
}

void Menu::interactionDescriptionCarte(){
    if(sf::Mouse::isButtonPressed(sf::Mouse::Right)){
        for(const auto elem : Affichage::getPosCartes()){

            if(getMousePosition().x>=elem.x && getMousePosition().x<=elem.x+150 && getMousePosition().y>=elem.y && getMousePosition().y<=elem.y+200){
                switch(elem.imm/100){
                    case 1://Creéature
                        for(auto& elem2 : m_jeu.getCartesBases().getCreatures()){
                            if(elem.imm==elem2.getImmatriculation()){
                                elem2.afficheDescription();
                                break;
                            }
                        }
                        break;
                    case 2://Spéciales
                        for(auto& elem2 : m_jeu.getCartesBases().getSpeciales()){
                            if(elem.imm==elem2.getImmatriculation()){
                                elem2.afficheDescription();
                                break;
                            }
                        }
                        break;
                    case 3://Energie
                        for(auto& elem2 : m_jeu.getCartesBases().getEnergies()){
                            if(elem.imm==elem2.getImmatriculation()){
                                elem2.afficheDescription();
                                break;
                            }
                        }
                        break;
                }
            }

        }
    }

}