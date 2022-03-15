//
// Created by popas on 14.03.2022.
//

#include "../headers/Cell.h"

// static attributes
const sf::Color Cell::wallColor = sf::Color(50, 50, 50);
const sf::Color Cell::floorColor = sf::Color(189, 189, 189);
const sf::Color Cell::undefinedColor = sf::Color(189, 189, 189);

// constructors
Cell::Cell(CellType cellType, float width, float height, sf::Vector2f position) :
    cellType(cellType), height(height), width(width), position(position) {}

// copy constructor
Cell::Cell(const Cell &rhs) {
    cellType = rhs.cellType;
    height = rhs.height;
    width = rhs.width;
    position = rhs.position;
}

// operators
Cell & Cell::operator = (const Cell &rhs) = default;

std::ostream &operator<<(std::ostream &os, const Cell &cell) {
    switch(cell.cellType) {
        case Cell::Wall:
            os << '#';
            break;
        case Cell::Floor:
            os << ' ';
            break;
        default:
            os << '?';
            break;
    }

    return os;
}

// getters / setters
[[maybe_unused]] Cell::CellType Cell::getCellType(Cell::CellType) {
    return cellType;
}

[[maybe_unused]] [[maybe_unused]] void Cell::setCellType(Cell::CellType cellType_) {
    cellType = cellType_;
}

// draw derived from sf::Drawable
void Cell::draw(sf::RenderTarget &target, sf::RenderStates) const {
    sf::RectangleShape rectangle(sf::Vector2f{height, width});
    rectangle.setPosition(position);

    switch(cellType) {
        case Cell::Wall:
            rectangle.setFillColor(Cell::wallColor);
            break;
        case Cell::Floor:
            rectangle.setFillColor(Cell::floorColor);
            break;
        default:
            rectangle.setFillColor(Cell::undefinedColor);
            break;
    }
    target.draw(rectangle);
}
