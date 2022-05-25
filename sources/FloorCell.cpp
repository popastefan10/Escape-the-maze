//
// Created by popas on 25.05.2022.
//

#include "../headers/FloorCell.h"

FloorCell::FloorCell(float height, float witdh, sf::Vector2f position) :
        Cell(CellType::Floor, height, witdh, position) {}

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

bool FloorCell::canWalkOn() {
    return true;
}