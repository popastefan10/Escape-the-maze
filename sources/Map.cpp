//
// Created by popas on 14.03.2022.
//

#include <iostream>
#include <fstream>
#include "../headers/Map.h"

void Map::parseConfigFile(const std::string &configFile) {
    std::ifstream fin(configFile);

    fin >> height >> width;
    fin.get();
    std::string crtLine;
    for(int i = 0; i < height; i++) {
        std::getline(fin, crtLine);

        cells.emplace_back(std::vector<Cell>());
        for(int j = 0; j < width; j++) {
            switch (crtLine[j]) {
                case '#':
                    cells[i].emplace_back(Cell(Cell::Wall));
                    break;
                case ' ':
                    cells[i].emplace_back(Cell(Cell::Floor));
                    break;
                default:
                    cells[i].emplace_back(Cell());
                    break;
            }
        }
    }
}

Map::Map() : height{0}, width{0} {}

Map::Map(std::string configFile) : height{0}, width{0} {
    parseConfigFile(configFile);
}

std::ostream &operator<<(std::ostream &os, const Map &map) {
    os << "width: " << map.width << " height: " << map.height << "\n";
    for(int i = 0; i < map.width; i++) {
        for (int j = 0; j < map.height; j++)
            os << map.cells[i][j];
        os << '\n';
    }

    return os;
}
