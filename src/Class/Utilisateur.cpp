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



/*
 * Méthodes
 */

void Utilisateur::creerDatabase(){
    //1: Ajout dans l'utilisateur dans utilisateurs.txt
    std::ifstream fileInput("../database/utilisateurs/utilisateurs.txt");//permet juste de savoir si le fichier existe pour pas en créer un deuxième
    std::ofstream fileOutput("../database/utilisateurs/utilisateurs.txt",std::ios::app);

    if(fileInput.is_open()){//Si le fichier a réussit à s'ouvrir
        fileOutput << std::endl << getPseudo();
        fileOutput.close();//Fermeture du fichier
        fileInput.close();//Fermeture du fichier
    }
    else{
        std::cout << "Impossible d'ouvrir le fichier : utilisateurs.txt " << std::endl;
    }
}

void Utilisateur::chargerUtilisateur(){
    std::string nomFichier = "../database/utilisateurs/cartes/";
    nomFichier+=getPseudo();
    nomFichier+=".txt";
    std::ifstream filePseudo(nomFichier,std::ios::in);
    if(filePseudo.is_open()){//Si le fichier a réussit à s'ouvrir
        std::string line;

        std::getline(filePseudo,line);//1ere ligne ->cartes seules
        std::istringstream ss(line);
        int num;
        while(ss >> num)
        {
            if(num>=100 && num<=399){
                m_cartesSeul.push_back(num);
            }
            else{
                std::cout << "Erreur ce type d'immatriculation ne peut exister ! " <<std::endl;
            }

        }

        //On ajoute les decks : chaque ligne = 1 deck
        while(std::getline(filePseudo,line)){
            std::vector<int> temp;
            std::istringstream ss(line);
            int num;
            while(ss >> num)
            {
                if(num>=100 && num<=399){
                    temp.push_back(num);
                }
                else{
                    std::cout << "Erreur ce type d'immatriculation ne peut exister ! " <<std::endl;
                }

            }

            //Si le deck n'est pas conforme
            //alors on ajoute ces cartes aux cartes seuls
            if(temp.empty()||temp.size()>Deck::getNumCartes()){
                for(int i=0; i<temp.size(); i++){
                    m_cartesSeul.push_back(temp[i]);
                }
            }
            //Si le deck est conforme
            else{
                Deck _deck = Deck(temp);
                m_decks.push_back(_deck);
            }

        }


        filePseudo.close();//Fermeture du fichier
    }
    else{
        std::cout << "Impossible d'ouvrir le fichier : " << getPseudo() <<std::endl;
    }
}
