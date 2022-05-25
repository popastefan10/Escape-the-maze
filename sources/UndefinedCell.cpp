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

bool UndefinedCell::canWalkOn() {
    return false;
}