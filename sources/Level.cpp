//
// Created by popas on 28.05.2022.
//

#include "../headers/Level.h"

#include <utility>

Level::Level() : startPosition({0, 0}), endPosition({0, 0}) {}

Level::Level(std::string mapConfigFilename, sf::Vector2u startPosition, sf::Vector2u endPosition) :
    mapConfigFilename(std::move(mapConfigFilename)), startPosition(startPosition), endPosition(endPosition) {}

std::string Level::getMapConfigFilename() {
    return mapConfigFilename;
}

sf::Vector2u Level::getStartPosition() {
    return startPosition;
}

sf::Vector2u Level::getEndPosition() {
    return endPosition;
}

// PredefinedLevels //////////////////////////////

Level PredefinedLevels::getLevel1() {
    return {"resources/mapConfig.txt", {1, 0}, {29, 30}};
}
