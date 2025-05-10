#include "Events.hpp"

// Code repris et légerement modifier de CastleSlash V2 (https://github.com/Holiaaa/CastleSlash-Old/blob/main/source/events.c)

int Events::getInput() {
    int input = getch();
    if (input == Events::KEY_DIR_ALIAS || input == 224) {
        input = getch();
        return input;
    } else {
        return input;
    }
}
