//
// Created by bemat on 05/11/2020.
//

#include "../Headers/Game.h"

/*
 * Constructeur et destructeur
 */
Game::Game(){
    chargerUsersPseudos();
    m_collec.chargerCartes();
}

Game::~Game() {

}
/*
 * Accesseurs et mutateurs
 */

/*
 * Méthodes
 */

void Game::chargerUsersPseudos(){
    std::ifstream file ("../database/utilisateurs/utilisateurs.txt");

    if(file.is_open()){
        std::cout << "fichier ouvert : utilisateurs.txt" << std::endl;
        std::string line;

        while(std::getline(file,line)){
            m_usersPseudo.push_back(line);

        }

        file.close(); //fermuture du fichier
    }
    else{
        std::cout << "Impossible d'ouvrir le fichier : utilisateurs.txt"<< std::endl;
    }

}

void Game::connectionUser(std::string _pseudo){
    Utilisateur _temp = Utilisateur(_pseudo);

    //On charge ses cartes et ses decks
    _temp.chargerUtilisateur();

    //On ajoute l'utilisateur au vecteur d'users connectés
    m_usersConnectes.push_back(_temp);
}
 
 