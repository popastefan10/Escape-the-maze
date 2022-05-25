//
// Created by popas on 25.05.2022.
//

#ifndef OOP_UNDEFINEDCELL_H
#define OOP_UNDEFINEDCELL_H

#include "Cell.h"

class UndefinedCell : public Cell {

public:
    // constructors
    explicit UndefinedCell(float height = 0, float width = 0, sf::Vector2f = sf::Vector2f{});
    UndefinedCell(const UndefinedCell &) = default;
    UndefinedCell *clone() override;

    // operators
    void afisare(std::ostream &) const override;
    friend std::ostream & operator << (std::ostream &, const UndefinedCell &);

    // draw inherited din sf::Drawable
    void draw(sf::RenderTarget &, sf::RenderStates) const override;

    bool canWalkOn() override;

};


#endif //OOP_UNDEFINEDCELL_H
