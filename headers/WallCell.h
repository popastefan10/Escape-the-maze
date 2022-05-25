#ifndef OOP_WALLCELL_H
#define OOP_WALLCELL_H

#include "Cell.h"

class WallCell : public Cell {

public:
    explicit WallCell(float height = 0, float width = 0, sf::Vector2f = sf::Vector2f{});
    WallCell(const WallCell &) = default;
    WallCell *clone() override;

    bool canWalkOn() override;

};


#endif //OOP_WALLCELL_H
