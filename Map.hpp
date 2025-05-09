#include "Utils.hpp"

class Map {
    private:
        text_t name;
        map_t data;
    public:
        Map(text_t n, map_t d);
        Map();
        void setName(text_t n);
        void setData(map_t d);
        text_t getName();
        void copyData(map_t d);
};