//
// Created by popas on 25.05.2022.
//

#include "../headers/WallCell.h"

WallCell::WallCell(float height, float witdh, sf::Vector2f position) :
    Cell(CellType::Wall, height, witdh, position) {}

WallCell *WallCell::clone() {
    return new WallCell(*this);
}

bool WallCell::canWalkOn() {
    return true;
}