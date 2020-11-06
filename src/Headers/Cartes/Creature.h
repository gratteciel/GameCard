//
// Created by bemat on 03/11/2020.
//

#ifndef CARDGAME_CREATURE_H
#define CARDGAME_CREATURE_H


#include "Carte.h"
#include "Attaque.h"


class Creature : public Carte{
    private:
        short m_pdv; //point de vie
        short m_pdvInitial; //pdv initial
        bool m_vivant; //pour savoir la carte est encore en vie
        //Ici il faudra mettre le tableau d'attaque
        std::vector<Attaque> m_attaques;

    public:
        //Constructeur et destructeur
        Creature(int _id);
        ~Creature();

        //Méthodes
        void afficheDescription();
        //Accesseurs et mutateurs
        short getPdv() const;
        void setPdv(short _pdv);

        short getPdvInitial() const;//pas de setters : initialisation dans le constructeur

        bool getVivant() const;
        void setVivant(bool _vivant);

};


#endif //CARDGAME_CREATURE_H
