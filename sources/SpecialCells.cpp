//
// Created by popas on 28.05.2022.
//

#include "../headers/SpecialCells.h"

StartCell::StartCell(float height, float witdh, sf::Vector2f position) :
        FloorCell(height, witdh, position) {}

// draw inherited from sf::Drawable
void StartCell::draw(sf::RenderTarget &target, sf::RenderStates) const {
    sf::RectangleShape rectangle(sf::Vector2f(width, height));
    rectangle.setPosition(position);
    sf::Texture &floorCellTexture = cellTextureHolder.get(CellTextures::RedWool);
    rectangle.setTexture(&floorCellTexture);
    target.draw(rectangle);
}

EndCell::EndCell(float height, float witdh, sf::Vector2f position) :
        FloorCell(height, witdh, position) {}

// draw inherited from sf::Drawable
void EndCell::draw(sf::RenderTarget &target, sf::RenderStates) const {
    sf::RectangleShape rectangle(sf::Vector2f(width, height));
    rectangle.setPosition(position);
    sf::Texture &floorCellTexture = cellTextureHolder.get(CellTextures::LimeWool);
    rectangle.setTexture(&floorCellTexture);
    target.draw(rectangle);
}