//
// Created by bemat on 30/11/2020.
//

#include "../../Headers/Match/Joueur.h"

int Joueur::interaction(Joueur& _ennemie, std::vector<int>& _cimetiere, int& _typeTerrain){
    setEtreSurBouton(false);
    int verifFinDePartie=verifFinPartie(_ennemie);

    if(verifFinDePartie==5 || verifFinDePartie==6 || verifFinDePartie==7)
        return verifFinDePartie;

    _ennemie.possedeAtleastUneActive();

    if(m_prop.propChoixAttaquer.id==-1){
        m_prop.numAttaque=-1;
        if(possedeAtleastUneActive()){
            if(interactionFinTour())
                return 1;
        }

        if(quitterOuPas())
            return 2;

        if(getQuitter()==0){
            if(m_prop.affichePtsEnergies==0){
                interactionPioche();
                interactionMain();
                interactionFromMainToActive(_typeTerrain,_ennemie,_cimetiere);
            }
            interactionPtsEnergies(_ennemie);
        }
    }

    if(getQuitter()==0){
        if(m_prop.affichePtsEnergies==0) {
            interactionActives();
            interactionChoixAttaque(_ennemie, _cimetiere, _typeTerrain);
        }
    }


    if(!getEtreSurBouton())
        setEndroitActu("none");
    incrementerClignotage();


    //Si pas fin de tour
    return 0;
}




int Joueur::verifFinPartie(Joueur &_ennemie){
    if(getStatueLoose()!=0)//Joueur actu a perdu
        return 6;
    else if(_ennemie.getStatueLoose()!=0)//l'ennemie a perdu
        return 7;

    return 0;//si tout se passe bien
}


bool Joueur::quitterOuPas(){

    if(m_prop.affichePtsEnergies==0){
        sf::Vector2<int> souris=Affichage::getMousePosition();

        if(getQuitter()==0){
            //Si la souris est sur le "Quitter"
            if(souris.x>=20&&souris.x<230 && souris.y>=700&&souris.y<=740){
                setEndroitActu("quitter");

                if(sf::Mouse::isButtonPressed(sf::Mouse::Left) && !getDrag().getActif()){
                    sf::sleep(sf::milliseconds(200));
                    setQuitter(1);
                }
            }
        }


        else if(getQuitter()==1){
            //Si la souris est sur le "Quitter"
            if(souris.x>=763&&souris.x<=920 && souris.y>=600&&souris.y<=640) {
                setEndroitActu("quitter");

                if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && !getDrag().getActif()) {
                    sf::sleep(sf::milliseconds(200));
                    return true;
                }
            }
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)){ //Si appuie sur Echap
                setQuitter(0);
            }
            if(souris.x>=1000&&souris.x<=1170 && souris.y>=600&&souris.y<=640) {
                setEndroitActu("annuler");

                if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && !getDrag().getActif()) {
                    setQuitter(0);
                }
            }


        }
    }


    return false;
}

void Joueur::interactionMain(){
    if(!getDrag().getActif()){
        for(int i=0; i<getMain().size(); i++){
            auto elem=getMain()[i];
            int sourisX=Affichage::getMousePosition().x;
            int sourisY=Affichage::getMousePosition().y;

            if(sourisX>580+155*i && sourisX<(580+155*i+150) &&sourisY>850 && sourisY<(850+200)){
                //Si clique sur la carte
                if(!m_prop.doitRepiocher || i!=(getMain().size()-1)){
                    if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
                        /*Initialisation du drag drop*/
                        getDrag().setActif(true); //Drag drop actif
                        getDrag().setId(elem.id);
                        getDrag().setImm(elem.imm);

                    }
                }

            }
        }
    }

}

bool Joueur::interactionFinTour(){

    if(m_prop.affichePtsEnergies==0){
        sf::Vector2<int> souris=Affichage::getMousePosition();

        //Si la souris est sur le "Fin de tour"
        if(souris.x>=1600&&souris.x<1920 && souris.y>=700&&souris.y<=740){
            setEndroitActu("finPioche");

            if(sf::Mouse::isButtonPressed(sf::Mouse::Left) && !getDrag().getActif()){

                return true;
            }

        }
    }

    return false;

}

void Joueur::interactionPioche(){
    if(getPioche().getCartes().size()>0){ //Si il reste des cartes dans la pioche
        if(getPioche().etreSurLaPioche()){//Si curseur sur la pioche
            setEndroitActu("pioche");
            if((!m_prop.aPioche && getMain().size()<5) || m_prop.doitRepiocher){//Si n'a pas encore pioché & taille de la main <5

                if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){//si appuie sur la pioche
                    piocher();
                    sf::sleep(sf::milliseconds(200));
                }

            }
        }
    }

}

void Joueur::interactionFromMainToActive(int& _typeTerrain, Joueur& _ennemie, std::vector<int>& _cimetiere){
    int x1=Affichage::recupSprite("Terrain_cartes").getPosition().x;
    int y1=Affichage::recupSprite("Terrain_cartes").getPosition().y;

    int tempId=getDrag().interaction(x1,y1,1079,649);



        if(tempId!=666){ //Si posé la carte au bon endoit

            for(int i=0; i<getMain().size(); i++){
                if(getMain()[i].id == tempId){ //On cherche la carte de la main qui correspond à celle qu'on vient de déplacer
                    t_carte temp;
                    temp.id = getMain()[i].id;
                    temp.imm= getMain()[i].imm;

                    bool effacerDeMain=false;
                    switch (temp.imm / 100) {
                        case 1: //Créature
                            if(m_actives.size()<4){
                                m_actives.push_back(temp); //On ajoute la cartes aux actives
                                effacerDeMain=true;
                            }

                            break;
                        case 2: //Spéciale
                            for(auto& elem: getCartes().getSpeciales()){
                                if(elem.getId()==temp.id){
                                    if(elem.getType()!=2 && m_actives.size()<4){
                                        _typeTerrain = elem.getDomaine();
                                        m_actives.push_back(temp); //On ajoute la cartes aux actives
                                        effacerDeMain=true;
                                    }
                                    else{
                                        setDefense(true);
                                        elem.setPdv(0);
                                        _cimetiere.push_back(elem.getImmatriculation());
                                        effacerDeMain=true;
                                    }

                                    break;
                                }
                            }

                            break;
                        case 3://Energie
                            effacerDeMain=true;
                            m_cartesEnergie.push_back(temp);
                            for(auto& elem: getCartes().getEnergies()){//On augmente le nombre d'énergie selon les 2 domaines
                                if(elem.getId()==temp.id){
                                    m_ptEnergie[elem.getDomaine()]++;
                                    if(elem.getDomaine2()!=9)
                                        m_ptEnergie[elem.getDomaine2()]++;
                                    break;
                                }
                            }
                            break;

                    }
                    if(effacerDeMain)
                        m_main.erase(m_main.begin() + i); //on efface la carte de la main



                    break;
                }
            }
        }



}

void Joueur::interactionActives(){
    int x= Affichage::recupSprite("Terrain_cartes").getPosition().x+230;
    int y=Affichage::recupSprite("Terrain_cartes").getPosition().y;

    if(!getDrag().getActif()){//Si le drag & drop n'est pas actif
        if(m_prop.propChoixAttaquer.id==-1 && m_prop.numAttaque==-1 ){
            for(int i=0; i<m_actives.size(); i++){
                int posX=Affichage::getMousePosition().x;
                int posY=Affichage::getMousePosition().y;

                if(posX>=x+155*i && posX<=x+155*i+150 && posY>=y+350 && posY<=y+350+200){

                    setEndroitActu("active"+std::to_string(i));

                    if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
                        m_prop.propChoixAttaquer.id=m_actives[i].id;
                        m_prop.propChoixAttaquer.imm=m_actives[i].imm;
                    }

                }
            }
        }

    }

}

void Joueur::interactionChoixAttaque(Joueur& _ennemie, std::vector<int>& _cimetiere,const int& _typeTerrain){

    if(m_prop.propChoixAttaquer.id!=-1){ //S choix d'attaque

        int posX=Affichage::getMousePosition().x;
        int posY=Affichage::getMousePosition().y;


        if(m_prop.numAttaque==-1){ //Si pas encore choisi l'attaque
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)){ //Si appuie sur Echap
                m_prop.propChoixAttaquer.id=-1;
            }
            /*Interaciton du bouton retour*/
            if(posX>=940 && posX<=970 && posY>=830 && posY<=830 + 180){
                setEndroitActu("RETOUR");
                if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){

                    m_prop.propChoixAttaquer.id=-1;
                }
            }



            for(int i=0; i<2; i++){


                int xBase =400 +650*i;
                int yBase = 800;

                if(posX>=xBase && posX<=xBase+453 && posY>=yBase && posY<=yBase + 241){
                    setEndroitActu("attaque" + std::to_string(i));
                    if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
                        if(getNbAttaques()<2){//Si n'a pas fait ses 2 attaques par tour
                            /* VERIF SI A BIEN LES ENERGIES */
                            if(verifIfPossedeEnergies(i)&& !_ennemie.getDefense()){
                                if(m_prop.propChoixAttaquer.imm/100==2 && i==1){//Si spéciale
                                    specialAttaque(_ennemie,_cimetiere);
                                }
                                else
                                    m_prop.numAttaque=i;
                            }
                        }


                    }

                }
            }


        }
        else{ //Si a choisi l'attaque alors il va devoir choisir quelle carte ennemie il va attaquer
            /*Interaciton du bouton retour*/
            if(posX>=900 && posX<=1080 && posY>=900 && posY<=930){
                setEndroitActu("RETOUR1");
                if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
                    sf::sleep(sf::milliseconds(100));
                    m_prop.numAttaque=-1;

                }
            }

            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)){ //Si appuie sur Echap alors on revient au choix des attaques
                m_prop.numAttaque=-1;
            }


            int x= Affichage::recupSprite("Terrain_cartes").getPosition().x+230;
            int y=Affichage::recupSprite("Terrain_cartes").getPosition().y-250;

            if(m_prop.numAttaque!=66){ //Si pas attaque de la reine -> soigner
                for(int i=0; i<_ennemie.getActives().size(); i++) {

                    int xBase = x+ 155 * i;
                    int yBase = y+350;

                    if(posX>=xBase && posX<=xBase+150 && posY>=yBase && posY<=yBase + 200){
                        setEndroitActu("ennemieActives"+std::to_string(i));
                        if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){ //Si clique sur une carte ennemie
                            attaquer(i,_ennemie,_cimetiere,_typeTerrain);
                        }

                    }
                }
            }
            else{//si attaque de la reine->soigner
                for(int i=0; i<getActives().size(); i++) {//On choisit la carte alliée

                    int xBase = x+ 155 * i;
                    int yBase = y+250+350;

                    if(posX>=xBase && posX<=xBase+150 && posY>=yBase && posY<=yBase + 200){
                        setEndroitActu("active"+std::to_string(i));

                        if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){ //Si clique sur une carte ennemie
                            if(getActives()[i].id!=m_prop.propChoixAttaquer.id) //Si n'essaye pas de se soigner
                                specialAttaque(_ennemie,_cimetiere,i);
                        }

                    }
                }
            }

        }


    }
}

void Joueur::specialAttaque(Joueur& _ennemie, std::vector<int>& _cimetiere, int posAllie){
    int degat=0;
    int degatExcendentaires=0;
    int _type;
    for(auto& elem: getCartes().getSpeciales()){ //Cherche la carte du joueur actuel pour savoir ses dégats
        if(m_prop.propChoixAttaquer.id==elem.getId()){
            degat= elem.getAttaques()[1]->getDegat();
            _type=elem.getType();
            break;
        }
    }

    if(_type==1){//SI ROI

        for(auto& elem: _ennemie.getActives()){
            if(elem.imm/100==1){//Créature
                for(auto& elem2 : _ennemie.getCartes().getCreaturesModif()){
                    if(elem2.getId() == elem.id){
                        if(degat-elem2.getPdv()>0)
                            degatExcendentaires+=degat-elem2.getPdv();
                        elem2.setPdv(elem2.getPdv()-degat);
                    }
                }
            }
            else{//Spéciale
                for(auto& elem2 : _ennemie.getCartes().getSpecialesModif()){
                    if(elem2.getId() == elem.id){
                        if(degat-elem2.getPdv()>0)
                            degatExcendentaires+=degat-elem2.getPdv();
                        elem2.setPdv(elem2.getPdv()-degat);
                    }
                }
            }
        }

        /* LES DEGATS EXCEDENTAIRES IMPACTENT LES POINTS DE VIE DU JOUEUR*/
        if(degatExcendentaires>0)//Si il y a eu des dégats excédentaires
            _ennemie.setPdv(_ennemie.getPdv()-degatExcendentaires);

        /*DIMINUE LES POINTS D'ENERGIES*/
        //diminuEnergieAfterAttaque(1);

        setNbAttaques(getNbAttaques()+1); //Augmente le nombre d'attaques
        m_prop.propChoixAttaquer.id=-1;
        m_prop.propChoixAttaquer.imm=-1;
        m_prop.numAttaque=-1;

    }
    else{
        if(posAllie!=42){
            if(getActives()[posAllie].id!=m_prop.propChoixAttaquer.id){ //Si n'essaye pas de se heal

                switch(getActives()[posAllie].imm/100){
                    case 1://Creature
                        //On Cherche la carte de l'aliié qui coreespond à l'id de la carte healé
                        for(auto& elem : getCartes().getCreaturesModif()){
                            if(elem.getId()==getActives()[posAllie].id){
                                elem.setPdv(elem.getPdv()+30);//Ses pdv diminue selon les dégats de l'attaque
                                break;
                            }
                        }
                        break;
                    case 2:
                        //On Cherche la carte de l'ennemie qui coreespond à l'id de la carte healé
                        for(auto& elem : getCartes().getSpecialesModif()){
                            if(elem.getId()==getActives()[posAllie].id){
                                elem.setPdv(elem.getPdv()+30);//Ses pdv diminue selon les dégats de l'attaque
                                break;
                            }
                        }
                        break;
                }
            }

            /*DIMINUE LES POINTS D'ENERGIES*/
            //diminuEnergieAfterAttaque(1);
            setNbAttaques(getNbAttaques()+1); //Augmente le nombre d'attaques

            sf::sleep(sf::milliseconds(100));
            m_prop.propChoixAttaquer.id=-1;
            m_prop.propChoixAttaquer.imm=-1;
            m_prop.numAttaque=-1;
        }
        else
            m_prop.numAttaque=66;


    }



    /*VERIFIE SI DES CARTES SONT MORTES ET LES MET DANS LE CIMETIERE SI C'EST LE CAS*/
    verifSiDead(_ennemie,_cimetiere);

        

}

void Joueur::attaquer(int i,Joueur& _ennemie, std::vector<int>& _cimetiere, const int& _typeTerrain ){
    int _idEnnemieAttaque = _ennemie.getActives()[i].id;
    int degat=0;
    int degatExcendentaires=0;
    switch(m_prop.propChoixAttaquer.imm/100){//TYPE
        case 1://Créature
            for(auto& elem: getCartes().getCreatures()){ //Cherche la carte du joueur actuel pour savoir ses dégats
                if(m_prop.propChoixAttaquer.id==elem.getId()){
                    degat= elem.getAttaques()[m_prop.numAttaque]->getDegat();
                    if(_typeTerrain==elem.getDomaine())
                        degat+=5;
                    break;
                }
            }


            switch(_ennemie.getActives()[i].imm/100){
                case 1:
                    //On Cherche la carte de l'ennemie qui coreespond à l'id de la carte attaqué
                    for(auto& elem : _ennemie.getCartes().getCreaturesModif()){
                        if(elem.getId()==_idEnnemieAttaque){
                            degatExcendentaires=degat-elem.getPdv();
                            elem.setPdv(elem.getPdv()-degat);//Ses pdv diminue selon les dégats de l'attaque
                            break;
                        }
                    }
                    break;
                case 2:
                    //On Cherche la carte de l'ennemie qui coreespond à l'id de la carte attaqué
                    for(auto& elem : _ennemie.getCartes().getSpecialesModif()){
                        if(elem.getId()==_idEnnemieAttaque){
                            degatExcendentaires=degat-elem.getPdv();
                            elem.setPdv(elem.getPdv()-degat);//Ses pdv diminue selon les dégats de l'attaque
                            break;
                        }
                    }
                    break;
            }

            break;


        case 2://Spéciale

            for(auto& elem: getCartes().getSpeciales()){ //Cherche la carte du joueur actuel pour savoir ses dégats
                if(m_prop.propChoixAttaquer.id==elem.getId()){
                    degat= elem.getAttaques()[m_prop.numAttaque]->getDegat();
                    if(_typeTerrain==elem.getDomaine())
                        degat+=5;
                    break;
                }
            }


            if(m_prop.numAttaque==0){
                switch(_ennemie.getActives()[i].imm/100){
                    case 1:
                        //On Cherche la carte de l'ennemie qui coreespond à l'id de la carte attaqué
                        for(auto& elem : _ennemie.getCartes().getCreaturesModif()){
                            if(elem.getId()==_idEnnemieAttaque){
                                degatExcendentaires=degat-elem.getPdv();
                                elem.setPdv(elem.getPdv()-degat);//Ses pdv diminue selon les dégats de l'attaque
                                break;
                            }
                        }
                        break;
                    case 2:
                        //On Cherche la carte de l'ennemie qui coreespond à l'id de la carte attaqué
                        for(auto& elem : _ennemie.getCartes().getSpecialesModif()){
                            if(elem.getId()==_idEnnemieAttaque){
                                degatExcendentaires=degat-elem.getPdv();
                                elem.setPdv(elem.getPdv()-degat);//Ses pdv diminue selon les dégats de l'attaque
                                break;
                            }
                        }
                        break;


                }

            }
            else if(m_prop.numAttaque==1){
                std::cout <<"beug Attaque " << std::endl;
            }

        break;
    }

    /* LES DEGATS EXCEDENTAIRES IMPACTENT LES POINTS DE VIE DU JOUEUR*/
    if(degatExcendentaires>0)//Si il y a eu des dégats excédentaires
        _ennemie.setPdv(_ennemie.getPdv()-degatExcendentaires);

    /*VERIFIE SI DES CARTES SONT MORTES ET LES MET DANS LE CIMETIERE SI C'EST LE CAS*/
    verifSiDead(_ennemie,_cimetiere);

    /*DIMINUE LES POINTS D'ENERGIES*/
    //diminuEnergieAfterAttaque(m_prop.numAttaque);
    setNbAttaques(getNbAttaques()+1); //Augmente le nombre d'attaques
    m_prop.propChoixAttaquer.id=-1;
    m_prop.propChoixAttaquer.imm=-1;
    m_prop.numAttaque=-1;

}

void Joueur::interactionPtsEnergies(Joueur& _ennemie){
    int x=30,y=850+105;
    int posX=Affichage::getMousePosition().x;
    int posY=Affichage::getMousePosition().y;

    if(m_prop.affichePtsEnergies==0){
        if(posX>=x&&posX<=x+220 && posY>=y && posY<=y+30){
            setEndroitActu("ptsEnergies");
            if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
                m_prop.affichePtsEnergies=1;
                _ennemie.setAffichePtsEnergies(1);
            }
        }
    }
    else if(m_prop.affichePtsEnergies==1){
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)){ //Si appuie sur Echap
            m_prop.affichePtsEnergies=0;
            _ennemie.setAffichePtsEnergies(0);
        }

        if(posX>=800&&posX<=800+270 && posY>=700 && posY<=700+46){
            setEndroitActu("RetourAfficheEnergies");
            if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
                m_prop.affichePtsEnergies=0;
                _ennemie.setAffichePtsEnergies(0);
                sf::sleep(sf::milliseconds(200));
            }
        }


    }


}

