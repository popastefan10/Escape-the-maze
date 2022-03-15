#include "headers/Game.h"

int main() {

    sf::RenderWindow window(sf::VideoMode(800, 600), "My window");
    Game game(window, "resources/mapConfig.txt");
    game.start();

    return 0;
}