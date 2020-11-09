//
// Created by bemat on 06/11/2020.
//

#ifndef CARDGAME_PIOCHE_H
#define CARDGAME_PIOCHE_H


#include "../../../biblio.h"
#include "../Collection.h"

typedef struct t_carte{
   int key;
   int id;
}t_carte;

class Pioche {
    private:
        //Une unique clé
        //       clé   id
        std::deque<t_carte> m_cartesId;
        Collection m_cartes;

    public:

        Pioche();
        ~Pioche();

        //Constructeur et destructeur

        //Méthodes

        //Accesseurs et mutateurs
};


#endif //CARDGAME_PIOCHE_H
