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

    std::vector<t_carte> m_cimetiere;
    std::vector<t_carte> m_cartesEnergie;

public:
    //Constructeur et destructeur
    Joueur(Utilisateur *_user);
    ~Joueur();

    //Méthodes
    void piocher();

    void afficheMain(bool _ennemie);
    void interactionMain();
    void afficherSurTerrain();
    bool interaction();
    void initiatlisationProp();
    bool interactionFinTour();
    void interactionFromMainToActive();
    void afficheActives(bool _ennemie);
    void interactionPioche();
    void afficheFinTour();
    void afficheModeEnnemie();
    void afficheNom(bool ennemie);
    void affichePioche();
    void affichePtsEnergies(int x, int y, int taille, bool ennemie);
    void afficheCimetiere();
    //Accesseurs et mutateurs
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

};


#endif //CARDGAME_JOUEUR_H
