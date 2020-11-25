//
// Created by bemat on 05/11/2020.
//

#ifndef CARDGAME_GAME_H
#define CARDGAME_GAME_H

#include "../biblio.h"

#include "Utilisateur.h"
#include "Collection.h"
#include "Match/Match.h"

class Game {

    private:
        Collection m_cartesBases;
        std::map<std::string, Utilisateur> m_usersConnectes;
        std::set<std::string> m_usersPseudo;
        Match m_match;

    public:
        //Constructeur et destructeur
        Game();
        ~Game();
        //Méthodes
        void chargerUsersPseudos();
        unsigned short connectionUser(const std::string& _pseudo);
        void lancerMatch(std::string user1, std::string user2);

        //Accesseurs et mutateurs
        std::map<std::string, Utilisateur> getUsersConnectes() const;
        std::set<std::string> getUsersPseudo() const;
};


#endif //CARDGAME_GAME_H
