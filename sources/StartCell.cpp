//
// Created by popas on 28.05.2022.
//

#include "../headers/StartCell.h"

StartCell::StartCell(float height, float witdh, sf::Vector2f position) :
        FloorCell(height, witdh, position) {}

// draw inherited from sf::Drawable
void StartCell::draw(sf::RenderTarget &target, sf::RenderStates) const {
    sf::RectangleShape rectangle(sf::Vector2f(width, height));
    rectangle.setPosition(position);
    sf::Texture &floorCellTexture = cellTextureHolder.get(CellTextures::RedstoneBlock);
    rectangle.setTexture(&floorCellTexture);
    target.draw(rectangle);
}