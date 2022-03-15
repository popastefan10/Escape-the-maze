//
// Created by popas on 15.03.2022.
//

#include "../headers/Player.h"

// constructors
Player::Player() : position(sf::Vector2i(0, 0)) {
    loadTextures();
}

Player::Player(const sf::Vector2i &position) : position(position) {
    loadTextures();
}

// getters / setters
sf::Vector2i Player::getPosition() {
    return position;
}

void Player::setPosition(const sf::Vector2i &newPosition) {
    position = newPosition;
}

// draw inherited from sf::Drawable
void Player::draw(sf::RenderTarget &target, sf::RenderStates) const {
    sf::RectangleShape rectangle;
    rectangle.setSize(sf::Vector2f(15.0, 15.0));
    rectangle.setPosition(sf::Vector2f(15.0f * position.x, 15.0f * position.y));
    rectangle.setTexture(&playerTexture);
    target.draw(rectangle);
}

void Player::loadTextures() {
    playerTexture.loadFromFile("resources/totem_of_undying.png");
}
