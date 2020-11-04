//
// Created by bemat on 03/11/2020.
//

#ifndef CARDGAME_CARTE_H
#define CARDGAME_CARTE_H

#include <string>
#include <iostream>
#include <vector>

class Carte{
    protected:
        std::string m_nom;
        std::string m_description;
    public :
        //Constructeur et destructeur
        Carte(std::string _nom, std::string _description);
        virtual ~Carte();

        //Méthodes
        // il va falloir metre une méthode virtuelle = 0

        //Accesseurs et mutateurs
        std::string getNom() const;
        std::string getDescription() const;

};


#endif //CARDGAME_CARTE_H
