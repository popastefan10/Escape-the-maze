//
// Created by Stefan on 12.04.2022.
//

// Cod luat din cartea
// SFML Game Development Learn how to use SFML 2.0 to develop your own feature-packed game
// (Artur Moreira, Jan Haller etc.)

#include "../headers/TextureHolder.h"

template <typename Identifier>
void TextureHolder<Identifier>::load(Identifier id, const std::string &filename) {
    std::unique_ptr<sf::Texture> texture(new sf::Texture());
    texture->loadFromFile(filename);

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
