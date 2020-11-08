cmake_minimum_required(VERSION 3.17)
project(cardGame)

set(CMAKE_CXX_STANDARD 14)

add_executable(cardGame main.cpp src/Class/Cartes/Carte.cpp src/Headers/Cartes/Carte.h src/Class/Cartes/Energie.cpp src/Headers/Cartes/Energie.h biblio.h src/Class/Cartes/Creature.cpp src/Headers/Cartes/Creature.h src/Class/Cartes/Attaque.cpp src/Headers/Cartes/Attaque.h main.h src/Class/Utilisateur.cpp src/Headers/Utilisateur.h src/Class/Cartes/Deck.cpp src/Headers/Cartes/Deck.h src/Class/Match/Joueur.cpp src/Headers/Match/Joueur.h src/Class/Game.cpp src/Headers/Game.h src/Class/Match/Pioche.cpp src/Headers/Match/Pioche.h src/Class/Collection.cpp src/Headers/Collection.h src/Class/Cartes/Speciale.cpp src/Headers/Cartes/Speciale.h)