//
// Created by popas on 27.05.2022.
//

#include "../headers/Util.h"

std::string Util::resourcesBasePath = "resources/";
std::string Util::texturesBasePath = "textures/";
std::string Util::configsBasePath = "configs/";

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

void Util::drawMessage(sf::RenderWindow &window, const std::string &message) {
    sf::Font font;
    font.loadFromFile("resources/fonts/Minecraft.ttf");
    sf::Text text;
    text.setFont(font);
    text.setString(message);
    text.setCharacterSize(30);
    text.setFillColor(sf::Color::Green);

    text.setPosition(Util::centerRectInsideWindow(window, text.getGlobalBounds()));

    window.draw(text);
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

std::string Util::getConfigBasePath() {
    return getResourcesBasePath() + configsBasePath;
}
