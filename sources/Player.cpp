//
// Created by popas on 15.03.2022.
//

#include "../headers/Player.h"

// static members
TextureHolder<std::string> Player::playerTextureHolder;

void Player::loadTextures() {
    const std::string texturesBasePath = "resources/";
    const std::vector< std::pair< std::string, std::string > > textures = {
        std::make_pair("totem_of_undying", "totem_of_undying.png"),
    };

    // This way if a texture is not loaded the other textures won't be affected
    for(const std::pair< std::string, std::string > &texture : textures) {
        try {
            playerTextureHolder.load(texture.first, texturesBasePath + texture.second);
        }
        catch (FailedTextureLoad &e) {
            std::cout << e.what() << std::endl;
        }
    }
}

// constructors
Player::Player() :
    width(0), height(0), position(sf::Vector2i(0, 0)) {}

[[maybe_unused]] Player::Player(float width, float height, const sf::Vector2i &position) :
width(width), height(height), position(position) {
    loadTextures();
}

// getters / setters
sf::Vector2i Player::getPosition() {
    return position;
}

void Player::setPosition(const sf::Vector2i &newPosition) {
    position = newPosition;
}

void Player::setSize(const sf::Vector2f &newSize) {
    width = newSize.x;
    height = newSize.y;
}

// draw inherited from sf::Drawable
void Player::draw(sf::RenderTarget &target, sf::RenderStates) const {
    sf::RectangleShape rectangle;
    rectangle.setSize(sf::Vector2f(width, height));
    rectangle.setPosition(sf::Vector2f(width * (float)position.x, height * (float)position.y));

    sf::Texture &playerTexture = playerTextureHolder.get("totem_of_undying");
    rectangle.setTexture(&playerTexture);
    target.draw(rectangle);
}
