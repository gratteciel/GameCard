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

std::map<std::string, Utilisateur> Game::getUsersConnectes() const{
    return m_usersConnectes;
}
std::set<std::string> Game::getUsersPseudo() const{
    return m_usersPseudo;
}

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

bool Game::connectionUser(const std::string& _pseudo){
    if(m_usersConnectes.size()>=2){
        std::cout << "Game::connectionUser : deja 2 joueurs connectes! " << std::endl;
        return false;
    }

    //Vérifie si le user est deja connecté
    if(m_usersConnectes.find(_pseudo)!=m_usersConnectes.end()){
        return false;
    }


    //Vérifie si le pseudo "input" existe dans la liste des pseudos
    if(m_usersPseudo.find(_pseudo)!=m_usersPseudo.end()){
        Utilisateur _temp = Utilisateur(_pseudo);

        //On charge ses cartes et ses decks
        _temp.chargerUtilisateur();

        //On ajoute l'utilisateur au vecteur d'users connectés
        m_usersConnectes.insert(std::pair<std::string,Utilisateur>(_pseudo,_temp));
        return true; //l'utilisateur est connecté

    }

    std::cout << "Game::connectionUser : le pseudo n'existe pas " << std::endl;
    return false;

}

void Game::lancerMatch(std::string user1, std::string user2){
    auto it1=m_usersConnectes.find(user1);
    auto it2=m_usersConnectes.find(user2);

    //Vérification si ils existent
    if(it1!= m_usersConnectes.end() &&  it2 != m_usersConnectes.end()){
        m_match.lancementMatch(&it1->second, &it2->second, m_cartesBases);
    }
}


