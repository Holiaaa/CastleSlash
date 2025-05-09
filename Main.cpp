#include <iostream>

#include "Utils.hpp"
#include "Maps.hpp"
#include "Game.hpp"

int main(int argc, char *argv[]) {
    Game game;
    Interface interface;
    game.setInterface(interface);

    Player player;
    text_t name;

    std::cout << "Entre ton nom : " << std::endl;
    std::getline(std::cin, name);

    player.setName(name);
    game.setPlayer(player);

    // Maps

    Map overworld;
    overworld.setData(Maps::overworld);
    overworld.setName("Overworld");

    Map dungeon;
    dungeon.setData(Maps::dungeon);
    dungeon.setName("Dungeon");

    game.setMap(overworld);
    
    // Game loop
    game.getInterface().drawBox(10, 10, 20, 10);
}