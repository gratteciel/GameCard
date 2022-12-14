//
// Created by bemat on 24/11/2020.
//

#ifndef CARDGAME_MENU_H
#define CARDGAME_MENU_H
#include "Affichage.h"
#include "../Game.h"
#include "AfficheMatch.h"

#include "../Cartes/DragCarte.h"

typedef struct t_inscription{
    std::string _choixTypeCarte;
    std::string pseudoInscription;
    std::vector<int> imm;
    DragCarte drag;
    bool valide;
}t_inscription;

typedef struct t_booleen{
    bool fin;
    bool sleep;
    bool ancienEchap;
    bool ancienClick;
}t_booleen;

typedef struct t_creationCarte{
    int section;
    std::vector<std::string> creaCarte;
    int attaque1;
    int attaque2;
    char domaine;
}t_creationCarte;

typedef struct t_intro{
    std::string mot;
    sf::Sound sound;
    sf::SoundBuffer soundBuffer;
    short pos;
}t_intro;

class Menu : public Affichage {
private:
    int m_menuActuel;
    std::string m_boutonActuel;
    Game m_jeu;
    int m_gestionUtilisateur;
    t_inscription m_choixInscription;
    int m_erreur;
    t_booleen m_bool;
    int m_mode; //=0 : Menu //=1 : Jeu //=2 : Start
    t_creationCarte m_creationCarte;
    t_intro m_intro;
    int m_affichageDeck;
    int m_modeAffichageJoueur;
    int m_affichageCartes;
    int m_immCarteShop;

public:
    //Constructeur et destructeur
    Menu();
    ~Menu();

    //Methodes
    void introJeu();
    void gestionChangementMenu();
    void gestionInputCarac(sf::Event& event);
    void affichePseudoUtilisateurs();
    void interactionPseudoUtilisateurs();
    void contrerResterAppuye();
    void interactionDescriptionCarte();

    void menuInit(int& temp);
    void menuBase(std::string& pseudoCouleur);
    void boucleBase();
    void menuBaseAffichage(const std::string& pseudoCouleur);
    void initIntro();
    void menu0Init();
    void menu0Interaction();
    void menu0Affichage();

    void menu1Affichage();
    void menu1Interaction();
    void menu1Init();

    void menu2Affichage();
    void menu2Interaction();
    void menu2Init();

    void menu3Affichage();
    void menu3Interaction();
    void menu3Init();

    void menu4Affichage(const std::string& pseudoCouleur);
    void menu4Interaction(std::string& pseudoCouleur);
    void menu4Init();

    void menu5Affichage();
    void menu5Interaction();
    void menu5Init();

    void menu6Init();
    void menu6Affichage();
    void menu6Interaction();

    void menu7Init();
    void menu7Affichage();
    void menu7Interaction();

    void afficheAttaqueCreationCarte();

    void gestionUtilisateurAffichage();
    void gestionUtilisateurInteraction();

    void gestionInteractionDeckJoueur();
    void gestionAffichageDeckJoueur();

    void choixCreatureAffichage();
    void choixCreatureInteraction();

    void choixSpecialeInteraction();
    void choixSpecialeAffichage();

    void choixEnergieInteraction();
    void choixEnergieAffichage();

    void btnRetourAffichage();
    bool btnRetourInteraction(int menuBase);

    void affichePermuterJoueurs();

    void sfmlLeave();
    void erreur();
    void sleep();



    //Getter et Setter

    int getImCarteShop()const;
    void setImCarteShop(int _immCarteShop);
    void setMenuActuel(int _menuActuel);
    int getMenuActuel() const;
    void setBoutonActuel(const std::string& _boutonActuel);
    std::string getBoutonActuel() const;
    void setErreur(int _erreur);
    int getErreur() const;
    int getGestionUtilisateur() const;
    void setGestionUtilisateur(int a);
    int getMode() const;
    void setMode(int _mode);

    t_booleen getBool() const;
    void setAffichageDeck(int _affichageDeck);
    int getAffichageDeck() const;

    int getModeAffichageJoueur()const;
    void setModeAffichageJoueur(int _modeAffichageJoueur);

    int getAffichageCartes()const;
    void setAffichageCartes(int _modeAffichageJoueur);
};


#endif //CARDGAME_MENU_H
