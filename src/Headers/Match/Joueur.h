//
// Created by bemat on 05/11/2020.
//

#ifndef CARDGAME_JOUEUR_H
#define CARDGAME_JOUEUR_H

#include "../Utilisateur.h"
#include "Pioche.h"
#include "../../Headers/Cartes/DragCarte.h"


typedef struct t_propJoueur{
    std::string endroitActu;
    bool aPioche;
    bool etreSurBtn;
    unsigned short clignotage;
    int numAttaque;
    t_carte propChoixAttaquer;
    int affichePtsEnergies;
}t_propJoueur;

class Joueur {
private:
    t_propJoueur m_prop;
    int m_pdv;
    Utilisateur *m_user;

    Collection m_cartes;

    t_carte m_enjeu;
    std::vector<int> m_ptEnergie;

    Pioche m_pioche;
    std::vector<t_carte> m_actives;

    std::vector<t_carte> m_main;
    DragCarte m_drag;


    std::vector<t_carte> m_cartesEnergie;
    int m_quitter;
public:
    //Constructeur et destructeur
    Joueur(Utilisateur *_user);
    ~Joueur();

    //Méthodes
    void initiatlisationProp();

    void afficheMain(bool _ennemie);
    void interactionMain();
    void afficheModeEnnemie();

    void afficherSurTerrain(int _ennemieActives, const int& _terrainActuel);
    int interaction(Joueur& _ennemie, std::vector<int>& _cimetiere, int& _typeTerrain);


    bool interactionFinTour();
    void afficheFinTour();

    void interactionFromMainToActive(int& _typeTerrain);
    void afficheActives(bool _ennemie, int _ennemieActive=0);
    void interactionActives();

    void interactionChoixAttaque(Joueur& _ennemie, std::vector<int>& _cimetiere,const int& _typeTerrain);
    void attaquer(int i,Joueur& _ennemie, std::vector<int>& _cimetiere,const int& _typeTerrain);
    void specialAttaque(Joueur& _ennemie, std::vector<int>& _cimetiere, int posAllie=42);
    void afficheChoixAttaque(int _ennemieActives);
    void afficheAttaques(const int& _terrainActuel);

    void interactionPioche();
    void affichePioche();
    void piocher();

    void afficheNom(bool ennemie);

    void affichePtsEnergies(int x, int y, int taille, bool ennemie);

    void verifSiDead(Joueur& _ennemie, std::vector<int>& _cimetiere);
    bool verifIfPossedeEnergies(int posAttaque);
    void diminuEnergieAfterAttaque(int posAttaque);
    bool quitterOuPas();
    void afficheQuitter();

    void incrementerClignotage();
    void interactionPtsEnergies(Joueur& _ennemie);
    //Accesseurs et mutateurs

    std::vector<t_carte>& getActives();
    int getPdv()const;
    Utilisateur* getUser()const;
    void setPioche(const Collection& _cartesBase);
    Pioche& getPioche();
    void setCartes(const Collection& _cartesBase);
    DragCarte& getDrag();
    std::vector<t_carte>& getMain();

    Collection& getCartes();

    void setEndroitActu(const std::string& _endroitActu);
    std::string getEndroitActu()const;
    void setEtreSurBouton(const bool& _etreSurBouton);
    bool getEtreSurBouton() const;

    unsigned short getClignotage() const;
    void setClignotage(unsigned short _clignotage);
    std::vector<int>& getPtsEnergies();
    void setQuitter(int _nb);
    int getQuitter() const;
    void setAffichePtsEnergies(int _affichePtsEnergies);
};


#endif //CARDGAME_JOUEUR_H
