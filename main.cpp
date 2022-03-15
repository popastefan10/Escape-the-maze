#include "headers/Game.h"

int main() {

    sf::RenderWindow window(sf::VideoMode(465, 465), "Escape the Maze");
    Game game(window, "resources/mapConfig.txt");
    game.start();

    return 0;
}