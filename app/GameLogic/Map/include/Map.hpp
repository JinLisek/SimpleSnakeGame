#pragma once

#include <vector>
#include "Tile.hpp"
#include "StrongType.hpp"

class Map
{
public:
    using VerticalPosition = StrongType<size_t, struct NumOfTilesParameter>;
    using HorizontalPosition = StrongType<size_t, struct NumOfRowsParameter>;
    using RowOfTiles = std::vector<Tile>;

    Map(const VerticalPosition& numOfRows, const HorizontalPosition& numOfTiles);

    bool buildWallOnTile(const VerticalPosition& verticalPos, const HorizontalPosition& horizontalPos);
    bool placePointsOnTile(const VerticalPosition& verticalPos, const HorizontalPosition& horizontalPos);

    bool isTilePassable(const VerticalPosition& verticalPos, const HorizontalPosition& horizontalPos) const;
    bool hasTilePoints(const VerticalPosition& verticalPos, const HorizontalPosition& horizontalPos) const;

    Tile& getTileAt(const VerticalPosition& verticalPos, const HorizontalPosition& horizontalPos);
    const Tile& getTileAt(const VerticalPosition& verticalPos, const HorizontalPosition& horizontalPos) const;

    unsigned getNumOfRows() const { return _numOfRows; }
    unsigned getNumOfColumns() const { return _numOfColumns; }

private:
    bool canPlaceThingsOnTile(const Tile& tileToCheck) const;

    std::vector<RowOfTiles> _rows {};
    unsigned _numOfRows;
    unsigned _numOfColumns;    
};