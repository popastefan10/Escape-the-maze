//
// Created by popas on 28.05.2022.
//

#ifndef OOP_LEVEL_H
#define OOP_LEVEL_H

#include <string>
#include "SFML/Graphics.hpp"

class Level {

private:
    std::string mapConfigFilename;
    sf::Vector2u startPosition;
    sf::Vector2u endPosition;

public:
    Level();
    Level(std::string, sf::Vector2u, sf::Vector2u);

    std::string getMapConfigFilename();
    sf::Vector2u getStartPosition();
    sf::Vector2u getEndPosition();
};

// Factory
class PredefinedLevels {

public:
    static Level getLevel1();
};

#endif //OOP_LEVEL_H
