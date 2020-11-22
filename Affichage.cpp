//
// Created by mitue on 09/11/2020.
//
#include "src/Headers/Affichage.h"

sf::RenderWindow window(sf::VideoMode(1920, 1080), "GameCard");//variable globale pour la fenetre afin de l'utiliser dans tous les programmes


Affichage::Affichage() {

}

Affichage::~Affichage() {
}
void Affichage::sfml_lancement(){
    sfml_initialisation();
}

std::map <std::string, sf::Texture> Affichage::sfml_loadImages() {
    std::map<std::string, sf::Texture> imageMap;

    /** Partie Intro **/
    sf::Texture intro;
    if(!intro.loadFromFile("../Images/Intro/intro.jpg")){
        std::cout << "Probleme ouverture fichier intro"<<std::endl;
    }
    //imageMap.insert(std::pair <std::string, sf::Texture> ("intro", intro));
    imageMap["intro"] = intro;

    sf::Texture rectJouer;
    if(!rectJouer.loadFromFile("../Images/Intro/Rectangle.jpg")){
        std::cout << "probleme loading rectangle" <<std::endl;
    }
    //imageMap.insert(std::pair <std::string, sf::Texture> ("rectJouer", rectJouer));
    imageMap["rectJouer"] = rectJouer;

    sf::Texture rectRegles;
    if(!rectRegles.loadFromFile("../Images/Intro/Rectangle.jpg")){
        std::cout << "probleme loading rectangle" <<std::endl;
    }
    imageMap["recRegles"]= rectRegles;
    //imageMap.insert(std::pair <std::string, sf::Texture> ("rectRegles", rectRegles));

    sf::Texture rectQuitter;
    if(!rectQuitter.loadFromFile("../Images/Intro/Rectangle.jpg")){
        std::cout << "probleme loading rectangle" <<std::endl;
    }
    //imageMap.insert(std::pair <std::string, sf::Texture> ("rectQuitter", rectQuitter));
    imageMap["rectQuitter"] = rectQuitter;

    /** Partie Play **/
    sf::Texture fondLogin;
    if(!fondLogin.loadFromFile("../Images/Play/Login/Login.jpg"))
        std::cout << "Probleme ouverture fichier login" <<std::endl;
    //imageMap.insert(std::pair <std::string, sf::Texture> ("fondLogin", fondLogin));
    imageMap["fondLogin"] = fondLogin;

    sf::Texture fire;
    if(!fire.loadFromFile("../Images/Play/Terrain/Fire.jpg"))
        std::cout << "Probleme ouverture fichier fire" << std::endl;
    imageMap["fire"] = fire;

    sf::Texture water;
    if(!water.loadFromFile("../Images/Play/Terrain/Water.jpg"))
        std::cout << "Probleme ouverture fichier water" <<std::endl;
    imageMap["water"]= water;

    sf::Texture electric;
    if(!electric.loadFromFile("../Images/Play/Terrain/Electric.jpg"))
        std::cout << "Probleme ouverture fichier electric" <<std::endl;
    imageMap["electric"] = electric;

    sf::Texture nature;
    if(!nature.loadFromFile("../Images/Play/Terrain/Nature.jpg"))
        std::cout << "Probleme ouverture fichier nature" <<std::endl;
    imageMap["nature"] = nature;

    /** Partie Regles **/
    sf::Texture regles;
    if(!regles.loadFromFile("../Images/Regles/Regles.jpg"))
        std::cout << "Probleme ouverture du fichier regles" << std::endl;
    //imageMap.insert(std::pair <std::string, sf::Texture> ("regles", regles));
    imageMap["regles"] = regles;

    /** Partie End **/
    sf::Texture end;
    if(!end.loadFromFile("../Images/Quitter/Leave.jpg"))
        std::cout << "Probleme ouverture fichier de fin "<<std::endl;
    //imageMap.insert(std::pair <std::string, sf::Texture> ("end", end));
    imageMap["end"] = end;

    return imageMap;
}

sf::Texture Affichage::sfml_SearchingImages(std::map<std::string, sf::Texture> &imagesMap, std::string _nom){
    auto it=imagesMap.find(_nom);
    if(it!=imagesMap.end())
        return it->second;

}

void Affichage::sfml_initialisation(){//fonction pour inisialiser sfml

    std::map<std::string, sf::Texture> imageMap=sfml_loadImages();
    //partie intro
    sf::Sprite sprite_intro;
    sprite_intro.setTexture(sfml_SearchingImages(imageMap, "intro"));

   float longueurRect(220);
   float largeurRect (130);
   //rectangle pour lancer la partie et se connecter

        sf::Sprite sprite_rectJouer;
        sprite_rectJouer.setTexture(sfml_SearchingImages(imageMap, "rectJouer"));
        sprite_rectJouer.setPosition(1400,550);

    //rectangle pour les regles

        sf::Sprite sprite_rectRegles;
        sprite_rectRegles.setTexture(sfml_SearchingImages(imageMap, "rectRegles"));
        sprite_rectRegles.setPosition(1400,700);


    //rectangle pour quitter
        sf::Sprite sprite_rectQuitter;
        sprite_rectQuitter.setTexture(sfml_SearchingImages(imageMap, "rectQuitter"));
        sprite_rectQuitter.setPosition(1400,850);

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
           if (mousePosition.x < (sprite_rectJouer.getPosition().x + longueurRect) &&
               mousePosition.x > (sprite_rectJouer.getPosition().x) &&
               mousePosition.y < (sprite_rectJouer.getPosition().y + largeurRect) &&
               mousePosition.y > (sprite_rectJouer.getPosition().y)){
                    sfml_play(imageMap);

           }

           if (mousePosition.x < (sprite_rectRegles.getPosition().x + longueurRect) &&
               mousePosition.x > (sprite_rectRegles.getPosition().x) &&
               mousePosition.y < (sprite_rectRegles.getPosition().y + largeurRect) &&
               mousePosition.y > (sprite_rectRegles.getPosition().y)){
               sfml_regles(imageMap);
           }

           if (mousePosition.x < (sprite_rectQuitter.getPosition().x + longueurRect) &&
               mousePosition.x > (sprite_rectQuitter.getPosition().x) &&
               mousePosition.y < (sprite_rectQuitter.getPosition().y + largeurRect) &&
               mousePosition.y > (sprite_rectQuitter.getPosition().y)){
               sfml_leave(imageMap);
           }

       }
            window.clear();
           window.draw(sprite_intro);
           window.draw(sprite_rectJouer);
           window.draw(sprite_rectRegles);
           window.draw(sprite_rectQuitter);
           window.display();
           sf::sleep(sf::milliseconds(5));
   }

}

void Affichage::sfml_play(std::map <std::string, sf::Texture> &imageMap){//fonction qui lance le jeu en mode graphique


    //fond
    sf::Sprite sprite_fondLogin;
    sprite_fondLogin.setTexture(sfml_SearchingImages(imageMap, "fondLogin"));

    while(!sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
        window.clear();
        window.draw(sprite_fondLogin);

        window.display();
        sf::sleep(sf::milliseconds(5));

    }

}

void Affichage::sfml_regles(std::map <std::string, sf::Texture> &imageMap){


    sf::Sprite sprite_regles;
    sprite_regles.setTexture(sfml_SearchingImages(imageMap, "regles"));
    while(!sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)){
    window.draw(sprite_regles);
    window.display();
    }
}

void Affichage::sfml_leave(std::map <std::string, sf::Texture> &imageMap){

    sf::Sprite sprite_end;
    sprite_end.setTexture(sfml_SearchingImages(imageMap, "end"));
    window.draw(sprite_end);
    sf::sleep(sf::seconds(5));
    window.close();

}
