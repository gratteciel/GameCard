//
// Created by bemat on 05/11/2020.
//

#ifndef CARDGAME_GAME_H
#define CARDGAME_GAME_H

#include "../biblio.h"

#include "Utilisateur.h"
#include "Collection.h"
#include "Match/Match.h"
#include "Affichage/AfficheMatch.h"

class Game {

    private:
        Collection m_cartesBases;
        std::vector<Utilisateur> m_usersConnectes;
        std::set<std::string> m_usersPseudo;
        AfficheMatch m_affichageMatch;

    public:
        //Constructeur et destructeur
        Game();
        ~Game();
        //Méthodes
        void chargerUsersPseudos();
        unsigned short connectionUser(const std::string& _pseudo);
        void deconnexionUser(const int& posUser);
        void lancerMatch();

        //Accesseurs et mutateurs
        std::vector<Utilisateur>& getUsersConnectes();
        std::set<std::string>& getUsersPseudo();
        Collection getCartesBases() const;
        AfficheMatch& getAffichageMatch();
};


#endif //CARDGAME_GAME_H
