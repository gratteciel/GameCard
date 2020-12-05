//
// Created by bemat on 07/11/2020.
//

#ifndef CARDGAME_SPECIALE_H
#define CARDGAME_SPECIALE_H

#include "Creature.h"
class Creature;

class Speciale : public Creature{
    private:
        bool m_roi;
    public:
        //Constructeur et destructeur

        Speciale(int _immatriculation, int _id, std::string _nom, std::string _description,int _domaine, int _pdVInitial, std::vector<Attaque*> _attaques, bool _roi);
        ~Speciale();

        //Méthodes
        void affiche(float x, float y);
        void creer(std::ofstream& fileOutput);
        void afficheAttaques(const int& _terrainActuel);
        void afficheDescription();
        void afficheRoiReineDescription(int xBase, int yBase);

        //Accesseurs et mutateurs
        bool getRoi() const;
};


#endif //CARDGAME_SPECIALE_H
