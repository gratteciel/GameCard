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
        Collection m_collec;
        std::vector<Utilisateur> m_usersConnectes;
        std::vector<std::string> m_usersPseudo;
        Match m_match;

    public:
        //Constructeur et destructeur
        Game();
        ~Game();
        //Méthodes
        void chargerUsersPseudos();
        void connectionUser(std::string _pseudo);


        //Accesseurs et mutateurs
};


#endif //CARDGAME_GAME_H
