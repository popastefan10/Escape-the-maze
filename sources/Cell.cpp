//
// Created by popas on 14.03.2022.
//

#include "../headers/Cell.h"

Cell::Cell(Cell::CellType cellType_) : cellType(cellType_) {}

[[maybe_unused]] void Cell::setCellType(Cell::CellType cellType_) {
    cellType = cellType_;
}

[[maybe_unused]] Cell::CellType Cell::getCellType(Cell::CellType) {
    return cellType;
}

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
