//
// Created by bemat on 03/11/2020.
//

#ifndef CARDGAME_CARTE_H
#define CARDGAME_CARTE_H

#include "../../biblio.h"

class Carte{
    private:
        std::string m_nom;
        std::string m_description;
        int m_id;
        int m_immatriculation;
        int m_domaine;
    public :
        //Constructeur et destructeur
        Carte(int _immatriculation, int _id);
        Carte(int _immatriculation, int _id, std::string _nom, std::string _description, int domaine);
        virtual ~Carte();

        //Méthodes
        virtual void creer(std::ofstream& fileOutput) = 0;
        virtual void affiche(float x, float y);
        void ajoutCarteDescription(float x, float y);
        void afficheDescriptionCarte(const std::string& _type);
        //Accesseurs et mutateurs
        std::string getNom() const;
        std::string getDescription() const;

        int getId() const;
        int getImmatriculation() const;
        int getDomaine() const;



};


#endif //CARDGAME_CARTE_H
