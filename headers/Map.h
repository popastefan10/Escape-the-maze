//
// Created by popas on 14.03.2022.
//

#ifndef OOP_MAP_H
#define OOP_MAP_H

#include <vector>
#include <string>
#include <memory>
#include "Cell.h"
#include "WallCell.h"
#include "FloorCell.h"
#include "UndefinedCell.h"

class Map : public sf::Drawable {
    int width;
    int height;
    float cellWidth;
    float cellHeight;
    std::vector< std::vector<Cell> > cells;
    std::vector< std::vector< std::shared_ptr<Cell> > > cells_;

private:
    void parseConfigFile(const std::string &);

public:
    // constructors
    Map();
    [[maybe_unused]] explicit Map(const std::string &);   // config file
    [[maybe_unused]] Map(const Map &);

    // destructor
    ~Map();

    // operators
    Map & operator = (const Map &);
    friend std::ostream & operator << (std::ostream &, const Map &);
    const std::vector<Cell> & operator [] (int);

    // getters
    sf::Vector2f getCellSize() const;

    // draw derived din sf::Drawable
    virtual void draw(sf::RenderTarget &, sf::RenderStates) const;

    [[nodiscard]] bool isInside(const sf::Vector2i &) const;
    bool isEmpty(const sf::Vector2i &);
};


#endif //OOP_MAP_H
