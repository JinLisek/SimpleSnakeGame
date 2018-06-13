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

private:
    std::vector<RowOfTiles> _rows {};

    bool canPlaceThingsOnTile(const Tile& tileToCheck) const;

    Tile& getTileAt(const VerticalPosition& verticalPos, const HorizontalPosition& horizontalPos);
    const Tile& getTileAt(const VerticalPosition& verticalPos, const HorizontalPosition& horizontalPos) const;
};