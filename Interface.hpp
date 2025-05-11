#pragma once

#include "Utils.hpp"
#include "Characters.hpp"
#include "Player.hpp"
#include "Map.hpp"

class Interface {
    public:
        Interface();
        void drawBox(int x, int y, int w, int h);
        void drawMap(int x, int y, int r, map_t m, Player* p, Map* map);
        void clear();
        void drawText(int x, int y, const text_t& text, const text_t& color);
        void drawText(int x, int y, const char text, const text_t& color);
        void setColor(const text_t& color);
};