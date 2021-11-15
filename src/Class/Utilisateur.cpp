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

Deck Utilisateur::getDeck(int _numDeck) const {
    return m_decks[_numDeck];
}

std::vector<Deck>& Utilisateur::getDeckModifiable(){
    return m_decks;
}

std::vector<int>& Utilisateur::getCartesSeules(){
    return m_cartesSeul;
}

void Utilisateur::setDeckActif(int _deckActif)
{
    if(_deckActif>=0 && _deckActif <m_decks.size()){
        m_deckActif = _deckActif;
    }

}

int Utilisateur::getDeckActif() const{
    return m_deckActif;
}

int Utilisateur::getArgent() const {
    return m_argent;
}
void Utilisateur::setArgent(int _argent){
    if(_argent>=0){
        m_argent=_argent;
    }

}


/*
 * Méthodes
 */

int Utilisateur::getNombreDeck() const{
    return m_decks.size();
}

void Utilisateur::affichageUtilisateur() {
    std::cout << getPseudo();
}


void Utilisateur::creerDatabase(const std::vector<int>& _deck0){
    //1: Ajout dans l'utilisateur dans utilisateurs.txt
    std::ifstream fileUtilisateursInput("../database/utilisateurs/utilisateurs.txt");//permet juste de savoir si le fichier existe pour pas en créer un deuxième
    std::ofstream fileUtilisateursOutput("../database/utilisateurs/utilisateurs.txt",std::ios::app);

    if(fileUtilisateursInput.is_open()){//Si le fichier a réussit à s'ouvrir
        fileUtilisateursOutput << std::endl << getPseudo();
        fileUtilisateursOutput.close();//Fermeture du fichier utilisateurs.txt
        fileUtilisateursInput.close();//Fermeture du fichier utilisateurs.txt

        /* Fichier "pseudo.txt" */
        creerFichierPseudo(_deck0);

    }
    else{
        std::cout << "Impossible d'ouvrir le fichier : utilisateurs.txt " << std::endl;
    }
}


/*
 * Création du fichier 'pseudo'.txt
 * Ajout des cartes au fichier
 */
void Utilisateur::creerFichierPseudo(const std::vector<int>& _deck0){
    std::string nomFichierPseudo="../database/utilisateurs/cartes/";
    nomFichierPseudo+=getPseudo();
    nomFichierPseudo+=".txt";

    std::ofstream filePseudoOutput(nomFichierPseudo); //Création du fichier

    if (filePseudoOutput.is_open()) //Si fichier est bien créé
    {
        filePseudoOutput << "0" << std::endl; //Deck de base : 0

        filePseudoOutput << "200"<< std::endl; //Argent de base : 200

        filePseudoOutput << _deck0[10] << std::endl;

        for(unsigned int i=0; i<_deck0.size()-1;i++){
            filePseudoOutput << _deck0[i] << " ";
        }
        filePseudoOutput.close();
    }
    else
        std::cout << "Impossbile d'ouvrir le fichier de :" << getPseudo() << std::endl;
}


void Utilisateur::sauvegardeFichierPseudo(){
    std::string nomFichierPseudo="../database/utilisateurs/cartes/";
    nomFichierPseudo+=getPseudo();
    nomFichierPseudo+=".txt";

    std::ofstream filePseudoOutput(nomFichierPseudo);


    if (filePseudoOutput.is_open()) //Si fichier est bien créé
    {
        /* AJOTUER LA MONEY */
        filePseudoOutput << std::to_string(getDeckActif()) << std::endl; //Aucune carte seules
        filePseudoOutput << std::to_string(getArgent()) << std::endl;


        for(auto& elem:m_cartesSeul){
            filePseudoOutput << std::to_string(elem) << " ";
        }

        for(int i=0; i<getNombreDeck(); i++){
            filePseudoOutput << std::endl;
            for(auto& elem: m_decks[i].getCartes()){
                filePseudoOutput << std::to_string(elem) << " ";
            }
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


        std::getline(filePseudo,line);//1ere ligne ->deck actif

        m_deckActif=std::stoi(line); //set le deck actif de l'utilisateur
                                     //Ici on n'appale pas setDeckActif() car le joueur ne possede pas encore de deck

        std::getline(filePseudo,line);//2eme ligne ->argent
        m_argent = std::stoi(line);


        std::getline(filePseudo,line);//2eme ligne ->cartes seules
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