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

std::map<std::string, Level> PredefinedLevels::levelsRegistry;

void PredefinedLevels::generateLevels() {
    levelsRegistry.insert(std::make_pair(
        "level1",
        Level(
            "resources/mapConfigs/level1.txt",
            {1, 0},
            {29, 30}
        )
    ));

    levelsRegistry.insert(std::make_pair(
            "level2",
            Level(
                    "resources/mapConfigs/level2.txt",
                    {1, 0},
                    {9, 10}
            )
    ));

    levelsRegistry.insert(std::make_pair(
            "level3",
            Level(
                    "resources/mapConfigs/level3.txt",
                    {1, 0},
                    {19, 20}
            )
    ));
}

Level PredefinedLevels::getLevel(const std::string& levelID) {
    return levelsRegistry[levelID];
}
