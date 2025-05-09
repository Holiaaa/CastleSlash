#include "Utils.hpp"
#include "Classes.hpp"
#include "Player.hpp"

Player::Player() : x(0), y(0) {}

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