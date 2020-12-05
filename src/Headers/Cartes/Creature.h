//
// Created by bemat on 03/11/2020.
//

#ifndef CARDGAME_CREATURE_H
#define CARDGAME_CREATURE_H


#include "Carte.h"
#include "Attaque.h"



class Creature : public Carte{
    private:
        int m_pdv; //point de vie
        int m_pdvInitial; //pdv initial
        bool m_vivant; //pour savoir la carte est encore en vie
        //Ici il faudra mettre le tableau d'attaque
        std::vector<Attaque*> m_attaques;


    public:

        //Constructeur et destructeur

        Creature(int _immatriculation, int _id, std::string _nom, std::string _description,int _domaine, int _pdVInitial, std::vector<Attaque*> _attaques);

        ~Creature();

        //Méthodes

        virtual void creer(std::ofstream& fileOutput);
        virtual void affiche(float x, float y);

        virtual void afficheDescription();
        virtual void afficheAttaques(const int& _terrainActuel);
        void afficheAttaqueConsommation(int xBase, int yBase, int i);
        void afficheAttaqueNom(int xBase, int yBase, int i);
        void afficheAttaqueDeBase(int i, const int& _terrainActuel);
        void afficheAttaqueImage(int xBase, int yBase);
        void afficheDescriptionHerited();
        void afficheDegat(int xBase,int yBase,int i);
        //Accesseurs et mutateurs
        int getPdv() const;
        void setPdv(int _pdv);

        int getPdvInitial() const;//pas de setters : initialisation dans le constructeur

        bool getVivant() const;
        void setVivant(bool _vivant);
        std::vector<Attaque*> getAttaques();


};


#endif //CARDGAME_CREATURE_H
