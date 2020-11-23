//
// Created by mitue on 09/11/2020.
//
#include "src/Headers/Affichage.h"

sf::RenderWindow window(sf::VideoMode(1920, 1080), "GameCard");//variable globale pour la fenetre afin de l'utiliser dans tous les programmes

Affichage::Affichage() {

    sfml_loadImages();
}

Affichage::~Affichage() {
}
void Affichage::sfml_lancement(){

    sfml_initialisation();
}

void Affichage::sfml_loadImages() {

    /** Partie Intro **/
    sf::Texture intro;
    if(!intro.loadFromFile("../Images/Intro/intro.jpg")){
        std::cout << "Probleme ouverture fichier intro"<<std::endl;
    }
    m_imageMap["intro"] = sf::Sprite(intro);
    //m_imageMap.insert(std::pair <std::string, sf::Sprite> ("intro", sf::Sprite(intro)));

    sf::Texture rectJouer;
    if(!rectJouer.loadFromFile("../Images/Intro/Rectangle.jpg")){
        std::cout << "probleme ouverture rectangle" <<std::endl;
    }
    m_imageMap["rectJouer"] = sf::Sprite(rectJouer);
    //m_imageMap.insert(std::pair <std::string, sf::Sprite> ("rectJouer", sf::Sprite(rectJouer)));


    sf::Texture rectRegles;
    if(!rectRegles.loadFromFile("../Images/Intro/Rectangle.jpg")){
        std::cout << "probleme loading rectangle" <<std::endl;
    }
    m_imageMap["rectRegles"] = sf::Sprite(rectRegles);
    //m_imageMap.insert(std::pair <std::string, sf::Sprite> ("rectRegles", sf::Sprite(rectRegles)));

    sf::Texture rectQuitter;
    if(!rectQuitter.loadFromFile("../Images/Intro/Rectangle.jpg")){
        std::cout << "probleme loading rectangle" <<std::endl;
    }
    m_imageMap["rectQuitter"] = sf::Sprite(rectQuitter);
    //m_imageMap.insert(std::pair <std::string, sf::Sprite> ("rectQuitter", sf::Sprite(rectQuitter)));


    /** Partie Play **/

    sf::Texture fondLogin;
    if(!fondLogin.loadFromFile("../Images/Play/Login/Login.jpg"))
        std::cout << "Probleme ouverture fichier login" <<std::endl;
    m_imageMap["fondlogin"] = sf::Sprite(fondLogin);
    //m_imageMap.insert(std::pair <std::string, sf::Sprite> ("fondLogin", sf::Sprite(fondLogin)));

    sf::Texture fire;
    if(!fire.loadFromFile("../Images/Play/Terrain/Fire.jpg"))
        std::cout << "Probleme ouverture fichier fire" << std::endl;
    m_imageMap["fire"] = sf::Sprite(fire);
    //m_imageMap.insert(std::pair <std::string, sf::Sprite> ("fire", sf::Sprite(fire)));

    sf::Texture water;
    if(!water.loadFromFile("../Images/Play/Terrain/Water.jpg"))
        std::cout << "Probleme ouverture fichier water" <<std::endl;
    m_imageMap["water"] = sf::Sprite(water);
    //m_imageMap.insert(std::pair <std::string, sf::Sprite> ("water", sf::Sprite(water)));

    sf::Texture electric;
    if(!electric.loadFromFile("../Images/Play/Terrain/Electric.jpg"))
        std::cout << "Probleme ouverture fichier electric" <<std::endl;
   m_imageMap["electric"] = sf::Sprite(electric);
    //m_imageMap.insert(std::pair <std::string, sf::Sprite> ("electric", sf::Sprite(electric)));

    sf::Texture nature;
    if(!nature.loadFromFile("../Images/Play/Terrain/Nature.jpg"))
        std::cout << "Probleme ouverture fichier nature" <<std::endl;
    m_imageMap["nature"] = sf::Sprite(nature);
    //m_imageMap.insert(std::pair <std::string, sf::Sprite> ("nature", sf::Sprite(nature)));

    /** Partie Regles **/

    sf::Texture regles;
    if(!regles.loadFromFile("../Images/Regles/Regles.jpg"))
        std::cout << "Probleme ouverture du fichier regles" << std::endl;
   m_imageMap["regles"] = sf::Sprite(regles);
    //m_imageMap.insert(std::pair <std::string, sf::Sprite> ("regles", sf::Sprite(regles)));

    /** Partie End **/

    sf::Texture end;
    if(!end.loadFromFile("../Images/Quitter/Leave.jpg"))
        std::cout << "Probleme ouverture fichier de fin "<<std::endl;
    m_imageMap["end"] = sf::Sprite(end);
    //m_imageMap.insert(std::pair <std::string, sf::Sprite> ("end", sf::Sprite(end)));

}

sf::Sprite Affichage::sfml_SearchingImages(std::string _nom){
    auto it=getImageMap().find(_nom);
    if(it!=getImageMap().end())
        return it->second;

}

void Affichage::sfml_initialisation(){//fonction pour initialiser sfml

    float longueurRect(220);
   float largeurRect (130);
   //rectangle pour lancer la partie et se connecter//
        sfml_SearchingImages("rectJouer").setPosition(1400,550);

    //rectangle pour les regles
        sfml_SearchingImages("rectRegles").setPosition(1400,700);

    //rectangle pour quitter
        sfml_SearchingImages("rectQuitter").setPosition(1400,850);


   while(!sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
       //obliger de le mettre dans la boucle pour réactualiser tout le temps
       sf::Vector2i mousePosition = sf::Mouse::getPosition();

       sf::Event event;
       while (window.pollEvent(event)) {
           if (event.type == sf::Event::Closed)
               window.close();//permet de fermer la fenetre
       }

       if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
       {
           if (mousePosition.x < (sfml_SearchingImages("rectJouer").getPosition().x + longueurRect) &&
               mousePosition.x > (sfml_SearchingImages("rectJouer").getPosition().x) &&
               mousePosition.y < (sfml_SearchingImages("rectJouer").getPosition().y + largeurRect) &&
               mousePosition.y > (sfml_SearchingImages("rectJouer").getPosition().y)){
                    sfml_play();

           }

           if (mousePosition.x < (sfml_SearchingImages("rectRegles").getPosition().x + longueurRect) &&
               mousePosition.x > (sfml_SearchingImages("rectRegles").getPosition().x) &&
               mousePosition.y < (sfml_SearchingImages("rectRegles").getPosition().y + largeurRect) &&
               mousePosition.y > (sfml_SearchingImages("rectRegles").getPosition().y)){
                    sfml_regles();
           }

           if (mousePosition.x < (sfml_SearchingImages("rectQuitter").getPosition().x + longueurRect) &&
               mousePosition.x > (sfml_SearchingImages("rectQuitter").getPosition().x) &&
               mousePosition.y < (sfml_SearchingImages("rectQuitter").getPosition().y + largeurRect) &&
               mousePosition.y > (sfml_SearchingImages("rectQuitter").getPosition().y)){
                    sfml_leave();
           }

       }
       window.clear();
       window.draw(sfml_SearchingImages("intro"));
       window.draw(sfml_SearchingImages("rectJouer"));
       window.draw(sfml_SearchingImages("rectRegles"));
       window.draw(sfml_SearchingImages("rectQuitter"));
       window.display();
       sf::sleep(sf::milliseconds(5));
   }

}

void Affichage::sfml_play(){//fonction qui lance le jeu en mode graphique

    while(!sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
        window.clear();
        window.draw(sfml_SearchingImages("fondLogin"));
        window.display();
        sf::sleep(sf::milliseconds(5));

    }

}

void Affichage::sfml_regles(){

    while(!sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)){
        window.clear();
        window.draw(sfml_SearchingImages("regles"));
        window.display();
    }
}

void Affichage::sfml_leave(){

    window.draw(sfml_SearchingImages("end"));
    sf::sleep(sf::seconds(5));
    window.close();
}

std::map <std::string, sf::Sprite> Affichage::getImageMap() const {
    return m_imageMap;
}