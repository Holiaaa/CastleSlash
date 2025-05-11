#include "Utils.hpp"
#include "Classes.hpp"
#include "Player.hpp"

Player::Player() {}

/// @brief Renvoie le nom d'un joueur.
/// @author Téo JAUFFRET
text_t Player::getName() {
    return name;
}

/// @brief Définit le nom du joueur
/// @param n Le nom à assigner
void Player::setName(text_t n) {
    name = n;
}

/// @brief Attribue une classe au joueur.
/// @param c La classe a assigner.
void Player::setClasses(const Classes c) {
    classes = c;
}

/// @brief Renvoie la classe d'un joueur.
Classes Player::getClasses() {
    return classes;
}

/// @brief Renvoie la position X d'un joueur.
int Player::getX() {
    return x;
}

/// @brief Renvoie la position Y d'un joueur.
int Player::getY() {
    return y;
}

void Player::setAtk(int a) {
    stats.atk = a;
}

void Player::setDef(int d) {
    stats.def = d;
}

void Player::setHp(int h) {
    stats.hp = h;
}

void Player::setHpMax(int hp) {
    stats.hpmax = hp;
}

int Player::getAtk() {
    return stats.atk;
}

int Player::getDef() {
    return stats.def;
}

int Player::getHp() {
    return stats.hp;
}

int Player::getHpMax() {
    return stats.hpmax;
}

void Player::setMoney(int m) {
    money = m;
}

int Player::getMoney() {
    return money;
}

int Player::getLVL() {
    return lvl;
}

void Player::setLVL() {}

void Player::setX(int nx) {
    x = nx;
}

void Player::setY(int ny) {
    y = ny;
}