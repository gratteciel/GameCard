//
// Created by bemat on 03/11/2020.
//

#ifndef CARDGAME_CARTE_H
#define CARDGAME_CARTE_H

#include "../../../biblio.h"

class Carte{
    private:
        std::string m_nom;
        std::string m_description;
        int m_id;
        int m_immatriculation;
    public :
        //Constructeur et destructeur
        Carte(int _immatriculation);
        Carte(int _immatriculation, int _id, std::string _nom, std::string _description);
        virtual ~Carte();

        //Méthodes
        // il va falloir metre une méthode virtuelle = 0
        virtual void afficheDescription() = 0;
        //Accesseurs et mutateurs
        std::string getNom() const;
        std::string getDescription() const;

        int getId() const;
        int getImmatriculation() const;
};


#endif //CARDGAME_CARTE_H
