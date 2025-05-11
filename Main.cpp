#include <iostream>
#include <windows.h>
#undef interface

#include "Utils.hpp"
#include "Maps.hpp"
#include "Colors.hpp"
#include "Game.hpp"
#include "Events.hpp"

int main(int argc, char *argv[]) {
    SetConsoleCP(CP_UTF8);
    Game game;
    int GAME_RUNNING = 1;
    Interface interface;
    game.setInterface(interface);
    game.getInterface()->setColor(WHT);

    Player player;
    game.setPlayer(player);
    text_t name;

    std::cout << u8"Entre ton nom : " << std::endl;
    std::getline(std::cin, name);

    game.getPlayer()->setName(name);

    // Classes
    Classes idle;
    idle.setName("Pas de metier");
    idle.setSymbol("-");
    game.getPlayer()->setClasses(idle);

    // Maps
    Map overworld;
    overworld.setData(Maps::Overworld::data);
    overworld.setConfig(Maps::Overworld::config);
    overworld.getConfig()->ground = GRN;
    overworld.setName("Overworld");

    Map dungeon;
    dungeon.setData(Maps::Dungeon::data);
    dungeon.setConfig(Maps::Overworld::config);
    dungeon.getConfig()->ground = GRN;
    dungeon.setName("Dungeon");

    game.setMap(overworld);
    
    // Game loop;
    Events event;
    while (GAME_RUNNING) {
        game.getInterface()->clear();
        map_t current;
        game.getMap()->copyData(current);
        game.getInterface()->drawMap(30, 8, 5, current, game.getPlayer(), game.getMap());
        game.getInterface()->drawBox(2, 1, 60, 20); // Map Frame
        game.getInterface()->drawBox(18, 3, 27, 13);

        game.getInterface()->drawBox(63, 1, 50, 20); // Info Frame

        game.getInterface()->drawText(65, 2, game.getPlayer()->getName() + " -", WHT); // Name
        game.getInterface()->drawText(65+game.getPlayer()->getName().length()+1, 2, game.getPlayer()->getClasses().getName(), CYN); // Classes

        game.getInterface()->drawText(65, 3, "LVL", WHT);
        game.getInterface()->drawText(69, 3, std::to_string(game.getPlayer()->getLVL()), GRN); // Level

        game.getInterface()->drawText(65, 4, "Money", WHT);
        game.getInterface()->drawText(71, 4, std::to_string(game.getPlayer()->getMoney()), YEL); // Money

        game.getInterface()->drawText(4, 17, game.getMap()->getName(), WHT);
        game.getInterface()->drawText(4, 18, "X="+std::to_string(game.getPlayer()->getX()), WHT);
        game.getInterface()->drawText(4, 19, "Y="+std::to_string(game.getPlayer()->getY()), WHT);

        int input = event.getInput();

        switch (input) {
            case event.KEY_A:
                game.getPlayer()->setMoney(game.getPlayer()->getMoney()+1);
                continue;
            case event.KEY_Q:
                game.getPlayer()->setX(game.getPlayer()->getX() - 1);
                continue;
            case event.KEY_D:
                game.getPlayer()->setX(game.getPlayer()->getX() + 1);
                continue;
            case event.KEY_Z:
                game.getPlayer()->setY(game.getPlayer()->getY() + 1);
                continue;
            case event.KEY_S:
                game.getPlayer()->setY(game.getPlayer()->getY() - 1);
                continue;
            case event.KEY_X:
                GAME_RUNNING = 0;
                continue;
            default:
                continue;
        }
    }

    std::cout << "\n\nExit" << std::endl;
}