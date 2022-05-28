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

        cells.emplace_back(std::vector< std::shared_ptr<Cell> >());
        std::shared_ptr<Cell> cell_ptr;
        for(int j = 0; j < width; j++) {
            switch (crtLine[j]) {
                case '#':
                    cell_ptr = std::make_shared<WallCell>(cellHeight, cellWidth, cellPosition);
                    break;
                case ' ':
                    cell_ptr = std::make_shared<FloorCell>(cellHeight, cellWidth, cellPosition);
                    break;
                default:
                    cell_ptr = std::make_shared<UndefinedCell>(cellHeight, cellWidth, cellPosition);
                    break;
            }

            cells[i].emplace_back(cell_ptr);
            cellPosition.x += cellWidth;
        }

        cellPosition.x = 0.0;
        cellPosition.y += cellHeight;
    }
}

// constructors
Map::Map() : width{0}, height{0}, cellWidth{0}, cellHeight{0} {
    std::cout << "Ctr Map fara parametri\n";
}

Map::Map(const std::string &configFile) : width{0}, height{0}, cellWidth{0}, cellHeight{0} {
    std::cout << "Construiesc harta cu 1 param: " << configFile << std::endl;
    parseConfigFile(configFile);
    std::cout << "Dupa ce am parsat harta\n";
}

[[maybe_unused]] Map::Map(const Map &rhs) :
    width(rhs.width), height(rhs.height), cellWidth(rhs.cellWidth), cellHeight(rhs.cellHeight) {
    cells.clear();
    for(int i = 0; i < height; i++) {
        cells.emplace_back();
        for (int j = 0; j < width; j++)
            cells[i].emplace_back(rhs.cells[i][j]->clone());
    }
}

// destructor
Map::~Map() = default;

// operators
void swap(Map &lhs, Map &rhs) {
    using std::swap;

    swap(lhs.height, rhs.height);
    swap(lhs.width, rhs.width);
    swap(lhs.cellHeight, rhs.cellHeight);
    swap(lhs.cellWidth, rhs.cellWidth);
    swap(lhs.cells, rhs.cells);
}

Map & Map::operator = (const Map &rhs) {
    Map copy(rhs);
    swap(*this, copy);
    return *this;
}

std::ostream & operator << (std::ostream &os, const Map &map) {
    os << "width: " << map.width << " height: " << map.height << "\n";
    for(int i = 0; i < map.width; i++) {
        for (int j = 0; j < map.height; j++)
            os << *map.cells[i][j];
        os << '\n';
    }

    return os;
}

const std::vector< std::shared_ptr< Cell > > & Map::operator [] (int line) {
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
            target.draw(*cells[i][j]);
        }
}

bool Map::isInside(const sf::Vector2i &position) const {
    return position.x >= 0 && position.x < width && position.y >= 0 && position.y < height;
}

bool Map::canWalkOn(const sf::Vector2i &position) {
    return cells[position.y][position.x]->canWalkOn();
}
