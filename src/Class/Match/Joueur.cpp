//
// Created by bemat on 05/11/2020.
//

#include "../../Headers/Match/Joueur.h"

/*
 * Constructeur et destructeur
 */

Joueur::Joueur(Utilisateur *_user)
       :m_user(_user), m_pdv(100)
{
    for(int i=0; i<4; i++)
        m_ptEnergie.push_back(0);

    t_carte temp;
    temp.id=-1;
    temp.imm=-1;

    m_enjeu=temp;
    m_active=temp;
}

Joueur::~Joueur(){


}

/*
 * Accesseurs et mutateurs
 */


int Joueur::getPdv() const {
    return m_pdv;
}
Utilisateur* Joueur::getUser() const {
    return m_user;
}

void Joueur::setPioche(const Collection& _cartesBase){
    m_pioche.chargerPioche(getUser()->getDeck(getUser()->getDeckActif()).getCartes());
    setCartes(_cartesBase);

    m_enjeu = m_pioche.melanger();

}


/*
 * Méthodes
 */

void Joueur::setCartes(const Collection& _cartesBase){


    for(const auto& elem : m_pioche.getCartesId()){
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
                std::cout << "Erreur : Joueur::setCartes" << std::endl;
        }
    }
}

void Joueur::tour(){
    bool choix=true;//a changer
    bool aPioche=false;
    char a;
    while(!choix){
        std::cin >> a;

        switch(a){
            case 'P':
                if(!aPioche){
                    m_main.push_back(m_pioche.piocher());
                    aPioche=true;
                }
                break;

        }



    }




}