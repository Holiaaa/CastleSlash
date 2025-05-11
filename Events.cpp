#include "Events.hpp"

int Events::getInput() {
    int input = getch();
    if (input == Events::KEY_DIR_ALIAS || input == 224) {
        input = getch();
        return input;
    } else {
        return input;
    }
}
