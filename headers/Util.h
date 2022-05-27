//
// Created by popas on 27.05.2022.
//

#ifndef OOP_UTIL_H
#define OOP_UTIL_H

#include "SFML/Graphics.hpp"

class Util {

public:
    static void addShadow(sf::RenderWindow &);
    static sf::Vector2f centerRectInsideWindow(sf::RenderWindow &, sf::FloatRect);
};


#endif //OOP_UTIL_H
