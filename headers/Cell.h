//
// Created by popas on 14.03.2022.
//

#ifndef OOP_CELL_H
#define OOP_CELL_H

#include <iostream>

class Cell {

public:
    enum CellType {
        Undefined,
        Wall,
        Floor,
    };

private:
    CellType cellType;

public:
    Cell(CellType = Cell::Undefined);

    void setCellType(CellType);
    CellType getCellType(CellType);

    friend std::ostream & operator << (std::ostream &, const Cell &);
};


#endif //OOP_CELL_H
