#include <iostream>

#include "Utils.hpp"
#include "Maps.hpp"
#include "Colors.hpp"
#include "Game.hpp"
#include "Events.hpp"

int main(int argc, char *argv[]) {
    Game game;
    int GAME_RUNNING = 1;
    Interface interface;
    game.setInterface(interface);
    game.getInterface()->setColor(WHT);

    Player player;
    game.setPlayer(player);
    text_t name;

    std::cout << "Entre ton nom : " << std::endl;
    std::getline(std::cin, name);

    game.getPlayer()->setName(name);

    // Classes
    Classes idle;
    idle.setName("Pas de metier");
    idle.setSymbol("-");
    game.getPlayer()->setClasses(idle);

    // Maps
    Map overworld;
    overworld.setData(Maps::overworld);
    overworld.setName("Overworld");

    Map dungeon;
    dungeon.setData(Maps::dungeon);
    dungeon.setName("Dungeon");

    game.setMap(overworld);
    
    // Game loop;
    Events event;
    while (GAME_RUNNING) {
        game.getInterface()->clear();
        game.getInterface()->drawBox(2, 1, 60, 20); // Map Frame
        game.getInterface()->drawBox(63, 1, 50, 20); // Info Frame

        game.getInterface()->drawText(65, 2, game.getPlayer()->getName() + " -", WHT); // Name
        game.getInterface()->drawText(65+game.getPlayer()->getName().length()+1, 2, game.getPlayer()->getClasses().getName(), CYN); // Classes

        game.getInterface()->drawText(65, 3, "LVL", WHT);
        game.getInterface()->drawText(69, 3, std::to_string(game.getPlayer()->getLVL()), GRN); // Level

        game.getInterface()->drawText(65, 4, "Money", WHT);
        game.getInterface()->drawText(71, 4, std::to_string(game.getPlayer()->getMoney()), YEL); // Money
        int input = event.getInput();

        switch (input) {
            case event.KEY_A:
                game.getPlayer()->setMoney(game.getPlayer()->getMoney()+1);
                continue;
            case event.KEY_Q:
                GAME_RUNNING = 0;
                continue;
            default:
                continue;
        }
    }

    std::cout << "Fin" << std::endl;
}