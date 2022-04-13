//
// Created by Stefan on 12.04.2022.
//

// Cod luat din cartea
// SFML Game Development Learn how to use SFML 2.0 to develop your own feature-packed game
// (Artur Moreira, Jan Haller etc.)

#ifndef OOP_TEXTUREHOLDER_H
#define OOP_TEXTUREHOLDER_H

#include <map>
#include <memory>
#include "SFML/Graphics.hpp"

namespace Textures {
    enum ID {
        Bedrock,
        SmoothStone,
        TotemOfUndying
    };
}

class TextureHolder {
    std::map<Textures::ID, std::unique_ptr<sf::Texture>> mTextureMap;

public:
    void load(Textures::ID id, const std::string &filename);

    sf::Texture& get(Textures::ID id);
    [[nodiscard]] const sf::Texture& get(Textures::ID id) const;
};

#endif //OOP_TEXTUREHOLDER_H
