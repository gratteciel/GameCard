//
// Created by bemat on 06/11/2020.
//

#ifndef CARDGAME_PIOCHE_H
#define CARDGAME_PIOCHE_H


#include "../../biblio.h"
#include "../Collection.h"

typedef struct t_carte{
   int imm;
   int id;
}t_carte;

class Pioche {
    private:
        //Une unique clé
        //       immatricuation   id
        std::deque<t_carte> m_cartesId;
        Collection m_cartes;

    public:
        Pioche();
        ~Pioche();

        //Constructeur et destructeur

        //Méthodes
        void chargerPioche(std::vector<int> _cartes, const Collection& _cartesBase);
        void setCartes(const Collection& _cartesBase);
        //Accesseurs et mutateurs
        void setCartes(int type, t_carte temp);
};


#endif //CARDGAME_PIOCHE_H
