#include <SFML/Window.hpp>
#include "SFML/Graphics.hpp"
#include "SFML/System.hpp"
#include <iostream>
#include "headers/Map.h"

int main()
{
    Map map("resources/mapConfig.txt");
    std::cout << map;

    sf::RenderWindow window(sf::VideoMode(800, 600), "My window");

    window.setVerticalSyncEnabled(true); // call it once, after creating the window

    window.setFramerateLimit(60); // call it once, after creating the window

    // change the position of the window (relatively to the desktop)
    window.setPosition(sf::Vector2i(10, 200));

    // change the size of the window
    window.setSize(sf::Vector2u(640, 480));

    // change the title of the window
    window.setTitle("SFML window");

    // get the size of the window
    sf::Vector2u size = window.getSize();
    unsigned int width = size.x;
    unsigned int height = size.y;

    std::cout << "Windows width: " << width << "\n";
    std::cout << "Windows height: " << height << "\n";

    // get the position of the window
    sf::Vector2i position = window.getPosition();
    int x = position.x;
    int y = position.y;

    std::cout << "Windows x-coordinate: " << x << "\n";
    std::cout << "Windows y-coordinate: " << y << "\n";

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
        // window.draw(...);

        // end the current frame
        window.display();
    }

    return 0;
}