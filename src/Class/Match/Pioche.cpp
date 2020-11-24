//
// Created by bemat on 06/11/2020.
//

#include "../../Headers/Match/Pioche.h"

/*
 * Constructeur et destructeur
 */
Pioche::Pioche() {

}
Pioche::~Pioche() {

}
/*
 * Accesseurs et mutateurs
 */

std::deque<t_carte> Pioche::getCartesId() const{
    return m_cartesId;
}

/*
 * Méthodes
 */

/*
 * Permet de charger la pioche
 * ->Charge les cartes de l'utilisateur dans la pioche du joueur
 * Parametre 1 : carte du deck 'numDeck' du user
 * Parametre 2 : Collection de cartes du deck 'numDeck' de user
 */
void Pioche::chargerPioche(std::vector<int> _cartes){

    for(unsigned int i=0; i<_cartes.size(); i++) {
        t_carte temp;

        temp.imm = _cartes[i];
        temp.id = i;

        //On remplit le tableau d'entiers de cartes (immatriculation + id)
        m_cartesId.push_back(temp);

    }
}

/*
 * Permet de mélanger la pioche
 * renvoie l'enjeu
 */
t_carte Pioche::melanger(){
    int taille=m_cartesId.size();

    for(const auto& elem: m_cartesId){
        int a=rand()%(taille);
        int b=rand()%(taille);
        swap(m_cartesId[a], m_cartesId[b]);
    }
   t_carte enjeu=m_cartesId.front();

   m_cartesId.pop_front();

   return enjeu;
}

t_carte Pioche::piocher(){
    t_carte temp=m_cartesId.front();
    m_cartesId.pop_front();
    return temp;
}

void Pioche::swap(t_carte& a, t_carte& b){
    t_carte temp=a;
    a=b;
    b=temp;
}
 
 