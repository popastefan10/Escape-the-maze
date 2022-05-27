//
// Created by popas on 15.03.2022.
//

#include "../headers/Game.h"

// constructors
Game::Game(sf::RenderWindow &window, const std::string & configFile) :
    window(window), map(configFile), player() {
    sf::Vector2f cellSize = map.getCellSize();
    player.setSize(cellSize);
}

[[maybe_unused]] Game::Game(const Game &rhs) = default;

// destructor
Game::~Game() = default;

void Game::start() {
    window.setVerticalSyncEnabled(true); // call it once, after creating the window

    window.setFramerateLimit(60); // call it once, after creating the window

    // change the position of the window (relatively to the desktop)
    window.setPosition(sf::Vector2i(0, 0));

    const unsigned int MODE_WIDTH = 900;
    const unsigned int MODE_HEIGHT = 900;
    window.setSize(sf::Vector2u(MODE_WIDTH, MODE_HEIGHT));

    // change the title of the window
    window.setTitle("SFML window");

    const sf::Vector2i startPosition(1, 0);
    const sf::Vector2i endPosition(29, 30);
    bool finishedGame = false;
    player.setPosition(startPosition);

    // run the program as long as the window is open
    while (window.isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event{};
        while (window.pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();

            if (event.type == sf::Event::KeyPressed) {
                sf::Vector2i playerPosition = player.getPosition();

                switch(event.key.code) {
                    case sf::Keyboard::Up: {
                        playerPosition.y--;
                        break;
                    }
                    case sf::Keyboard::Right: {
                        playerPosition.x++;
                        break;
                    }
                    case sf::Keyboard::Down: {
                        playerPosition.y++;
                        break;
                    }
                    case sf::Keyboard::Left: {
                        playerPosition.x--;
                        break;
                    }
                    default:
                        break;
                }

                if(!finishedGame && map.isInside(playerPosition) && map.canWalkOn(playerPosition)) {
                    player.setPosition(playerPosition);
                    std::cout << "X = " << playerPosition.x << ", Y = " << playerPosition.y << std::endl;
                }
                if(playerPosition == endPosition)
                    finishedGame = true;
            }
        }

        // clear the window with black color
        window.clear(sf::Color::Black);

        // draw everything here...
        window.draw(map);
        window.draw(player);
        if(finishedGame) {
            Util::addShadow(window);

            // Draw the game winning text
            sf::Font font;
            font.loadFromFile("resources/fonts/Minecraft.ttf");
            sf::Text text;
            text.setFont(font);
            text.setString("You won!");
            text.setCharacterSize(24);
            text.setFillColor(sf::Color::Green);

            text.setPosition(Util::centerRectInsideWindow(window, text.getGlobalBounds()));

            window.draw(text);
        }

        // end the current frame
        window.display();
    }
}

void Game::loadTextures() {
    Cell::loadTextures();
}
