//
// Created by mitue on 07/11/2020.
//

#include "../../Headers/Match/Match.h"
Match::Match(){

}
Match::Match(Utilisateur *_user1, Utilisateur *_user2, int _numDeck1, int _numDeck2)
{
    m_joueur.push_back(Joueur(_user1,_numDeck1));// on insere les differents joueurs en faisant insert(Joueur(utilisateur1, deck1));
    m_joueur.push_back(Joueur(_user2,_numDeck2));

}
Match::~Match() {

}

void Match::lancementmatch() {
    std::cout << "Le match commence"<<std::endl;
    getPlateau().affichageplateau();

}
Plateau Match::getPlateau() const {
    return m_plateau;
}