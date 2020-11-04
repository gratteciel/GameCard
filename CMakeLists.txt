cmake_minimum_required(VERSION 3.17)
project(cardGame)

set(CMAKE_CXX_STANDARD 14)

add_executable(cardGame main.cpp src/Class/Carte.cpp src/Headers/Carte.h src/Class/Energie.cpp src/Headers/Energie.h biblio.h src/Class/Creature.cpp src/Headers/Creature.h src/Class/Attaque.cpp src/Class/Attaque.h)