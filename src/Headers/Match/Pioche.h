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


    public:
        //Constructeur et destructeur
        Pioche();
        ~Pioche();

        //Méthodes
        void chargerPioche(std::vector<int> _cartes);
        std::deque<t_carte> getCartesId() const;
        t_carte piocher();
        t_carte melanger();
        void swap(t_carte& a, t_carte& b);
        //Accesseurs et mutateurs

};


#endif //CARDGAME_PIOCHE_H
