//
// Created by popas on 25.05.2022.
//

#include "../headers/WallCell.h"

// constructors
WallCell::WallCell(float height, float witdh, sf::Vector2f position) :
    Cell(height, witdh, position) {}

WallCell *WallCell::clone() {
    return new WallCell(*this);
}

// operators
void WallCell::afisare(std::ostream &os) const {
    os << '#';
}

std::ostream &operator<<(std::ostream &os, const WallCell &wallCell) {
    wallCell.afisare(os);
    return os;
}

// draw inherited from sf::Drawable
void WallCell::draw(sf::RenderTarget &target, sf::RenderStates) const {
    sf::RectangleShape rectangle(sf::Vector2f(width, height));
    rectangle.setPosition(position);
    rectangle.setTexture(&wallTexture);
    target.draw(rectangle);
}

bool WallCell::canWalkOn() {
    return true;
}