//
// Created by bemat on 24/11/2020.
//

#ifndef CARDGAME_MENU_H
#define CARDGAME_MENU_H
#include "Affichage.h"
#include "../Game.h"

class Menu : public Affichage {
private:
    int m_menuActuel;
    std::string m_boutonActuel;
    Game m_jeu;
public:
    //Constructeur et destructeur
    Menu();
    ~Menu();

    //Methodes
    void gestionChangementMenu();

    void sfmlMenuBase();

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

    void sfmlLeave();

    void creerUneCarte();






    //Getter et Setter

    void setMenuActuel(int _menuActuel);
    int getMenuActuel() const;
    void setBoutonActuel(const std::string& _boutonActuel);
    std::string getBoutonActuel() const;



};


#endif //CARDGAME_MENU_H
