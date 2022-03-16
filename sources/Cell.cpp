//
// Created by popas on 14.03.2022.
//

#include "../headers/Cell.h"

// constructors
Cell::Cell(CellType cellType, sf::Vector2f size, sf::Vector2f position) :
    cellType(cellType), size(size), position(position) {
    loadResources();
}

Cell::Cell(const Cell &rhs) :
cellType(rhs.cellType), size(rhs.size), position(rhs.position),
wallTexture(rhs.wallTexture), floorTexture(rhs.floorTexture) {}

// destructor
Cell::~Cell() = default;

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
[[maybe_unused]] Cell::CellType Cell::getCellType() {
    return cellType;
}

// draw inherited from sf::Drawable
void Cell::draw(sf::RenderTarget &target, sf::RenderStates) const {
    sf::RectangleShape rectangle(size);
    rectangle.setPosition(position);

//    sf::Texture wallTexture;
//    wallTexture.loadFromFile("resources/bedrock.png");
//
//    sf::Texture floorTexture;
//    floorTexture.loadFromFile("resources/smooth_stone.png");

    switch(cellType) {
        case Cell::Wall: {
            rectangle.setTexture(&wallTexture);
            break;
        }
        case Cell::Floor: {
            rectangle.setTexture(&floorTexture);
            break;
        }
        default: {
            rectangle.setFillColor(sf::Color::Black);
            break;
        }
    }

    target.draw(rectangle);
}

void Cell::loadResources() {
    wallTexture.loadFromFile("resources/bedrock.png");
    floorTexture.loadFromFile("resources/smooth_stone.png");
}