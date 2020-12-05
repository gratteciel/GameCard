//
// Created by mitue on 07/11/2020.
//

#ifndef CARDGAME_MATCH_H
#define CARDGAME_MATCH_H



#include "Joueur.h"
#include "Plateau.h"
#include "../../biblio.h"



class Match {
private:
    //Plateau m_plateau;
    std::vector<Joueur> m_joueur;//set de joueur  car pas le meme nom
    int m_typeTerrain;
    int m_joueurActuel;
    std::vector<int> m_cimetiere;

public:
    //Constructeurs et Destructeurs
    Match();

    ~Match();

    //Méthodes
    void lancementMatch(Utilisateur *_user1, Utilisateur *_user2, const Collection &_cartesBase);

    int interaction();

    void permuterJoueur();

    //Getter et Setter

    void setJoueur(Utilisateur *_user);

    void setTypeTerrain(int _typeTerrain);

    int getTypeTerrain() const;

    int getJoueurActuel() const;

    void setJoueurActuel(int _joueurActuel);

    Joueur &getJoueur();

    Joueur &getJoueurEnnemie();

    std::vector<Joueur> &getJoueurs();
    std::vector<int>& getCimetiere();
};
#endif //CARDGAME_MATCH_H