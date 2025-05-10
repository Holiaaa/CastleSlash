#include "Utils.hpp"
#include "Characters.hpp"

class Interface {
    public:
        Interface();
        void drawBox(int x, int y, int w, int h);
        void clear();
        void drawText(int x, int y, const text_t& text, const text_t& color);
        void setColor(const text_t& color);
};