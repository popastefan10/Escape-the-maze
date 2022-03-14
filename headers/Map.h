//
// Created by popas on 14.03.2022.
//

#ifndef OOP_MAP_H
#define OOP_MAP_H

#include <vector>
#include <string>
#include "Cell.h"

class Map {

private:
    int height;
    int width;
    std::vector< std::vector<Cell> > cells;

    void parseConfigFile(const std::string &);

public:
    Map();
    Map(std::string);   // Primeste fisier de config

    friend std::ostream & operator << (std::ostream &, const Map &);
};


#endif //OOP_MAP_H
