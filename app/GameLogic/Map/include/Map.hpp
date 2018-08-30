#pragma once

#include <vector>
#include "Tile.hpp"
#include "PositionTypes.hpp"

class Map
{
public:
    using RowOfTiles = std::vector<Tile>;

    Map(const PosX& numOfColumns, const PosY& numOfTiles);

    bool buildWallOnTile(const PosX& horizontalPos, const PosY& verticalPos);
    bool placePointsOnTile(const PosX& horizontalPos, const PosY& verticalPos);

    bool isTilePassable(const PosX& horizontalPos, const PosY& verticalPos) const;
    bool hasTilePoints(const PosX& horizontalPos, const PosY& verticalPos) const;

    Tile& getTileAt(const PosX& horizontalPos, const PosY& verticalPos);
    const Tile& getTileAt(const PosX& horizontalPos, const PosY& verticalPos) const;

    unsigned getNumOfRows() const { return _numOfRows.get(); }
    unsigned getNumOfColumns() const { return _numOfColumns.get(); }

private:
    bool canPlaceThingsOnTile(const Tile& tileToCheck) const;

    std::vector<RowOfTiles> _rows {};

    PosX _numOfColumns;   
    PosY _numOfRows; 
};