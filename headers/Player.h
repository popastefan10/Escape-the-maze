//
// Created by popas on 15.03.2022.
//

#ifndef OOP_PLAYER_H
#define OOP_PLAYER_H

#include "SFML/Graphics.hpp"

class Player : public sf::Drawable {
    float width;
    float height;
    sf::Vector2i position;
    sf::Texture playerTexture;

public:
    // constructors
    Player();

    [[maybe_unused]] explicit Player(float, float, const sf::Vector2i &);

    // getters / setters
    sf::Vector2i getPosition();
    void setPosition(const sf::Vector2i &);

    void setSize(const sf::Vector2f &);

    // draw inherited from sf::Drawable
    void draw(sf::RenderTarget &, sf::RenderStates) const override;

private:
    void loadTextures();
};


#endif //OOP_PLAYER_H
