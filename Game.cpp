#include "Game.hpp"

Game::Game() {};

void Game::setPlayer(Player p) {
    player = p;
}

void Game::setMap(Map m) {
    m.copyData(map);
} 

/// @brief [Debug] Utiliser pour représenter une map dans la console sans interface.
void Game::showMap() {
    for (int i = 0; i < 50; ++i) {
        for (int j = 0; j < 50; ++j) {
            std::cout << map[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

void Game::setInterface(Interface i) {
    interface = i;
}

Interface Game::getInterface() {
    return interface;
}

Player Game::getPlayer() {
    return player;
}