//
// Created by bemat on 05/11/2020.
//

#ifndef CARDGAME_JOUEUR_H
#define CARDGAME_JOUEUR_H

#include "../Utilisateur.h"
#include "Pioche.h"



class Joueur {
private:
    int m_pdv;
    Utilisateur *m_user;


    Collection m_cartes;

    t_carte m_enjeu;
    std::vector<int> m_ptEnergie;

    Pioche m_pioche;
    t_carte m_active;
    std::vector<t_carte> m_main;
    std::vector<t_carte> m_cimetiere;
    std::vector<t_carte> m_cartesEnergie;

public:
    //Constructeur et destructeur
    Joueur(Utilisateur *_user);
    ~Joueur();

    //Méthodes
    void tour();

    //Accesseurs et mutateurs
    int getPdv()const;
    Utilisateur* getUser()const;
    void setPioche(const Collection& _cartesBase);
    void setCartes(const Collection& _cartesBase);



};


#endif //CARDGAME_JOUEUR_H
