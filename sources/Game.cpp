//
// Created by popas on 15.03.2022.
//

#include "../headers/Game.h"

// constructors
[[maybe_unused]] Game::Game(sf::RenderWindow &window, const std::string & configFile) :
    window(window), map{configFile} {}

void Game::start() {
    std::cout << map;

    window.setVerticalSyncEnabled(true); // call it once, after creating the window

    window.setFramerateLimit(60); // call it once, after creating the window

    // change the position of the window (relatively to the desktop)
    window.setPosition(sf::Vector2i(10, 200));

    // change the size of the window
    window.setSize(sf::Vector2u(640, 480));

    // change the title of the window
    window.setTitle("SFML window");

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

            if (event.type == sf::Event::KeyPressed)
            {
                if (event.key.code == sf::Keyboard::Escape)
                {
                    std::cout << "the escape key was pressed" << std::endl;
                    std::cout << "control:" << event.key.control << std::endl;
                    std::cout << "alt:" << event.key.alt << std::endl;
                    std::cout << "shift:" << event.key.shift << std::endl;
                    std::cout << "system:" << event.key.system << std::endl;
                }
                if(event.key.code == sf::Keyboard::Right) {
                    std::cout << "the right arrow was pressed" << std::endl;
                }
            }
        }

        // clear the window with black color
        window.clear(sf::Color::Black);

        // draw everything here...
        window.draw(map);

        // end the current frame
        window.display();
    }
}
