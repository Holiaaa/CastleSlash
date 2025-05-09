#pragma once

#include "Utils.hpp"

class Classes{
    private:
        text_t name;
        text_t symbol;
    public:
        Classes(text_t n, text_t s);
        Classes() : name(""), symbol("") {} // pour l'attribut joueur
        text_t getName();
        text_t getSymbol();
};