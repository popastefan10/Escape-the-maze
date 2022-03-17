#include "headers/Game.h"

int main() {

    sf::RenderWindow window(sf::VideoMode(465, 465), "Escape the Maze");
    Game game(window, "resources/mapConfig.txt");
    game.start();

//    sf::RectangleShape rect(sf::Vector2f(30, 15));
//    while(window.isOpen()) {
//        sf::Event event;
//        while(window.pollEvent(event)) {
//            if(event.type == sf::Event::Closed)
//                window.close();
//        }
//
//        window.clear();
//        window.draw(rect);
//        window.display();
//    }

    return 0;
}