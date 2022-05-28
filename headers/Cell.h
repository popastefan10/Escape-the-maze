//
// Created by popas on 14.03.2022.
//

#ifndef OOP_CELL_H
#define OOP_CELL_H

#include <iostream>
#include "SFML/Graphics.hpp"
#include "TextureHolder.h"
#include "Util.h"

namespace CellTextures {
    enum ID {
        Bedrock,
        SmoothStone,
        RedstoneBlock,
        EmeraldBlock,
    };
}

class Cell : public sf::Drawable {

public:
    static TextureHolder<CellTextures::ID> cellTextureHolder;

public:
    static void loadTextures();

protected:
    float width;
    float height;
    sf::Vector2f position;

public:
    // constructors
    explicit Cell(float height = 0, float width = 0, sf::Vector2f = sf::Vector2f{});
    Cell(const Cell &);
    [[maybe_unused]] virtual std::shared_ptr<Cell> clone() = 0;

    //destructor
    ~Cell() override;

    // operators
    Cell & operator = (const Cell &);
    virtual void afisare(std::ostream &) const = 0;
    friend std::ostream & operator << (std::ostream &, const Cell &);

    virtual bool canWalkOn() = 0;
};

#endif //OOP_CELL_H
