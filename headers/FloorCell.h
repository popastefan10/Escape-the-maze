//
// Created by popas on 25.05.2022.
//

#ifndef OOP_FLOORCELL_H
#define OOP_FLOORCELL_H

#include "Cell.h"

class FloorCell : public Cell {

public:
    explicit FloorCell(float height = 0, float width = 0, sf::Vector2f = sf::Vector2f{});
    FloorCell(const FloorCell &) = default;
    FloorCell *clone() override;

    bool canWalkOn() override;

};


#endif //OOP_FLOORCELL_H
