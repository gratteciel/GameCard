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
std::set<std::string>& Game::getUsersPseudo(){
    return m_usersPseudo;
}

Collection Game::getCartesBases() const{
    return m_cartesBases;
}

AfficheMatch& Game::getAffichageMatch(){
    return m_affichageMatch;
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

unsigned short Game::connectionUser(const std::string& _pseudo){
    if(m_usersConnectes.size()>=2){
        std::cout << "Game::connectionUser : deja 2 joueurs connectes! " << std::endl;
        return 0;
    }

    //Vérifie si le user est deja connecté
    if(m_usersConnectes.find(_pseudo)!=m_usersConnectes.end()){
        return 2;
    }


    //Vérifie si le pseudo "input" existe dans la liste des pseudos
    if(m_usersPseudo.find(_pseudo)!=m_usersPseudo.end()){
        Utilisateur _temp = Utilisateur(_pseudo);

        //On charge ses cartes et ses decks
        _temp.chargerUtilisateur();

        //On ajoute l'utilisateur au vecteur d'users connectés
        m_usersConnectes.insert(std::pair<std::string,Utilisateur>(_pseudo,_temp));

        return 1; //l'utilisateur est connecté

    }

    std::cout << "Game::connectionUser : le pseudo n'existe pas " << std::endl;
    return 3;

}


void Game::deconnexionUser(const std::string& _pseudo){

    //Ici sauvegarder les éventuels changements

    //Suppression de la map m_userConnectes
    auto it=m_usersConnectes.find(_pseudo);
    m_usersConnectes.erase(it);
}

void Game::lancerMatch(){
    std::vector<std::string> users;
    //Recuperation des pseudos des joeurs connectés
    for(const auto& elem : m_usersConnectes){
        users.push_back(elem.first);
    }
    auto it1=m_usersConnectes.find(users[0]);
    auto it2=m_usersConnectes.find(users[0]);

    //Vérification si ils existent
    if(it1!= m_usersConnectes.end() &&  it2 != m_usersConnectes.end()){
        m_affichageMatch.lancement(&it1->second, &it2->second, m_cartesBases);
    }
}



