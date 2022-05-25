//
// Created by popas on 25.05.2022.
//

#include "../headers/FloorCell.h"

FloorCell::FloorCell(float height, float witdh, sf::Vector2f position) :
        Cell(height, witdh, position) {}

FloorCell *FloorCell::clone() {
    return new FloorCell(*this);
}

// operators
void FloorCell::afisare(std::ostream &os) const {
    os << ' ';
}

std::ostream &operator<<(std::ostream &os, const FloorCell &floorCell) {
    floorCell.afisare(os);
    return os;
}

// draw inherited from sf::Drawable
void FloorCell::draw(sf::RenderTarget &target, sf::RenderStates) const {
    sf::RectangleShape rectangle(sf::Vector2f(width, height));
    rectangle.setPosition(position);
    rectangle.setTexture(&floorTexture);
    target.draw(rectangle);
}

bool FloorCell::canWalkOn() {
    return true;
}