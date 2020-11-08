//
// Created by bemat on 06/11/2020.
//

#include "../Headers/Collection.h"

/*
 * Constructeur et destructeur
 */

Collection::Collection() {


}

Collection::~Collection() {

}


/*
 * Méthodes
 */

void Collection::chargerCartes() {
    chargerCartesFille("creatures");
    chargerCartesFille("energies");
    chargerCartesFille("speciales");
}

void Collection::lectureVar(std::string &sImm, std::string line, int &i, int &temp){
    for(i=temp; line[i]!='*';i++){
        sImm+=line[i];
    }
    i++;
    temp=i;
}


void Collection::chargerCartesFille(const std::string& _nomClassCarte){
    std::string _nomFichier = "../database/cartes/";
    int type=0,nbCartes=0, _imm=0;

    _nomFichier += _nomClassCarte;
    _nomFichier+= ".txt";
    std::ifstream file (_nomFichier);

    if(_nomClassCarte == "creatures")
        type=1;
    else if(_nomClassCarte == "speciales")
        type=2;
    else if(_nomClassCarte == "energies")
        type=3;


    if(file.is_open()){
        std::cout << "fichier ouvert : " << _nomClassCarte << std::endl;
        std::string line;

        while(std::getline(file,line)){

            std::string _nom, _description;
            int i=0,temp=0;
            std::string sImm;//immatriculation de type string

            lectureVar(sImm, line, i, temp);
            lectureVar(_nom, line, i, temp);
            lectureVar(_description,line,i,temp);

            _imm=std::stoi(sImm);

            switch(type){
                case 1: //Créature
                    chargerCreature(_imm,_nom,_description,line,i,temp);
                    break;
                case 2: //Spéciale
                    chargerSpeciale(_imm,_nom,_description,line,i,temp);
                    break;
                case 3: //Energie
                    chargerEnergie(_imm,_nom,_description,line,i,temp);
                    break;
                default:
                    break;
            }
            nbCartes++;
        }

        file.close(); //fermuture du fichier
        setNbCartes(nbCartes,type); //On set le nombre de cartes selon le type
    }
    else{
        std::cout << "Impossible d'ouvrir le fichier : " << _nomClassCarte << std::endl;
    }
}

void Collection::chargerCreature(int _imm, std::string _nom, std::string _description, const std::string& line, int i, int temp) {
    std::string sPdvI;
    lectureVar(sPdvI, line, i, temp);
    //Ici il faut ajouter LES ATTAQUES

    //Ajout de la carte au vecteur contenant un exemplaire de chaque carte creature du jeu
    m_creaturesBase.push_back(Creature(_imm,0,_nom,_description,std::stoi(sPdvI)));
}

void Collection::chargerEnergie(int _imm, std::string _nom, std::string _description, const std::string& line, int i, int temp) {
    std::string sDomaine;//string du domaine
    lectureVar(sDomaine, line, i, temp);
    char _domaine=sDomaine[0];//conversion du string en char

    //Ajout de la carte au vecteur contenant un exemplaire de chaque carte energie du jeu
    m_energiesBase.push_back(Energie(_imm,0,_nom,_description,_domaine));
}

void Collection::chargerSpeciale(int _imm, std::string _nom, std::string _description, const std::string& line, int i, int temp) {
    //Ajouteur tous les attributs à speciale

    //Ajout de la carte au vecteur contenant un exemplaire de chaque carte energie du jeu
    m_specialesBase.push_back(Speciale(_imm,0,_nom,_description));
}



/*
 * Permet d'ajouter une carte Creature dans le jeu:
 *  1.ajout dans le fichier creatures.txt
 *  2.ajout dans le vecteur créature
 */
void Collection::creerCarteType(Creature c,std::ofstream& fileOutput){
    //1: Ajout dans le fichier creature
    fileOutput << std::endl << std::to_string(c.getImmatriculation()) <<"*" << c.getNom() <<"*" << c.getDescription() << "*" << std::to_string(c.getPdvInitial()) << "*";
    //2: Ajout dans le vecteur créature
    m_creaturesBase.push_back(Creature(c.getImmatriculation(),0,c.getNom(),c.getDescription(),c.getPdvInitial()));
    setNbCartes(getNbCartes().creature + 1,1);//le nombre de carte augmente
};

/*
 * Permet d'ajouter une carte Energie dans le jeu:
 *  1.ajout dans le fichier energies.txt
 *  2.ajout dans le vecteur energie
 */
void Collection::creerCarteType(Energie c,std::ofstream& fileOutput){
    //1: Ajout dans le fichier energie
    fileOutput << std::endl << std::to_string(c.getImmatriculation()) <<"*" << c.getNom() <<"*" << c.getDescription() << "*" << c.getDomaine() << "*";

    //2: Ajout dans le vecteur énergie
    m_energiesBase.push_back(Energie(c.getImmatriculation(),0,c.getNom(),c.getDescription(),c.getDomaine()));
    setNbCartes(getNbCartes().energie+1,3);//le nombre de carte augmente
};

/*
 * Permet d'ajouter une carte Speciale dans le jeu:
 *  1.ajout dans le fichier speciales.txt
 *  2.ajout dans le vecteur speciale
 */
void Collection::creerCarteType(Speciale c,std::ofstream& fileOutput){
    //1: Ajout dans le fichier energie
    fileOutput << std::endl << std::to_string(c.getImmatriculation()) <<"*" << c.getNom() <<"*" << c.getDescription() << "*";

    //2: Ajout dans le vecteur énergie
    m_specialesBase.push_back(Speciale(c.getImmatriculation(),0,c.getNom(),c.getDescription()));
    setNbCartes(getNbCartes().speciale+1,2);//le nombre de carte augmente
};

/*
 * Permet à n'importe quel utilisateur d'ajouter une carte dans le jeu:
 * L'utilisateur clique sur l'interface allegro pour choisir la carte qu'il veut
 * avec les bons paramètres selon la carte
 */
void Collection::userCreerCarte(){
    int type=0;
    //La il peut cliquer sur le type qu'il veut

    switch(type){
        case 1: //Créature
            //Il choisit les paramètres pour la creature
            //L'immatriculation est choisi selon le nombre de carte créature dans le jeu + une verif dans le vecteur si jamais l'immatriculation choisi existe
            //Si elle existe on fait un truc plus compliqué pour la choisir
            //creerCarte(Creature);
            break;
        case 2: //Sépciale
            //Pareil que pour creature
            //creerCarte(Speciale);
            break;
        case 3: //Energie
            //Pareil que pour Creature
            //creerCarte(Energie);
            break;
        default :
            //Beug
            break;
    }


}

/*
 * Accesseur et mutateur
 */

void Collection::setNbCartes(int _nb, int type){
    if(_nb>=0){
        switch(type){
            case 1:
                m_nbCartes.creature = _nb;
                break;
            case 2:
                m_nbCartes.speciale = _nb;
                break;
            case 3:
                m_nbCartes.energie = _nb;
                break;
            default:
                break;
        }
    }

}

t_nbCartes Collection::getNbCartes() const{
    return m_nbCartes;
};