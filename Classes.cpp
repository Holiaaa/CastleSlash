#include "Classes.hpp"
#include "Utils.hpp"

Classes::Classes(text_t n, text_t s) {
    name = n;
    symbol = s;
}

/// @brief Renvoie le nom d'une classe
text_t Classes::getName() {
    return name;
}

/// @brief Renvoie le symbole d'une classe
text_t Classes::getSymbol() {
    return symbol;
}