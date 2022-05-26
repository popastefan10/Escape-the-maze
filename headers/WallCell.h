#ifndef OOP_WALLCELL_H
#define OOP_WALLCELL_H

#include "Cell.h"

class WallCell : public Cell {

public:
    // constructors
    explicit WallCell(float height = 0, float width = 0, sf::Vector2f = sf::Vector2f{});
    WallCell(const WallCell &) = default;
    [[maybe_unused]] std::shared_ptr<Cell> clone() override;

    // operators
    void afisare(std::ostream &) const override;
    friend std::ostream & operator << (std::ostream &, const WallCell &);

    // draw inherited din sf::Drawable
    void draw(sf::RenderTarget &, sf::RenderStates) const override;

    bool canWalkOn() override;

};


#endif //OOP_WALLCELL_H
