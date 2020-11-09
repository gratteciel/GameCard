//
// Created by bemat on 04/11/2020.
//

#include "../Headers/Utilisateur.h"

/*
 * Constructeur et destructeur
 */

Utilisateur::Utilisateur(std::string _pseudo)
           :m_pseudo(_pseudo),m_cartesSeul(false)
{

}

Utilisateur::~Utilisateur(){

}
/*
 * Accesseurs et mutateurs
 */

std::string Utilisateur::getPseudo() const {
    return m_pseudo;
}
void Utilisateur::affichageUtilisateur() {
    std::cout << getPseudo();

}



