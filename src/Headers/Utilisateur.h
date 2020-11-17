//
// Created by bemat on 04/11/2020.
//

#ifndef CARDGAME_UTILISATEUR_H
#define CARDGAME_UTILISATEUR_H

#include "../biblio.h"
#include "Cartes/Deck.h"
#include <sstream>

class Utilisateur {
    private:
        //Atrributs
        std::string m_pseudo;
        std::vector<Deck> m_decks;
        std::vector<int> m_cartesSeul;//Ici sont stockés les immatriculations des cartes qui n'ont pas de deck


        //Méthodes privées
        void creerFichierPseudo(const std::vector<int> _cartesSeuls);


    public:
        //Constructeur et destructeur
        Utilisateur(std::string _pseudo);
        ~Utilisateur();

        //Méthodes
        void chargerUtilisateur();
        void creerDatabase(const std::vector<int> _cartesSeuls);

        void affichageUtilisateur();

        //Accesseurs et mutateurs
        std::string getPseudo() const;
};


#endif //CARDGAME_UTILISATEUR_H
