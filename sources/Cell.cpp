//
// Created by popas on 14.03.2022.
//

#include "../headers/Cell.h"

// static members
TextureHolder<CellTextures::ID> Cell::cellTextureHolder;

void Cell::loadTextures() {
    const std::string texturesBasePath = Util::getTexturesBasePath();
    const std::vector< std::pair< CellTextures::ID, std::string > > textures = {
            std::make_pair(CellTextures::Bedrock, "bedrock.png"),
            std::make_pair(CellTextures::SmoothStone, "smooth_stone.png")
    };

    // This way if a texture is not loaded the other textures won't be affected
    for(const std::pair< CellTextures::ID, std::string > &texture : textures) {
        try {
            cellTextureHolder.load(texture.first, texturesBasePath + texture.second);
        }
        catch (FailedTextureLoad &e) {
            std::cout << e.what() << std::endl;
        }
    }
}

// constructors
Cell::Cell(float height, float width, sf::Vector2f position) :
    width(width), height(height), position(position) {
}

Cell::Cell(const Cell &rhs) :
    width(rhs.width), height(rhs.height), position(rhs.position) {}

// destructor
Cell::~Cell() = default;

// operators
Cell & Cell::operator = (const Cell &rhs) {
    width = rhs.width;
    height = rhs.height;
    position = rhs.position;

    return *this;
}

std::ostream &operator<<(std::ostream &os, const Cell &cell) {
    cell.afisare(os);
    return os;
}