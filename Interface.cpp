#include "Utils.hpp"

#include "Interface.hpp"
#include "Player.hpp"
#include "Colors.hpp"
#include "Game.hpp"

#include <string>

Interface::Interface() {
    printf("\033[H\033[J");
};

void Interface::clear() {
    printf("\033[H\033[J");
}

void Interface::drawMap(int x, int y, int r, map_t m, Player* p, Map* map) {
    int centreX = p->getX();
    int centreY = p->getY();

    int left   = r*2;
    int right  = r*2;
    int top    = r;
    int bottom = r;

    for (int j = centreY - top; j <= centreY + bottom; j++) {
        for (int i = centreX - left; i <= centreX + right; i++) {
            int drawX = x + (i - centreX);
            int drawY = y - (j - centreY);

            if (i >= 0 && i < 50 && j >= 0 && j < 50) {
                if (i == centreX && j == centreY) {
                    Interface::drawText(drawX + 1, drawY + 1, "Y", WHT);
                } else {
                    if (m[j][i] == 0) {
                        Interface::drawText(drawX + 1, drawY + 1, Characters::Nothing, map->getConfig()->ground);
                    }
                }
            } else {
                Interface::drawText(drawX, drawY, "   ", WHT);
            }
        }
    }
}

void Interface::drawBox(int x, int y, int w, int h) {
    printf("\033[%d;%dH%c", y, x, Characters::UpperLeftCorner);
    printf("\033[%d;%dH%c", y, x + w - 1, Characters::UpperRightCorner);
    printf("\033[%d;%dH%c", y + h - 1, x, Characters::LowerLeftCorner);
    printf("\033[%d;%dH%c", y + h - 1, x + w - 1, Characters::LowerRightCorner);

    for (int i = 1; i < w - 1; i++) {
        printf("\033[%d;%dH%c", y, x + i, Characters::HorizontalLine);             // haut
        printf("\033[%d;%dH%c", y + h - 1, x + i, Characters::HorizontalLine);     // bas
    }

    for (int i = 1; i < h - 1; i++) {
        printf("\033[%d;%dH%c", y + i, x, Characters::VerticalLine);               // gauche
        printf("\033[%d;%dH%c", y + i, x + w - 1, Characters::VerticalLine);       // droite
    }

    printf("\n");
}

void Interface::drawText(int x, int y, const text_t& text, const text_t& color) {
    printf("\033[%d;%dH%s%s", y, x, color.c_str(), text.c_str());
    Interface::setColor(WHT);
}

void Interface::drawText(int x, int y, const char text, const text_t& color) {
    printf("\033[%d;%dH%s%c", y, x, color.c_str(), text);
    Interface::setColor(WHT);
}

void Interface::setColor(const text_t& color) {
    printf("%s", color.c_str());
}