//
// Created by bemat on 07/11/2020.
//

#ifndef CARDGAME_SPECIALE_H
#define CARDGAME_SPECIALE_H

#include "Creature.h"
class Creature;

class Speciale : public Creature{
    private:
        int m_type; //0 reine  //1 roi  //2 défence
    public:
        //Constructeur et destructeur

        Speciale(int _immatriculation, int _id, std::string _nom, std::string _description,int _domaine, int _pdVInitial, std::vector<Attaque*> _attaques, int _type);
        ~Speciale();

        //Méthodes
        void affiche(float x, float y);
        void creer(std::ofstream& fileOutput);
        void afficheAttaques(const int& _terrainActuel);
        void afficheDescription();
        void afficheRoiReineDescription(int xBase, int yBase);

        //Accesseurs et mutateurs
        int getType() const;
};


#endif //CARDGAME_SPECIALE_H
