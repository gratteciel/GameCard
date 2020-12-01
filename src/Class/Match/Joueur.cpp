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

Pioche& Joueur::getPioche(){
    return m_pioche;
}

std::vector<t_carte>& Joueur::getMain(){
    return m_main;
}
Collection& Joueur::getCartes(){
    return m_cartes;
}

void Joueur::setEndroitActu(const std::string& _endroitActu){
    setEtreSurBouton(true);
    m_prop.endroitActu=_endroitActu;
}
std::string Joueur::getEndroitActu() const{
    return m_prop.endroitActu;
}

void Joueur::setEtreSurBouton(const bool& _etreSurBouton){
    m_prop.etreSurBtn=_etreSurBouton;
}
bool Joueur::getEtreSurBouton() const{
    return m_prop.etreSurBtn;
}

unsigned short Joueur::getClignotage() const{
    return m_prop.clignotage;
}

void Joueur::setClignotage(unsigned short _clignotage){
    m_prop.clignotage=_clignotage;
}

DragCarte& Joueur::getDrag(){
    return m_drag;
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

void Joueur::initiatlisationProp(){
    m_prop.aPioche=false;
    getDrag().setActif(false);

    setEndroitActu("none");
    setClignotage(30);
}

void Joueur::piocher(){
    //On ajoute la carte à la main
    getMain().push_back(getPioche().piocher());
    m_prop.aPioche=true;
}

