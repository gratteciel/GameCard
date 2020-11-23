//
// Created by mitue on 09/11/2020.
//

#include "src/Headers/Affichage.h"

sf::RenderWindow window(sf::VideoMode(1920, 1080), "GameCard");//variable globale pour la fenetre afin de l'utiliser dans tous les programmes

Affichage::Affichage() {
    sfmlLoadImages();
}

Affichage::~Affichage() {

}

void Affichage::sfmlLancement(){
    sfmlMenuBase();
}

void Affichage::chargerImage(const std::string& _nomFichier, const std::string& _posFichier,const std::string& _type){
    /** Partie Intro **/
    sf::Texture* img= new (sf::Texture);
    std::string temp="../Images/";
    temp+=_posFichier;
    temp+="/";
    temp+=_nomFichier;
    temp+=".";
    temp+=_type;
    if(!img->loadFromFile(temp)){
        std::cout << "Probleme ouverture fichier "<< _nomFichier << " dans " << _posFichier <<std::endl;
    }
    sf::Sprite sprite;
    sprite.setTexture(*img);
    m_imageMap[_nomFichier] = sprite;


}


void Affichage::setPos(int x, int y, const std::string& _nomFichier){
    auto it=m_imageMap.find(_nomFichier);
    if(it!=m_imageMap.end()){
        //Set la position du sprite
        it->second.setPosition(x,y);
    }
}

void Affichage::sfmlLoadImages() {

    chargerImage("intro", "Intro","jpg");


    chargerImage("RectangleJouer", "Intro","jpg");

    chargerImage("RectangleRegles", "Intro","jpg");

    chargerImage("RectangleLeave", "Intro","jpg");

    chargerImage("Login", "Play/Login","jpg");

    chargerImage("Se_connecter", "Play/Login","png");

    chargerImage("Fire", "Play/Terrain","jpg");

    chargerImage("Water", "Play/Terrain","jpg");

    chargerImage("Electric","Play/Terrain","jpg");

    chargerImage("Nature","Play/Terrain","jpg");

    chargerImage("Regles", "Regles","jpg");

    chargerImage("Leave", "Quitter","jpg");

}

void Affichage::afficheImage(const std::string& _nom){
    auto it=m_imageMap.find(_nom);
    if(it!=m_imageMap.end())
        window.draw(it->second);
}
sf::Sprite Affichage::recupSprite(const std::string& _nom){
    auto it=m_imageMap.find(_nom);
    if(it!=m_imageMap.end())
        return it->second;
}






void Affichage::sfmlMenuBase() {//fonction pour initialiser sfml

    float longueurRect(220);
    float largeurRect(130);


    while (!sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
        //obliger de le mettre dans la boucle pour réactualiser tout le temps
        sf::Vector2i mousePosition = sf::Mouse::getPosition();

        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();//permet de fermer la fenetre
        }


        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                if (mousePosition.x<(recupSprite("RectangleJouer").getPosition().x + longueurRect) && mousePosition.x>(recupSprite("RectangleJouer").getPosition().x) &&
                    mousePosition.y<(recupSprite("RectangleJouer").getPosition().y + largeurRect) && mousePosition.y>(recupSprite("RectangleJouer").getPosition().y)) {
                    sfmlPlay();

                }

                if (mousePosition.x<(recupSprite("RectangleRegles").getPosition().x + longueurRect) && mousePosition.x>(recupSprite("RectangleRegles").getPosition().x) && mousePosition.y<(recupSprite("RectangleRegles").getPosition().y + largeurRect) && mousePosition.y>(recupSprite("RectangleRegles").getPosition().y)) {
                    sfmlRegles();
                }

                if (mousePosition.x<(recupSprite("RectangleQuitter").getPosition().x + longueurRect) && mousePosition.x>(recupSprite("RectangleQuitter").getPosition().x) && mousePosition.y<(recupSprite("RectangleQuitter").getPosition().y + largeurRect) && mousePosition.y>(recupSprite("RectangleQuitter").getPosition().y)) {
                    sfmlLeave();
                }

            }

            window.clear();
            afficheImage("intro");

            setPos(1400, 550, "RectangleJouer");
            afficheImage("RectangleJouer");

            setPos(1400, 700, "RectangleRegles");
            afficheImage("RectangleRegles");

            setPos(1400, 850, "RectangleLeave");
            afficheImage("RectangleLeave");

            window.display();
            sf::sleep(sf::milliseconds(5));
        }

    }

void Affichage::sfmlPlay() {//fonction qui lance le jeu en mode graphique

        while (!sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
            window.clear();
            afficheImage("Login");
            window.display();
            sf::sleep(sf::milliseconds(5));
        }

    }

void Affichage::sfmlRegles() {

        while (!sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
            window.clear();
            afficheImage("Regles");
            window.display();
        }
    }
void Affichage::sfmlLeave() {

        afficheImage("Leave");
        sf::sleep(sf::seconds(5));
        window.close();
}
