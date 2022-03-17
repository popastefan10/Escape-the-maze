//
// Created by popas on 14.03.2022.
//

#include <iostream>
#include <fstream>
#include "../headers/Map.h"

void Map::parseConfigFile(const std::string &configFile) {
    std::ifstream fin(configFile);

    fin >> width >> height;
    fin >> cellWidth >> cellHeight;
    fin.get();

    std::string crtLine;
    sf::Vector2f cellPosition{0.0, 0.0};

    for(int i = 0; i < height; i++) {
        std::getline(fin, crtLine);

        cells.emplace_back(std::vector<Cell>());
        for(int j = 0; j < width; j++) {
            switch (crtLine[j]) {
                case '#':
                    cells[i].emplace_back(Cell(Cell::Wall, cellWidth, cellHeight, cellPosition));
                    break;
                case ' ':
                    cells[i].emplace_back(Cell(Cell::Floor, cellWidth, cellHeight, cellPosition));
                    break;
                default:
                    cells[i].emplace_back(Cell(Cell::Undefined, cellWidth, cellHeight, cellPosition));
                    break;
            }

            cellPosition.x += cellWidth;
        }

        cellPosition.x = 0.0;
        cellPosition.y += cellHeight;
    }
}

// constructors
Map::Map() : width{0}, height{0}, cellWidth{0}, cellHeight{0} {}

[[maybe_unused]] Map::Map(const std::string &configFile) : width{0}, height{0}, cellWidth{0}, cellHeight{0} {
    parseConfigFile(configFile);
}

[[maybe_unused]] Map::Map(const Map &rhs) :
width(rhs.width), height(rhs.height), cellWidth(rhs.cellWidth), cellHeight(rhs.cellHeight), cells(rhs.cells) {}

// destructor
Map::~Map() = default;

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

// getters
sf::Vector2f Map::getCellSize() const {
    return {cellWidth, cellHeight};
}

// draw inherited din sf::Drawable
void Map::draw(sf::RenderTarget &target, sf::RenderStates) const {
    for(int i = 0; i < height; i++)
        for(int j = 0; j < width; j++) {
            target.draw(cells[i][j]);
        }
}

bool Map::isInside(const sf::Vector2i &position) const {
    return position.x >= 0 && position.x < width && position.y >= 0 && position.y < height;
}

bool Map::isEmpty(const sf::Vector2i &position) {
    return cells[position.y][position.x].getCellType() == Cell::Floor;
}
