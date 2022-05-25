//
// Created by popas on 25.05.2022.
//

#include "../headers/UndefinedCell.h"

UndefinedCell::UndefinedCell(float height, float witdh, sf::Vector2f position) :
    Cell(CellType::Undefined, height, witdh, position) {}

UndefinedCell *UndefinedCell::clone() {
    return new UndefinedCell(*this);
}

// operators
void UndefinedCell::afisare(std::ostream &os) const {
    os << '?';
}

std::ostream &operator<<(std::ostream &os, const UndefinedCell &undefinedCell) {
    undefinedCell.afisare(os);
    return os;
}

// draw inherited from sf::Drawable
void UndefinedCell::draw(sf::RenderTarget &target, sf::RenderStates) const {
    sf::RectangleShape rectangle(sf::Vector2f(width, height));
    rectangle.setPosition(position);
    rectangle.setFillColor(sf::Color::Black);
    target.draw(rectangle);
}

bool UndefinedCell::canWalkOn() {
    return false;
}