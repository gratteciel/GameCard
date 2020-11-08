/*
 * Permet d'ajouter une carte Créature dans le jeu:
 *  1.ajout dans le fichier creatures.txt
 *  2.ajout dans le vecteur créature
 */
template <typename T>
void Collection::creerCarte(T _carte){
    int type = _carte.getImmatriculation()/100;
    std::string _nomClassCarte;

    switch(type){
        case 1: //Créature
            _nomClassCarte+="creatures";
            break;
        case 2: //Spéciale
            _nomClassCarte+="speciales";
            break;
        case 3: //Energie
            _nomClassCarte+="energies";
            break;
        default:
            break;
    }
    std::string _nomFichier = "../database/cartes/";

    _nomFichier += _nomClassCarte;
    _nomFichier+= ".txt";

    //1: Ajout dans le fichier creatures.txt
    std::ifstream fileInput(_nomFichier);
    std::ofstream fileOutput(_nomFichier,std::ios::app);

    if(fileInput.is_open()){//Si le fichier a réussit à s'ouvrir
        creerCarteType(_carte,fileOutput);
        fileOutput.close();//Fermeture du fichier
        fileInput.close();//Fermeture du fichier

    }
    else{
        std::cout << "Impossible d'ouvrir le fichier : creatures.txt " << std::endl;
    }


}