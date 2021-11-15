//
// Created by bemat on 06/11/2020.
//

#ifndef CARDGAME_COLLECTION_H
#define CARDGAME_COLLECTION_H

#include "../biblio.h"

#include "Affichage/Affichage.h"

#include "Cartes/Creature.h"
#include "Cartes/Speciale.h"
#include "Cartes/Energie.h"


class Energie;

class Creature;
class Attaque;
class Speciale;

class Collection {
    private:
        std::vector<Creature> m_creatures;
        std::vector<Energie> m_energies;
        std::vector<Speciale> m_speciales;
        std::vector<Attaque> m_attaques;

    public:
        //Constructeur et destructeur
        Collection();
        ~Collection();

        //Méthodes
        void chargerCartes();
        void chargerCartesFille(const std::string& _nomClassCarte);
        void chargerCreature(int _imm, std::string _nom, std::string _description, const std::string& line, int i, int temp,int _domaine);
        void chargerEnergie(int _imm, std::string _nom, std::string _description, const std::string& line, int i, int temp, int _domaine);
        void chargerSpeciale(int _imm, std::string _nom, std::string _description, const std::string& line, int i, int temp, int _domaine);
        void chargerAttaque(int _imm, std::string _nom, std::string _description, const std::string& line, int i, int temp, int _domaine);
        void lectureVar(std::string& _res, std::string line, int &i, int &temp);

        void ajouterCreature(Creature _carte);
        void ajouterEnergie(Energie _carte);
        void ajouterSpeciale(Speciale _carte);

        std::vector<Creature> getCreatures()const ;
        std::vector<Energie> getEnergies() const;
        std::vector<Speciale> getSpeciales() const;

        std::vector<Speciale>& getSpecialesModif() ;
        std::vector<Creature>& getCreaturesModif() ;


        std::vector<Attaque>& getAttaques();
        void userCreerCarte();

        template <typename T>
        void creerCarte(T _carte, std::vector<T>& vecteur);



        //Accesseur et mutateur



};

#include "collection.tpp"

#endif //CARDGAME_COLLECTION_H
