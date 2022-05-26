//
// Created by popas on 14.03.2022.
//

#include "../headers/Cell.h"

// static members
TextureHolder<CellTextures::ID> Cell::cellTextureHolder;

void Cell::loadTextures() {
    cellTextureHolder.load(CellTextures::Bedrock, "resources/bedrock.png");
    cellTextureHolder.load(CellTextures::SmoothStone, "resources/smooth_stone.png");
}

// constructors
Cell::Cell(float height, float width, sf::Vector2f position) :
    width(width), height(height), position(position) {
}

Cell::Cell(const Cell &rhs) :
    width(rhs.width), height(rhs.height), position(rhs.position) {}

// destructor
Cell::~Cell() = default;

// operators
Cell & Cell::operator = (const Cell &rhs) {
    width = rhs.width;
    height = rhs.height;
    position = rhs.position;

    return *this;
}

std::ostream &operator<<(std::ostream &os, const Cell &cell) {
    cell.afisare(os);
    return os;
}