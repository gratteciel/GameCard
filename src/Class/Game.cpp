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

std::vector<Utilisateur>& Game::getUsersConnectes(){
    return m_usersConnectes;
}
std::set<std::string>& Game::getUsersPseudo(){
    return m_usersPseudo;
}

Collection& Game::getCartesBases(){
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
    for(int i=0; i<getUsersConnectes().size() ; i++){
        Utilisateur elem =getUsersConnectes()[i];
        if(elem.getPseudo()==_pseudo)
            return 2;
    }


    //Vérifie si le pseudo "input" existe dans la liste des pseudos
    if(m_usersPseudo.find(_pseudo)!=m_usersPseudo.end()){
        Utilisateur _temp = Utilisateur(_pseudo);

        //On charge ses cartes et ses decks
        _temp.chargerUtilisateur();

        //On ajoute l'utilisateur au vecteur d'users connectés
        m_usersConnectes.push_back(_temp);

        return 1; //l'utilisateur est connecté

    }

    std::cout << "Game::connectionUser : le pseudo n'existe pas " << std::endl;
    return 3;

}


void Game::deconnexionUser(const int& _posUser){

    //Ici sauvegarder les éventuels changements

    //Suppression de la vecteur m_userConnectes
    m_usersConnectes.erase(m_usersConnectes.begin()+_posUser);


}

void Game::lancerMatch(){

    m_affichageMatch.lancement(&(m_usersConnectes[0]), &(m_usersConnectes[1]), m_cartesBases);

}



