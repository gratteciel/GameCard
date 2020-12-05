//
// Created by bemat on 04/11/2020.
//

#ifndef CARDGAME_UTILISATEUR_H
#define CARDGAME_UTILISATEUR_H

#include "../biblio.h"
#include "Cartes/Deck.h"


class Utilisateur {
    private:
        //Atrributs
        std::string m_pseudo;
        std::vector<Deck> m_decks;
        std::vector<int> m_cartesSeul;//Ici sont stockés les immatriculations des cartes qui n'ont pas de deck
        int m_deckActif;


        //Méthodes privées
        void creerFichierPseudo(const std::vector<int>& _deck0);


    public:
        //Constructeur et destructeur
        Utilisateur(std::string _pseudo);
        ~Utilisateur();

        //Méthodes
        void chargerUtilisateur();
        void creerDatabase(const std::vector<int>& _deck0);
        void sauvegardeFichierPseudo();
        void affichageUtilisateur();

        //Accesseurs et mutateurs
        int getNombreDeck() const;
        std::string getPseudo() const;
        Deck getDeck(int _numDeck) const;
        void setDeckActif(int _deckActif);
        int getDeckActif() const;

        std::vector<Deck>& getDeckModifiable();
        std::vector<int>& getCartesSeules();
};


#endif //CARDGAME_UTILISATEUR_H
