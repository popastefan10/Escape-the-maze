//
// Created by popas on 25.05.2022.
//

#include "../headers/UndefinedCell.h"

UndefinedCell::UndefinedCell(float height, float witdh, sf::Vector2f position) :
    Cell(CellType::Undefined, height, witdh, position) {}

UndefinedCell *UndefinedCell::clone() {
    return new UndefinedCell(*this);
}

bool UndefinedCell::canWalkOn() {
    return false;
}