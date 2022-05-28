//
// Created by popas on 27.05.2022.
//

#include "../headers/Util.h"

std::string Util::resourcesBasePath = "resources/";
std::string Util::texturesBasePath = "textures/";

void Util::addShadow(sf::RenderWindow &window) {
    sf::Vector2u windowSize = window.getSize();

    sf::RectangleShape shadow;
    shadow.setSize(window.mapPixelToCoords(sf::Vector2i(windowSize)));
    sf::Color color = sf::Color::Black;

    const int shadowAlpha = 150;
    color.a = shadowAlpha;
    shadow.setFillColor(color);

    window.draw(shadow);
}

sf::Vector2f Util::centerRectInsideWindow(sf::RenderWindow &window, sf::FloatRect rect) {
    sf::Vector2u windowSize = window.getSize();
    sf::Vector2f windowCoords = window.mapPixelToCoords(sf::Vector2i(windowSize));

    // Center horizontally
    auto bigWidth = (float)windowCoords.x;
    float smallWidth = rect.width;
    float x = (bigWidth - smallWidth) / 2;

    // Center vertically
    auto bigHeight = (float)windowCoords.y;
    float smallHeight = rect.height;
    float y = (bigHeight - smallHeight) / 2;

    return {x, y};
}

[[maybe_unused]] std::string Util::getResourcesBasePath() {
    return resourcesBasePath;
}

std::string Util::getTexturesBasePath() {
    return getResourcesBasePath() + texturesBasePath;
}
