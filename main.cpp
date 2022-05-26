#include "headers/Game.h"
#include "headers/TextureHolder.h"

int main() {

    Game::loadTextures();

    sf::RenderWindow window(sf::VideoMode(465, 465), "Escape the Maze");
    Game game(window, "resources/mapConfig.txt");
    game.start();

//    TextureHolder textures;
//    textures.load(Textures::Bedrock, "resources/bedrock.png");
//
//    sf::RenderWindow window(sf::VideoMode(465, 465), "Escape the Maze");
//    sf::RectangleShape rect(sf::Vector2f(30, 15));
//    rect.setTexture(&textures.get(Textures::Bedrock));
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