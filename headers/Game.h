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

// Singleton
class Game {
    sf::RenderWindow &window;
    Map map;
    Player player;

private:
    explicit Game(sf::RenderWindow &, const std::string &);

public:
    Game(const Game &) = delete;
    Game & operator = (const Game &) = delete;
    static Game & getGame(sf::RenderWindow &, const std::string &);

    // destructor
    ~Game();

    void start();

    static void loadTextures();
};


#endif //OOP_GAME_H
