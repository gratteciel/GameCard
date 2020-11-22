//
// Created by bemat on 05/11/2020.
//

#include "../Headers/Game.h"

/*
 * Constructeur et destructeur
 */
Game::Game(){
    chargerUsersPseudos();
    m_cartesBases.chargerCartes();
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
            m_usersPseudo.insert(line);
        }

        file.close(); //fermuture du fichier
    }
    else{
        std::cout << "Impossible d'ouvrir le fichier : utilisateurs.txt"<< std::endl;
    }
}

bool Game::connectionUser(std::string _pseudo){


    //Vérifie si le user est deja connecté
    for(const auto& elem : m_usersConnectes){
        if(_pseudo == elem.getPseudo()) {//si déja connecté
            std::cout << "Game::connectionUser : Deja connecte " << std::endl;
            return false;
        }
    }


    //Vérifie si le pseudo "input" existe dans la liste des pseudos
    if(m_usersPseudo.find(_pseudo)!=m_usersPseudo.end()){
        Utilisateur _temp = Utilisateur(_pseudo);

        //On charge ses cartes et ses decks
        _temp.chargerUtilisateur();

        //On ajoute l'utilisateur au vecteur d'users connectés
        m_usersConnectes.push_back(_temp);
        return true; //l'utilisateur est connecté

    }

    std::cout << "Game::connectionUser : le pseudo n'existe pas " << std::endl;
    return false;

}
 
void Game::lancerMatch(int user1, int user2){
    if(user1>=0 && user1<m_usersConnectes.size()){ //Vérifie si l'utilisateur est bien connecté
        m_match.lancementMatch(&(m_usersConnectes[user1]), &(m_usersConnectes[user2]), m_cartesBases);
    }

}