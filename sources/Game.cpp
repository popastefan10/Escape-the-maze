//
// Created by popas on 15.03.2022.
//

#include "../headers/Game.h"

// constructors
Game::Game(sf::RenderWindow &window) :
    window(window), map(), player() {

    // Static functions initialization
    PredefinedLevels::generateLevels();
    // Textures will load only once, since Game class is a singleton
    Game::loadTextures();

    loadLevel("level1");
}

Game &Game::getGame(sf::RenderWindow &window) {
    static Game game(window);
    return game;
}

// destructor
Game::~Game() = default;

void Game::start() {
    window.setVerticalSyncEnabled(true); // call it once, after creating the window

    window.setFramerateLimit(60); // call it once, after creating the window

    // change the position of the window (relatively to the desktop)
    window.setPosition(sf::Vector2i(0, 0));

    // change the title of the window
    window.setTitle("SFML window");

    std::vector< std::string > levelIDs = {
        "level1",
        "level2",
        "level3",
    };
    int currentLevelIdx = 0;
    loadLevel(levelIDs[currentLevelIdx]);
    bool finishedLevel = false;
    bool gameWon = false;
    sf::Vector2i endPosition = (sf::Vector2i)level.getEndPosition();

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

                if(!finishedLevel && map.isInside(playerPosition) && map.canWalkOn(playerPosition))
                    player.setPosition(playerPosition);
                if(playerPosition == endPosition)
                    finishedLevel = true;
            }
        }

        // clear the window with black color
        window.clear(sf::Color::Black);

        // draw everything here...
        window.draw(map);
        window.draw(player);
        if(finishedLevel) {
            currentLevelIdx++;
            finishedLevel = false;

            if(currentLevelIdx == (int)levelIDs.size()) {
                gameWon = true;
            }
            else {
                loadLevel(levelIDs[currentLevelIdx]);
                endPosition = (sf::Vector2i)level.getEndPosition();
            }
        }
        if(gameWon) {
            Util::addShadow(window);

            // Draw the game winning text
            sf::Font font;
            font.loadFromFile("resources/fonts/Minecraft.ttf");
            sf::Text text;
            text.setFont(font);
            text.setString("You won!");
            text.setCharacterSize(30);
            text.setFillColor(sf::Color::Green);

            text.setPosition(Util::centerRectInsideWindow(window, text.getGlobalBounds()));

            window.draw(text);
        }

        // end the current frame
        window.display();
    }
}

void Game::loadLevel(const std::string &levelID) {
    try {
        level = PredefinedLevels::getLevel(levelID);
        map = Map(level.getMapConfigFilename());

        sf::Vector2f cellSize = map.getCellSize();
        player.setSize(cellSize);

        // Adding special cells to the map
        map.setStartPosition(level.getStartPosition());
        map.setEndPosition(level.getEndPosition());

        // Moving player to the start
        player.setPosition(sf::Vector2i(level.getStartPosition()));

        // Resizing the window
        sf::Vector2f mapSize = map.getMapSize();
        sf::Vector2i mapSizeInPixels = window.mapCoordsToPixel(mapSize);
        window.setSize((sf::Vector2u)mapSizeInPixels);

        // Setting a new view
        sf::View view(sf::FloatRect(0.0, 0.0, mapSize.y, mapSize.x));
        window.setView(view);
    }
    catch(BadID &e) {
        std::cout << e.what() << std::endl;
    }
}

void Game::loadTextures() {
    Cell::loadTextures();
    Player::loadTextures();
}
