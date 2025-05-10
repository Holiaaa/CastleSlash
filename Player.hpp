#pragma once
#include "Utils.hpp"
#include "Classes.hpp"
#include <vector> // TODO: Item class for the inventory

typedef struct {
    int atk = 10;
    int def = 10;
    int hp = 100;
    int hpmax = hp;
} Stats;

class Player {
    private:
        text_t name;
        Classes classes;
        int x = 25;
        int y = 25;
        int money = 0;
        int lvl = 0;
        Stats stats;
    public: 
        Player();
        text_t getName();
        void setName(text_t n);
        void setClasses(Classes c);
        Classes getClasses();
        int getX();
        int getY();
        void setAtk(int a);
        void setDef(int d);
        void setHp(int h);
        void setHpMax(int hm);
        int getAtk();
        int getDef();
        int getHp();
        int getHpMax();
        void setMoney(int m);
        int getMoney();
        int getLVL();
        void setLVL(); // TODO: Level system.
};