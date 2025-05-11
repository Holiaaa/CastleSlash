#pragma once
#include "Utils.hpp"
#include "MapConfig.hpp"

class Map {
    private:
        text_t name;
        map_t data;
        mconfig cfg;
    public:
        Map(text_t n, map_t d);
        Map();
        void setName(text_t n);
        void setData(map_t d);
        text_t getName();
        void copyData(map_t d);
        void setConfig(mconfig c);
        mconfig* getConfig();
};