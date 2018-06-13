#include "Map.hpp"

Map::Map(const VerticalPosition& numOfRows, const HorizontalPosition& numOfTiles)
{
    for(size_t x = 0; x < numOfRows.get(); ++x)
    {
        _rows.push_back(std::vector<Tile>{});
        for(size_t y = 0; y < numOfTiles.get(); ++y)
        {
            _rows[x].push_back(Tile{});
        }
    }
}

bool Map::buildWallOnTile(const VerticalPosition& verticalPos, const HorizontalPosition& horizontalPos)
{
    Tile& updatedTile = getTileAt(verticalPos, horizontalPos);
    if(canPlaceThingsOnTile(updatedTile))
    {
        updatedTile.buildWall();
        return true;
    }
    
    return false;
}

bool Map::placePointsOnTile(const VerticalPosition& verticalPos, const HorizontalPosition& horizontalPos)
{
    Tile& updatedTile = getTileAt(verticalPos, horizontalPos);
    if(canPlaceThingsOnTile(updatedTile))
    {
        updatedTile.placePoints();
        return true;
    }
    
    return false;
}

bool Map::isTilePassable(const VerticalPosition& verticalPos, const HorizontalPosition& horizontalPos) const
{
    const Tile& tileAtPosition = getTileAt(verticalPos, horizontalPos);
    return tileAtPosition.isPassable();
}

bool Map::hasTilePoints(const VerticalPosition& verticalPos, const HorizontalPosition& horizontalPos) const
{
    const Tile& tileAtPosition = getTileAt(verticalPos, horizontalPos);
    return tileAtPosition.hasPoints();
}

bool Map::canPlaceThingsOnTile(const Tile& tileToCheck) const
{
    return not tileToCheck.hasPoints() and tileToCheck.isPassable();
}

Tile& Map::getTileAt(const VerticalPosition& verticalPos, const HorizontalPosition& horizontalPos)
{
    return _rows[verticalPos.get()][horizontalPos.get()];
}

const Tile& Map::getTileAt(const VerticalPosition& verticalPos, const HorizontalPosition& horizontalPos) const
{
    return _rows[verticalPos.get()][horizontalPos.get()];
}