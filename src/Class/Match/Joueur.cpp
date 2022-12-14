//
// Created by bemat on 05/11/2020.
//

#include "../../Headers/Match/Joueur.h"



/*
 * Constructeur et destructeur
 */

Joueur::Joueur(Utilisateur *_user)
       :m_user(_user), m_pdv(150),m_statueLoose(0)
{
    for(int i=0; i<4; i++)
        m_ptEnergie.push_back(0);

    t_carte temp;
    temp.id=-1;
    temp.imm=-1;

    m_enjeu=temp;

    m_prop.propChoixAttaquer.id=-1;
    m_prop.propChoixAttaquer.imm=-1;
    m_prop.numAttaque=-1;
    setDefense(false);
}

Joueur::~Joueur(){


}

/*
 * Accesseurs et mutateurs
 */


int Joueur::getPdv() const {
    return m_pdv;
}

void Joueur::setPdv(int _pdv){
    m_pdv = _pdv;
    if(_pdv <=0)
        setStatueLoose(2); //Plus de PDV

}

int Joueur::getStatueLoose() const { //1 : plus de carte qui puissent attaquer
                                     //2 : plus de pdv
    return m_statueLoose;
}

void Joueur::setStatueLoose(int _statueLoose) {
    m_statueLoose = _statueLoose;
}

Utilisateur* Joueur::getUser() {
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

std::vector<t_carte>& Joueur::getActives() {
    return m_actives;
}

std::vector<int>& Joueur::getPtsEnergies() {
    return m_ptEnergie;
}

void Joueur::setQuitter(int _nb){
    m_quitter=_nb;
}
int Joueur::getQuitter() const{
    return m_quitter;
}

void Joueur::setAffichePtsEnergies(int _affichePtsEnergies) {
    m_prop.affichePtsEnergies=_affichePtsEnergies;
}

bool Joueur::getDefense() const{
    return m_defense;
}
void Joueur::setDefense(bool _defense){
    m_defense=_defense;
}

void Joueur::setNbAttaques(int _nbAttaques){
    m_nbAttaques=_nbAttaques;
}

int Joueur::getNbAttaques() const{
    return m_nbAttaques;
}

t_carte Joueur::getEnjeu() const{
    return m_enjeu;
}
/*
 * M??thodes
 */


void Joueur::setCartes(const Collection& _cartesBase){


    for(const auto& elem : m_pioche.getCartesId()){
        switch(elem.imm/100){
            case 1: //Cr??ature
                for(auto& elem2 : _cartesBase.getCreatures()){
                    if(elem2.getImmatriculation()==elem.imm){
                        m_cartes.ajouterCreature(Creature(elem.imm, elem.id, elem2.getNom(), elem2.getDescription(),elem2.getDomaine(), elem2.getPdvInitial(),elem2.getAttaques()));

                        break;
                    }
                }
                break;
            case 2: //Speciale
                for(auto& elem2 : _cartesBase.getSpeciales()){
                    if(elem2.getImmatriculation()==elem.imm){
                        m_cartes.ajouterSpeciale(Speciale(elem.imm, elem.id, elem2.getNom(), elem2.getDescription(),elem2.getDomaine(), elem2.getPdvInitial(),elem2.getAttaques(),elem2.getType()));
                        break;
                    }
                }
                break;
            case 3: //Energie
                for(const auto& elem2 : _cartesBase.getEnergies()){
                    if(elem2.getImmatriculation()==elem.imm){
                        m_cartes.ajouterEnergie(Energie(elem.imm, elem.id, elem2.getNom(), elem2.getDescription(),elem2.getDomaine(), elem2.getDomaine2()));
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
    m_prop.doitRepiocher=false;
    getDrag().setActif(false);
    m_prop.propChoixAttaquer.id=-1;
    m_prop.propChoixAttaquer.imm=-1;
    m_prop.numAttaque=-1;

    setEndroitActu("none");
    setClignotage(30);
    setQuitter(0);
    m_prop.affichePtsEnergies=0;
    setDefense(false);
    setNbAttaques(0);
}

void Joueur::piocher(){
    if(getPioche().getCartes().size()>0){ //Si il reste des cartes dans la picohe
        //On ajoute la carte ?? la main
        if(m_prop.doitRepiocher){

            getPioche().getCartes().push_back(getMain()[getMain().size()-1]);
            getMain().pop_back();

            m_prop.doitRepiocher=false;
        }
        getMain().push_back(getPioche().piocher());


        m_prop.aPioche=true;
    }

}

bool Joueur::possedeAtleastUneActive(){
    if(m_actives.empty()){ //Si il n'y a aucune carte active
        bool possedeCartesPouvantAttaquer = false;

        //V??rifie que l'utilisateur possede dans sa main des cartes qui peuvent attaquer ( Cr??ature ou Sp??ciale)
        for(auto elem : m_main){
            if((elem.imm>=100 && elem.imm<=299)&& elem.imm !=208){//208 = carte sp??ciale d??fense
                possedeCartesPouvantAttaquer=true;//Le joueur peut alors poser une carte sur le terrain
                m_prop.doitRepiocher=false;
                break;
            }
        }

        //Si possede aucune carte dans sa main pouvant attaquer alors il peut repiocher si il a une carte pouvant attaquer dans sa pioche
        if(!possedeCartesPouvantAttaquer){
            bool aDansSaMainBonneCarte=false;
            for(auto& elem: getPioche().getCartes()) {
                if ((elem.imm >= 100 && elem.imm <= 299) && elem.imm != 208) {//208 = carte sp??ciale d??fense
                    aDansSaMainBonneCarte = true;//Le joueur possede alors dans sa pioche une carte pouvant attaquer
                    break;
                }
            }

            if(!aDansSaMainBonneCarte)//Si ne possede aucune carte dans sa pioche pouvant attaquer alors il a perdu
                setStatueLoose(1);
            else{

                m_prop.doitRepiocher=true;
            }


        }

        if(getMain().empty())
            m_prop.doitRepiocher=false;

        return false;
    }


    else{
        m_prop.doitRepiocher=false;
        return true;
    }


}


void Joueur::incrementerClignotage(){
    if(getClignotage()>=50)
        setClignotage(0);

    setClignotage(getClignotage()+1);
}


void Joueur::verifSiDead(Joueur& _ennemie, std::vector<int>& _cimetiere){
    /*VERIFIE SI DES CARTES SONT MORTES ET LES MET DANS LE CIMETIERE SI C'EST LE CAS*/
    for(int i=0; i<_ennemie.getActives().size(); i++){
        switch(_ennemie.getActives()[i].imm/100){//type
            case 1://cr??ature
                for(auto& elem2 : _ennemie.getCartes().getCreaturesModif()){
                    if(_ennemie.getActives()[i].id==elem2.getId()){
                        if(!elem2.getVivant()){
                            _ennemie.getActives().erase(_ennemie.getActives().begin()+i);//On le supprime de ses cartes actives

                            //On ajoute la carte au cimmetiere
                            _cimetiere.push_back(elem2.getImmatriculation());
                        }
                    }
                }
            case 2:{//Sp??ciale
                for(auto& elem2 : _ennemie.getCartes().getSpecialesModif()){
                    if(_ennemie.getActives()[i].id==elem2.getId()){
                        if(!elem2.getVivant()){
                            _ennemie.getActives().erase(_ennemie.getActives().begin()+i);//On le supprime de ses cartes actives

                            //On ajoute la carte au cimmetiere
                            _cimetiere.push_back(elem2.getImmatriculation());
                        }
                    }
                }
            }
        }

    }
}

bool Joueur::verifIfPossedeEnergies(int posAttaque){
    bool possedeBien=true;
    switch(m_prop.propChoixAttaquer.imm/100){//Type de la carte
        case 1://Cr??ature
            for(auto& elem: getCartes().getCreaturesModif()){
                if(m_prop.propChoixAttaquer.id==elem.getId()){
                    for(int i=0; i<4; i++){
                        if(getPtsEnergies()[i]<elem.getAttaques()[posAttaque]->getNbPoints()[i].nbPoints){
                            possedeBien=false;
                            return false;
                        }
                    }

                }
            }
            break;
        case 2://Sp??ciale
            for(auto& elem: getCartes().getSpecialesModif()){
                if(m_prop.propChoixAttaquer.id==elem.getId()){
                    for(int i=0; i<4; i++){
                        if(getPtsEnergies()[i]<elem.getAttaques()[posAttaque]->getNbPoints()[i].nbPoints){
                            possedeBien=false;
                            return false;
                        }
                    }

                }
            }
            break;

    }
    if(possedeBien)
        return true;
}

void Joueur::diminuEnergieAfterAttaque(int posAttaque){

    switch(m_prop.propChoixAttaquer.imm/100){//Type de la carte
        case 1://Cr??ature
            for(auto& elem: getCartes().getCreaturesModif()){
                if(m_prop.propChoixAttaquer.id==elem.getId()){
                    for(int i=0; i<4; i++){
                        m_ptEnergie[i]-=elem.getAttaques()[posAttaque]->getNbPoints()[i].nbPoints;
                    }
                    break;
                }
            }
            break;
        case 2://Sp??ciale
            for(auto& elem: getCartes().getSpecialesModif()){
                if(m_prop.propChoixAttaquer.id==elem.getId()){
                    for(int i=0; i<4; i++){
                        m_ptEnergie[i]-=elem.getAttaques()[posAttaque]->getNbPoints()[i].nbPoints;
                    }
                    break;
                }
            }
            break;
    }

}

