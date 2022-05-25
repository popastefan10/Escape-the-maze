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
    float width;
    float height;
    sf::Vector2f position;

    sf::Texture wallTexture;
    sf::Texture floorTexture;

public:
    // constructors
    explicit Cell(CellType = Cell::Undefined, float height = 0, float width = 0, sf::Vector2f = sf::Vector2f{});
    Cell(const Cell &);
    virtual Cell *clone();

    //destructor
    ~Cell() override;

    // operators
    Cell & operator = (const Cell &);
    virtual void afisare(std::ostream &) const;
    friend std::ostream & operator << (std::ostream &, const Cell &);

    // getters / setters
    CellType getCellType();

    // draw inherited din sf::Drawable
    void draw(sf::RenderTarget &, sf::RenderStates) const override;

    virtual bool canWalkOn();

private:
    void loadResources();
};

#endif //OOP_CELL_H
