//
// Created by popas on 28.05.2022.
//

#ifndef OOP_SPECIALCELLS_H
#define OOP_SPECIALCELLS_H

#include "FloorCell.h"

class StartCell : public FloorCell {

public:
    StartCell(float height = 0, float width = 0, sf::Vector2f = sf::Vector2f{});

    void draw(sf::RenderTarget &, sf::RenderStates) const override;
};

class EndCell : public FloorCell {

public:
    EndCell(float height = 0, float width = 0, sf::Vector2f = sf::Vector2f{});

    void draw(sf::RenderTarget &, sf::RenderStates) const override;
};


#endif //OOP_SPECIALCELLS_H
