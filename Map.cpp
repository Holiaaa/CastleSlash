#include "Map.hpp"

Map::Map(text_t n, map_t d) {
    name = n;
    for (int i = 0; i < 50; ++i) {
        for (int j = 0; j < 50; ++j) {
            data[i][j] = d[i][j];
        }
    }
}

Map::Map() {}

void Map::setName(text_t n) {
    name = n;
}

void Map::setData(map_t d) {
    for (int i = 0; i < 50; ++i) {
        for (int j = 0; j < 50; ++j) {
            data[i][j] = d[i][j];
        }
    }
}

text_t Map::getName() {
    return name;
}

void Map::copyData(map_t d) {
    for (int i = 0; i < 50; ++i) {
        for (int j = 0; j < 50; ++j) {
            d[i][j] = data[i][j];
        }
    }
}