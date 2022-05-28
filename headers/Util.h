//
// Created by popas on 27.05.2022.
//

#ifndef OOP_UTIL_H
#define OOP_UTIL_H

#include "SFML/Graphics.hpp"

class Util {

private:
    static std::string resourcesBasePath;
    static std::string texturesBasePath;
    static std::string configsBasePath;

public:
    static void addShadow(sf::RenderWindow &);
    static sf::Vector2f centerRectInsideWindow(sf::RenderWindow &, sf::FloatRect);

    static std::string getResourcesBasePath();
    static std::string getTexturesBasePath();
    static std::string getConfigBasePath();
};


#endif //OOP_UTIL_H
