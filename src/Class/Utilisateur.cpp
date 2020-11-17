//
// Created by bemat on 04/11/2020.
//

#include "../Headers/Utilisateur.h"

/*
 * Constructeur et destructeur
 */

Utilisateur::Utilisateur(std::string _pseudo)
           :m_pseudo(_pseudo)
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

void Utilisateur::affichageUtilisateur() {
    std::cout << getPseudo();
}

void Utilisateur::creerDatabase(const std::vector<int> _cartesSeuls){
    //1: Ajout dans l'utilisateur dans utilisateurs.txt
    std::ifstream fileUtilisateursInput("../database/utilisateurs/utilisateurs.txt");//permet juste de savoir si le fichier existe pour pas en créer un deuxième
    std::ofstream fileUtilisateursOutput("../database/utilisateurs/utilisateurs.txt",std::ios::app);

    if(fileUtilisateursInput.is_open()){//Si le fichier a réussit à s'ouvrir
        fileUtilisateursOutput << std::endl << getPseudo();
        fileUtilisateursOutput.close();//Fermeture du fichier utilisateurs.txt
        fileUtilisateursInput.close();//Fermeture du fichier utilisateurs.txt

        /* Fichier "pseudo.txt" */
        creerFichierPseudo(_cartesSeuls);

    }
    else{
        std::cout << "Impossible d'ouvrir le fichier : utilisateurs.txt " << std::endl;
    }
}


/*
 * Création du fichier 'pseudo'.txt
 * Ajout des cartes au fichier
 */
void Utilisateur::creerFichierPseudo(const std::vector<int> _cartesSeuls){
    std::string nomFichierPseudo="../database/utilisateurs/cartes/";
    nomFichierPseudo+=getPseudo();
    nomFichierPseudo+=".txt";

    std::ofstream filePseudoOutput(nomFichierPseudo); //Création du fichier

    if (filePseudoOutput.is_open()) //Si fichier est bien créé
    {
        for(const auto& elem : _cartesSeuls){
            filePseudoOutput << elem << " ";
        }
        filePseudoOutput.close();
    }
    else
        std::cout << "Impossbile d'ouvrir le fichier de :" << getPseudo() << std::endl;
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