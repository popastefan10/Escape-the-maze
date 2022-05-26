//
// Created by popas on 14.03.2022.
//

#include "../headers/Cell.h"

// constructors
Cell::Cell(float height, float width, sf::Vector2f position) :
    width(width), height(height), position(position) {
    loadResources();
}

Cell::Cell(const Cell &rhs) :
    width(rhs.width), height(rhs.height), position(rhs.position),
    wallTexture(rhs.wallTexture), floorTexture(rhs.floorTexture) {}

// destructor
Cell::~Cell() = default;

// operators
Cell & Cell::operator = (const Cell &rhs) {
    width = rhs.width;
    height = rhs.height;
    position = rhs.position;

    wallTexture = rhs.wallTexture;
    floorTexture = rhs.wallTexture;

    return *this;
}

std::ostream &operator<<(std::ostream &os, const Cell &cell) {
    cell.afisare(os);
    return os;
}

void Cell::loadResources() {
    wallTexture.loadFromFile("resources/bedrock.png");
    floorTexture.loadFromFile("resources/smooth_stone.png");
}