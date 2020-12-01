//
// Created by bemat on 25/11/2020.
//

#include "../../Headers/Affichage/Menu.h"

void Menu::interactionPseudoUtilisateurs() {
    unsigned int i=0;
    bool fin=false, decksValides=true;

    for(const auto& elem :m_jeu.getUsersConnectes()){
        if(!elem.second.getDeck(elem.second.getDeckActif()).getDeckActuValide())
            decksValides=false;

        if (getMousePosition().x>(600+250*i) && getMousePosition().x<(600+250*i+elem.first.size()*24) && getMousePosition().y>(970) && getMousePosition().y<(970+70) ){
            fin=true;
            setBoutonActuel(elem.first);

            if (sf::Mouse::isButtonPressed(sf::Mouse::Left)){//Si appuie sur pseudo
                if(getGestionUtilisateur()=="none")
                    setGestionUtilisateur(elem.first);
                else
                    setGestionUtilisateur("none");
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
           else if(bouton!="connecter" && bouton!="Retour" && bouton !="Inscription")
               setBoutonActuel("none");
       }
   }

   /*GESTION DES UTILISATEURS (INTERACTION)*/
   gestionUtilisateurInteraction();
}

void Menu::gestionUtilisateurInteraction(){
    if(getGestionUtilisateur()!="none"){
        if(!btnRetourInteraction(40)){
            if(getMousePosition().x >20&& getMousePosition().x<20+170 && getMousePosition().y >120 &&
               getMousePosition().y<150){
                setBoutonActuel("deconnexion");

                if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
                    m_jeu.deconnexionUser(getGestionUtilisateur());
                    setGestionUtilisateur("none");
                }

            }


        }
    }


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
    else
        setBoutonActuel("none");


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
    else if(!btnRetourInteraction(0))
        setBoutonActuel("none");
}

void Menu::menu2Interaction(){
    if(!btnRetourInteraction(0)){
        setBoutonActuel("none");
    }

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
        setBoutonActuel("none");


}

//Menu connection
void Menu::menu4Interaction(std::string& pseudoCouleur){
    bool fin=false;

    if(!btnRetourInteraction(1)){
        setBoutonActuel("none");
    }


    unsigned short i=0;
    unsigned short j=0;

    if(getGestionUtilisateur()=="none"){
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
    bool surQchose=false;

    /*BOUTON RETOUR*/
    if(getMousePosition().x < 50 + 270 &&
       getMousePosition().x > 50 &&
       getMousePosition().y < 800+ 46 &&
       getMousePosition().y > 800) {
        surQchose=true;
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
            surQchose=true;

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
            surQchose=true;
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left)){
                m_choixInscription._choixTypeCarte="Creature";
            }
        }
        if(getMousePosition().x>(1300) && getMousePosition().x<(1450) &&getMousePosition().y>(200) && getMousePosition().y<(400) ){//Pour les spéciales
            surQchose=true;
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left)){
                m_choixInscription._choixTypeCarte="Speciale";
            }
        }
        if(getMousePosition().x>(1500) && getMousePosition().x<(1650) &&getMousePosition().y>(200) && getMousePosition().y<(400) ){//Pour les énergies
            surQchose=true;
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

    if(!surQchose)
        setBoutonActuel("none");

}

void Menu::menu6Interaction(){//menu 6 dans le getMenu
    //rectInscription correspond à l'encadré blanc pour écrire
    if(getMousePosition().x>85 && getMousePosition().x<85+500 && getMousePosition().y>170 && getMousePosition().y < 170+85)
    {
        m_creationCarte.section = 0;
    }
    else if(getMousePosition().x>85 && getMousePosition().x<85+500 && getMousePosition().y>470 && getMousePosition().y < 470+85)
    {
        m_creationCarte.section = 1;
    }
    else if(getMousePosition().x>85 && getMousePosition().x< 85+500 && getMousePosition().y>770 && getMousePosition().y < 770+85)
    {
        m_creationCarte.section = 2;

    }
    else
        m_creationCarte.section = 3;
    if(m_creationCarte.creaCarte[0] != "" && m_creationCarte.creaCarte[1] != "" && m_creationCarte.creaCarte[2] != ""){
        m_window.draw(chargerTexte("Creer", 0,sf::Color::Green,100,1700,900,sf::Color::Black,2));
        if(getMousePosition().x>1700 && getMousePosition().x< 1700+190 && getMousePosition().y>900 && getMousePosition().y < 900+100){
            if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
                if(m_creationCarte.creaCarte[1].size() <= 3 && m_creationCarte.creaCarte[1] <= "412" && m_creationCarte.creaCarte[1] >= "400" && m_creationCarte.creaCarte[2].size() <= 3 && m_creationCarte.creaCarte[2] <= "412" && m_creationCarte.creaCarte[2] >= "400" && m_creationCarte.creaCarte[1] != m_creationCarte.creaCarte[2]) {

                    // m_jeu.getCartesBases().ajouterCreature(Creature(413,0,m_creationCarte.creaCarte[0],"Description",100,);
                    setMenuActuel(0);
                }
                else
                    setErreur(4);

            }
        }

    }



    if (!btnRetourInteraction(3))
        setBoutonActuel("none");


}

void Menu::menu7Interaction(){
    //rectInscription correspond à l'encadré blanc pour écrire
    if(getMousePosition().x>85 && getMousePosition().x<85+500 && getMousePosition().y>170 && getMousePosition().y < 170+85)
    {
        m_creationCarte.section = 0;
    }
    else if(getMousePosition().x>85 && getMousePosition().x<85+500 && getMousePosition().y>470 && getMousePosition().y < 470+85)
    {
        m_creationCarte.section = 1;
    }
    else if(getMousePosition().x>85 && getMousePosition().x< 85+500 && getMousePosition().y>770 && getMousePosition().y < 770+85)
    {
        m_creationCarte.section = 2;

    }
    else
        m_creationCarte.section = 3;
    if(m_creationCarte.creaCarte[0] != "" && m_creationCarte.creaCarte[1] != "" && m_creationCarte.creaCarte[2] != ""){
        m_window.draw(chargerTexte("Creer", 0,sf::Color::Green,100,1700,900,sf::Color::Black,2));
        if(getMousePosition().x>1700 && getMousePosition().x< 1700+190 && getMousePosition().y>900 && getMousePosition().y < 900+100){
            if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
                if(m_creationCarte.creaCarte[1].size() <= 3 && m_creationCarte.creaCarte[1] <= "420" && m_creationCarte.creaCarte[1] >= "400" && m_creationCarte.creaCarte[2].size() <= 3 && m_creationCarte.creaCarte[2] <= "420" && m_creationCarte.creaCarte[2] >= "400" && m_creationCarte.creaCarte[1] != m_creationCarte.creaCarte[2]) {
                    // m_jeu.getCartesBases().ajouterCreature(Creature(413,0,m_creationCarte.creaCarte[0],"Description",100,);
                    setMenuActuel(0);
                }
                else
                    setErreur(4);

            }
        }

    }



    if (btnRetourInteraction(3))
        setBoutonActuel("none");


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

            if(getGestionUtilisateur()=="none"){
                if(getMenuActuel()!=40){ //Si pas affichage du gestion Utilisateur
                    setMenuActuel(menuBase);
                }
            }


            setGestionUtilisateur("none");

            setBoutonActuel("none");
        }
        return true;
    }
  return false;
}

void Menu::interactionDescriptionCarte(){
    if(sf::Mouse::isButtonPressed(sf::Mouse::Right)){
        for(const auto elem : Affichage::getPosCartes()){
            if(getMousePosition().x>=elem.x && getMousePosition().x<=elem.x+150 && getMousePosition().y>=elem.y && getMousePosition().y<=elem.y+200){
                //m_jeu.getCartesBases().getCreatures()[0].afficheDescription();
                std::cout << elem.imm << std::endl;
            }
        }
    }

}