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
#include "SpecialCells.h"

class Map : public sf::Drawable {
    int width;
    int height;
    float cellWidth;
    float cellHeight;
    std::vector< std::vector< std::shared_ptr<Cell> > > cells;

private:
    void parseConfigFile(const std::string &);

public:
    // constructors
    Map();
    explicit Map(const std::string &);   // config file
    [[maybe_unused]] Map(const Map &);

    // destructor
    ~Map() override;

    // operators
    friend void swap(Map &, Map &);
    Map & operator = (const Map &);
    friend std::ostream & operator << (std::ostream &, const Map &);
    const std::vector< std::shared_ptr< Cell > > & operator [] (int);

    // getters / setters
    [[nodiscard]] sf::Vector2f getCellSize() const;
    [[nodiscard]] sf::Vector2f getMapSize() const;

    sf::Vector2f getCellCoords(int, int) const;
    void setStartPosition(sf::Vector2u);
    void setEndPosition(sf::Vector2u);

    // draw derived din sf::Drawable
    void draw(sf::RenderTarget &, sf::RenderStates) const override;

    [[nodiscard]] bool isInside(const sf::Vector2i &) const;
    bool canWalkOn(const sf::Vector2i &);
};


#endif //OOP_MAP_H
