//
// Created by popas on 14.03.2022.
//

#include <iostream>
#include <fstream>
#include "../headers/Map.h"

void Map::parseConfigFile(const std::string &configFile) {
    std::ifstream fin(configFile);

    fin >> height >> width;
    fin >> cellHeight >> cellWidth;
    fin.get();

    std::string crtLine;
    sf::Vector2f cellPosition{0.0, 0.0};

    for(int i = 0; i < height; i++) {
        std::getline(fin, crtLine);

        cells.emplace_back(std::vector<Cell>());
        for(int j = 0; j < width; j++) {
            switch (crtLine[j]) {
                case '#':
                    cells[i].emplace_back(Cell(Cell::Wall, cellHeight, cellWidth, cellPosition));
                    break;
                case ' ':
                    cells[i].emplace_back(Cell(Cell::Floor, cellHeight, cellWidth, cellPosition));
                    break;
                default:
                    cells[i].emplace_back(Cell(Cell::Undefined, cellHeight, cellWidth, cellPosition));
                    break;
            }

            cellPosition.x += cellWidth;
        }

        cellPosition.x = 0.0;
        cellPosition.y += cellHeight;
    }
}

// constructors
Map::Map() : height{0}, width{0}, cellHeight{0}, cellWidth{0} {}

[[maybe_unused]] Map::Map(const std::string &configFile) : height{0}, width{0}, cellHeight{0}, cellWidth{0} {
    parseConfigFile(configFile);
}

// operators
Map & Map::operator = (const Map &rhs) = default;

std::ostream & operator << (std::ostream &os, const Map &map) {
    os << "width: " << map.width << " height: " << map.height << "\n";
    for(int i = 0; i < map.width; i++) {
        for (int j = 0; j < map.height; j++)
            os << map.cells[i][j];
        os << '\n';
    }

    return os;
}

const std::vector<Cell> & Map::operator [] (int line) {
    return cells[line];
}

// getters / setters
int Map::getHeight() const { return height; }
[[maybe_unused]] int Map::getWidth() const { return width; }

// draw derived din sf::Drawable
void Map::draw(sf::RenderTarget &target, sf::RenderStates) const {
    for(int i = 0; i < height; i++)
        for(int j = 0; j < width; j++)
            target.draw(cells[i][j]);
}
