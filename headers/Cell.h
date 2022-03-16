//
// Created by popas on 14.03.2022.
//

#ifndef OOP_CELL_H
#define OOP_CELL_H

#include <iostream>
#include "SFML/Graphics.hpp"

class Cell : public sf::Drawable {

public:
    enum CellType {
        Undefined,
        Wall,
        Floor,
    };

private:
    CellType cellType;
    sf::Vector2f size;
    sf::Vector2f position;

public:
    // constructors
    explicit Cell(CellType = Cell::Undefined, sf::Vector2f = sf::Vector2f{}, sf::Vector2f = sf::Vector2f{});
    Cell(const Cell &);

    //destructor
    ~Cell();

    // operators
    Cell & operator = (const Cell &);
    friend std::ostream & operator << (std::ostream &, const Cell &);

    // getters / setters
    [[maybe_unused]] CellType getCellType();
    [[maybe_unused]] void setCellType(CellType);

    // draw inherited din sf::Drawable
    virtual void draw(sf::RenderTarget &, sf::RenderStates) const;
};

#endif //OOP_CELL_H
