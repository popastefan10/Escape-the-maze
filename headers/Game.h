//
// Created by popas on 15.03.2022.
//

#ifndef OOP_GAME_H
#define OOP_GAME_H

#include "Map.h"
#include "Player.h"
#include "Util.h"
#include "Level.h"
#include <string>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <iostream>

// Singleton
class Game {
    sf::RenderWindow &window;
    Level level;
    Map map;
    Player player;

private:
    explicit Game(sf::RenderWindow &);

public:
    Game(const Game &) = delete;
    Game & operator = (const Game &) = delete;
    static Game & getGame(sf::RenderWindow &);

    // destructor
    ~Game();

    void start();

    void loadLevel(const std::string &);
    static void loadTextures();
};


#endif //OOP_GAME_H
