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
#include "Exceptions.h"

template <typename Identifier>
class TextureHolder {
    std::map<Identifier, std::unique_ptr<sf::Texture>> mTextureMap;

public:
    void load(Identifier id, const std::string &filename);

    sf::Texture& get(Identifier id);
    [[nodiscard]] const sf::Texture& get(Identifier id) const;
};

template <typename Identifier>
void TextureHolder<Identifier>::load(Identifier id, const std::string &filename) {
    std::unique_ptr<sf::Texture> texture(new sf::Texture());
    if(!texture->loadFromFile(filename)) {
        if(filename.empty())
            throw FailedTextureLoad();
        else
            throw FailedTextureLoad(filename);
    }

    mTextureMap.insert(std::make_pair(id, std::move(texture)));
}

template <typename Identifier>
sf::Texture &TextureHolder<Identifier>::get(Identifier id) {
    auto found = mTextureMap.find(id);
    return *found->second;
}

template <typename Identifier>
const sf::Texture &TextureHolder<Identifier>::get(Identifier id) const {
    auto found = mTextureMap.find(id);
    return *found->second;
}

#endif //OOP_TEXTUREHOLDER_H
