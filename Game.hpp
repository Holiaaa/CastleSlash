#include "Utils.hpp"
#include "Player.hpp"
#include "Interface.hpp"
#include "Map.hpp"

class Game {
    private:
        Player player;
        map_t map;
        Map map_info;
        Interface interface;
    public:
        Game();
        void setPlayer(Player p);
        void setMap(Map m);
        void showMap();
        void setInterface(Interface i);
        Interface* getInterface();
        Player* getPlayer();
        Map* getMap();
};