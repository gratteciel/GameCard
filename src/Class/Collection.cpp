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

    chargerCartesFille("attaques");

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
    int type=0, _imm=0, _domaine=0;

    _nomFichier += _nomClassCarte;
    _nomFichier+= ".txt";
    std::ifstream file (_nomFichier);

    if(_nomClassCarte == "creatures")
        type=1;
    else if(_nomClassCarte == "speciales")
        type=2;
    else if(_nomClassCarte == "energies")
        type=3;
    else if(_nomClassCarte == "attaques")
        type=4;

    if(file.is_open()){
        std::string line;

        while(std::getline(file,line)){

            std::string _nom, _description;
            int i=0,temp=0;
            std::string sImm;//immatriculation de type string

            lectureVar(sImm, line, i, temp);
            lectureVar(_nom, line, i, temp);
            lectureVar(_description,line,i,temp);

            std::string sDomaine;//string du domaine
            lectureVar(sDomaine, line, i, temp);
            char _domaine=sDomaine[0];//conversion du string en char

            _imm=std::stoi(sImm);


            switch(type){
                case 1: //Créature
                    chargerCreature(_imm,_nom,_description,line,i,temp, _domaine-48);
                    break;
                case 2: //Spéciale
                    chargerSpeciale(_imm,_nom,_description,line,i,temp, _domaine-48);
                    break;
                case 3: //Energie
                    chargerEnergie(_imm,_nom,_description,line,i,temp, _domaine-48);
                    break;
                case 4: //Attaque
                    chargerAttaque(_imm,_nom,_description,line,i,temp, _domaine-48);
                    break;
                default:
                    break;
            }

        }

        file.close(); //fermuture du fichier

    }
    else{
        std::cout << "Impossible d'ouvrir le fichier : " << _nomClassCarte << std::endl;
    }
}

void Collection::chargerCreature(int _imm, std::string _nom, std::string _description, const std::string& line, int i, int temp, int _domaine) {
    std::string sPdvI;
    lectureVar(sPdvI, line, i, temp);

    //Ici il faut ajouter LES ATTAQUES
    std::vector<Attaque*> _attaques;
    std::string sAttaques;
    lectureVar(sAttaques, line, i, temp);
    std::istringstream ss(sAttaques);
    int num;
    while(ss >> num)
    {
        if(num>=400 && num<=499){ //Si bien attaque
            for(auto& elem :m_attaques){
                if(num==elem.getImmatriculation()){
                    _attaques.push_back(&elem);
                }
            }
        }
        else{
            std::cout << "Collection::chargerCreature Erreur ce type d'immatriculation d'attaque ne peut exister ! " <<std::endl;
        }
    }

    //Ajout de la carte au vecteur contenant un exemplaire de chaque carte creature du jeu
    m_creatures.push_back(Creature(_imm,_imm,_nom,_description,_domaine,std::stoi(sPdvI), _attaques));
}

void Collection::chargerEnergie(int _imm, std::string _nom, std::string _description, const std::string& line, int i, int temp, int _domaine) {
    std::string sDomain2;//string du domaine
    lectureVar(sDomain2, line, i, temp);
    char _domaine2=sDomain2[0];//conversion du string en char

    //Ajout de la carte au vecteur contenant un exemplaire de chaque carte energie du jeu
    m_energies.push_back(Energie(_imm,_imm,_nom,_description,_domaine,_domaine2-48));
}

void Collection::chargerSpeciale(int _imm, std::string _nom, std::string _description, const std::string& line, int i, int temp, int _domaine) {
    //Ajouteur tous les attributs à speciale
    std::string sPdvI;
    lectureVar(sPdvI, line, i, temp);

    //Ici il faut ajouter LES ATTAQUES
    std::vector<Attaque*> _attaques;
    std::string sAttaques;
    lectureVar(sAttaques, line, i, temp);
    std::istringstream ss(sAttaques);
    int num;
    while(ss >> num)
    {
        if(num>=400 && num<=499){ //Si bien attaque
            for(auto& elem :m_attaques){
                if(num==elem.getImmatriculation()){
                    _attaques.push_back(&elem);
                }
            }
        }
        else{
            std::cout << "Collection::chargerSpeciale Erreur ce type d'immatriculation d'attaque ne peut exister ! " <<std::endl;
        }
    }

    std::string sRoi;//string du Roi
    bool _roi;
    lectureVar(sRoi, line, i, temp);

    if(sRoi=="0")
        _roi =false;
    else
        _roi =true;


    //Ajout de la carte au vecteur contenant un exemplaire de chaque carte speciale du jeu
    m_speciales.push_back(Speciale(_imm,_imm,_nom,_description,_domaine,std::stoi(sPdvI), _attaques, _roi));
}

void Collection::chargerAttaque(int _imm, std::string _nom, std::string _description, const std::string& line, int i, int temp, int _domaine) {
    std::string sDegat;
    lectureVar(sDegat, line, i, temp);

    std::string sDomaines;

    std::vector<t_nbPoints> _nbPoints;


    lectureVar(sDomaines, line, i, temp);


    for(int i=0; i<4; i++){
        t_nbPoints x;
        x.domaine = i;
        x.nbPoints = sDomaines[i]-48; //code ascii
        _nbPoints.push_back(x);
    }


    //Ajout de la carte au vecteur contenant un exemplaire de chaque carte attaque du jeu
    m_attaques.push_back(Attaque(_imm,_imm,_nom,_description,_domaine,std::stoi(sDegat), _nbPoints));
}



/*
 * Permet à n'importe quel utilisateur d'ajouter une carte dans le jeu:
 * L'utilisateur clique sur l'interface allegro pour choisir la carte qu'il veut
 * avec les bons paramètres selon la carte
 */
void Collection::userCreerCarte(){
    //int type=0;
    //La il peut cliquer sur le type qu'il veut
    //creerCarte(Energie(350,0,"Jean", "prout prout", 'A'), m_energies);

/*
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
*/

}

void Collection::ajouterCreature(Creature _carte){
    m_creatures.push_back(_carte);
}

void Collection::ajouterEnergie(Energie _carte){
    m_energies.push_back(_carte);
}

void Collection::ajouterSpeciale(Speciale _carte){
    m_speciales.push_back(_carte);
}


/*
 * Accesseur et mutateur
 */


std::vector<Creature> Collection::getCreatures()const {
    return m_creatures;
}

std::vector<Energie> Collection::getEnergies() const{
    return m_energies;
}

std::vector<Speciale> Collection::getSpeciales() const{
    return m_speciales;
}

std::vector<Attaque> Collection::getAttaques() const{
    return m_attaques;
}

std::vector<Creature>& Collection::getCreaturesModif(){
    return m_creatures;
}
std::vector<Speciale>& Collection::getSpecialesModif(){
    return m_speciales;
}
