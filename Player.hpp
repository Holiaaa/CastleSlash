#pragma once
#include "Utils.hpp"
#include "Classes.hpp"
#include <vector>

class Player {
    private:
        text_t name;
        Classes classes;
        int x;
        int y;
    public: 
        Player();
        text_t getName();
        void setName(text_t n);
        void setClasses(Classes c);
        Classes getClasses();
        int getX();
        int getY();
};