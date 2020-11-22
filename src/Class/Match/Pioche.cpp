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

void Pioche::setCartes(const Collection& _cartesBase){


    for(const auto& elem : m_cartesId){
        switch(elem.imm/100){
            case 1: //Créature
                for(auto& elem2 : _cartesBase.getCreatures()){
                    if(elem2.getImmatriculation()==elem.imm){
                        m_cartes.ajouterCreature(Creature(elem.imm, elem.id, elem2.getNom(), elem2.getDescription(), elem2.getPdvInitial(),elem2.getAttaques()));

                        break;
                    }
                }
                break;
            case 2: //Speciale
                for(const auto& elem2 : _cartesBase.getSpeciales()){
                    if(elem2.getImmatriculation()==elem.imm){
                        m_cartes.ajouterSpeciale(Speciale(elem.imm, elem.id, elem2.getNom(), elem2.getDescription()));
                        break;
                    }
                }
                break;
            case 3: //Energie
                for(const auto& elem2 : _cartesBase.getEnergies()){
                    if(elem2.getImmatriculation()==elem.imm){
                        m_cartes.ajouterEnergie(Energie(elem.imm, elem.id, elem2.getNom(), elem2.getDescription(),elem2.getDomaine()));
                        break;
                    }
                }
                break;
            default:
                std::cout << "Erreur : Pioche::setCartes" << std::endl;
        }
    }


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
void Pioche::chargerPioche(std::vector<int> _cartes, const Collection& _cartesBase){

    for(unsigned int i=0; i<_cartes.size(); i++) {
        t_carte temp;

        temp.imm = _cartes[i];
        temp.id = i;

        //On remplit le tableau d'entiers de cartes (immatriculation + id)
        m_cartesId.push_back(temp);


    }
    setCartes(_cartesBase);



}

 
 