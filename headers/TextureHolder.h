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

template <typename Identifier>
class [[maybe_unused]] TextureHolder {
    std::map<Identifier, std::unique_ptr<sf::Texture>> mTextureMap;

public:
    [[maybe_unused]] void load(Identifier id, const std::string &filename);

    sf::Texture& get(Identifier id);
    [[nodiscard]] const sf::Texture& get(Identifier id) const;
};

#endif //OOP_TEXTUREHOLDER_H
