//
// Created by popas on 15.03.2022.
//

#ifndef OOP_GAME_H
#define OOP_GAME_H

#include "Map.h"
#include "Player.h"
#include <string>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <iostream>

class Game {
    sf::RenderWindow &window;
    Map map;
    Player player;

public:
    // constructors
    [[maybe_unused]] explicit Game(sf::RenderWindow &, const std::string &);

    void start();
};


#endif //OOP_GAME_H
