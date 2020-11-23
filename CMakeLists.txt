cmake_minimum_required(VERSION 3.17)
project(cardGame)

set(CMAKE_CXX_STANDARD 14)

add_executable(cardGame src/main.cpp src/Class/Cartes/Carte.cpp src/Headers/Cartes/Carte.h src/Class/Cartes/Energie.cpp src/Headers/Cartes/Energie.h src/biblio.h src/Class/Cartes/Creature.cpp src/Headers/Cartes/Creature.h src/Class/Cartes/Attaque.cpp src/Headers/Cartes/Attaque.h src/main.h src/Class/Utilisateur.cpp src/Headers/Utilisateur.h src/Class/Cartes/Deck.cpp src/Headers/Cartes/Deck.h src/Class/Match/Joueur.cpp src/Headers/Match/Joueur.h src/Class/Game.cpp src/Headers/Game.h src/Class/Match/Pioche.cpp src/Headers/Match/Pioche.h src/Class/Collection.cpp src/Headers/Collection.h src/Class/Cartes/Speciale.cpp src/Headers/Cartes/Speciale.h src/Class/Match/Plateau.cpp src/Headers/Match/Plateau.h src/Class/Match/Match.cpp src/Headers/Match/Match.h src/Class/Affichage.cpp src/Headers/Affichage.h)


set(SFML_STATIC_LIBRARIES TRUE)
set(SFML_DIR "${CMAKE_CURRENT_LIST_DIR}/lib/SFML-2.5.1/lib/cmake/SFML")
file(GLOB_RECURSE SOURCES "src/*.cpp" "src/*.hpp") #glob all the source files intp one place
file(COPY lib/SFML-2.5.1/bin/openal32.dll DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

link_libraries(stdc++fs) #link the filesystem
file(GLOB_RECURSE SCRF "src/*.cpp" "src/*.hpp")


find_package(SFML 2.5.1 COMPONENTS system window graphics network audio REQUIRED)
target_link_libraries(${PROJECT_NAME} sfml-audio sfml-graphics sfml-window sfml-system)