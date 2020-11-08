//
// Created by bemat on 07/11/2020.
//

#ifndef CARDGAME_SPECIALE_H
#define CARDGAME_SPECIALE_H

#include "Carte.h"

class Speciale : public Carte {
    private:

    public:
        //Constructeur et destructeur
        Speciale(int _immatriculation);
        Speciale(int _immatriculation, int _id, std::string _nom, std::string _description);
        ~Speciale();

        //Méthodes
        void afficheDescription();
        //Accesseurs et mutateurs
};


#endif //CARDGAME_SPECIALE_H
