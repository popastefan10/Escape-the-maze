//
// Created by popas on 14.03.2022.
//

#include "../headers/Cell.h"

// constructors
Cell::Cell(CellType cellType, float width, float height, sf::Vector2f position) :
cellType(cellType), width(width), height(height), position(position) {
    loadResources();
}

Cell::Cell(const Cell &rhs) :
cellType(rhs.cellType), width(rhs.width), height(rhs.height), position(rhs.position),
wallTexture(rhs.wallTexture), floorTexture(rhs.floorTexture) {}

Cell *Cell::clone() {
    return new Cell(*this);
}

// destructor
Cell::~Cell() = default;

// operators
Cell & Cell::operator = (const Cell &rhs) {
    cellType = rhs.cellType;
    width = rhs.width;
    height = rhs.height;
    position = rhs.position;

    wallTexture = rhs.wallTexture;
    floorTexture = rhs.wallTexture;

    return *this;
}

void Cell::afisare(std::ostream &os) const {
    switch(cellType) {
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
}

std::ostream &operator<<(std::ostream &os, const Cell &cell) {
    cell.afisare(os);
    return os;
}

// getters / setters
Cell::CellType Cell::getCellType() {
    return cellType;
}

// draw inherited from sf::Drawable
void Cell::draw(sf::RenderTarget &target, sf::RenderStates) const {
    sf::RectangleShape rectangle(sf::Vector2f(width, height));
    rectangle.setPosition(position);

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

bool Cell::canWalkOn() {
    return true;
}

void Cell::loadResources() {
    wallTexture.loadFromFile("resources/bedrock.png");
    floorTexture.loadFromFile("resources/smooth_stone.png");
}