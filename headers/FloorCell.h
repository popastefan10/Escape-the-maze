//
// Created by popas on 25.05.2022.
//

#ifndef OOP_FLOORCELL_H
#define OOP_FLOORCELL_H

#include "Cell.h"

class FloorCell : public Cell {

public:
    // constructors
    explicit FloorCell(float height = 0, float width = 0, sf::Vector2f = sf::Vector2f{});
    FloorCell(const FloorCell &) = default;
    FloorCell *clone() override;

    // operators
    void afisare(std::ostream &) const override;
    friend std::ostream & operator << (std::ostream &, const FloorCell &);

    bool canWalkOn() override;

};


#endif //OOP_FLOORCELL_H
