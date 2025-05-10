#include "Utils.hpp"

#include "Interface.hpp"
#include "Colors.hpp"

Interface::Interface() {
    printf("\033[H\033[J");
};

void Interface::clear() {
    printf("\033[H\033[J");
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

void Interface::setColor(const text_t& color) {
    printf("%s", color.c_str());
}