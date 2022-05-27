//
// Created by popas on 15.03.2022.
//

#ifndef OOP_GAME_H
#define OOP_GAME_H

#include "Map.h"
#include "Player.h"
#include "Util.h"
#include <string>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <iostream>

class Game {
    sf::RenderWindow &window;
    Map map;
    Player player;

    static const int textSize = 24;
    sf::Text gameWonText;

public:
    // constructors
    [[maybe_unused]] explicit Game(sf::RenderWindow &, const std::string &);
    [[maybe_unused]] Game(const Game &);

    // destructor
    ~Game();

    void start();

    static void loadTextures();
};


#endif //OOP_GAME_H
