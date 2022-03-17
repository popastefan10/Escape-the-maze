//
// Created by popas on 15.03.2022.
//

#include "../headers/Player.h"

// constructors
Player::Player() :
width(0), height(0), position(sf::Vector2i(0, 0)) {
    loadTextures();
}

Player::Player(float width, float height, const sf::Vector2i &position) :
width(width), height(height), position(position) {
    loadTextures();
}

// getters / setters
sf::Vector2i Player::getPosition() {
    return position;
}

void Player::setPosition(const sf::Vector2i &newPosition) {
    position = newPosition;
}

void Player::setSize(const sf::Vector2f &newSize) {
    width = newSize.x;
    height = newSize.y;
}

// draw inherited from sf::Drawable
void Player::draw(sf::RenderTarget &target, sf::RenderStates) const {
    sf::RectangleShape rectangle;
    rectangle.setSize(sf::Vector2f(width, height));
    rectangle.setPosition(sf::Vector2f(width * (float)position.x, height * (float)position.y));
    rectangle.setTexture(&playerTexture);
    target.draw(rectangle);
}

void Player::loadTextures() {
    playerTexture.loadFromFile("resources/totem_of_undying.png");
}
