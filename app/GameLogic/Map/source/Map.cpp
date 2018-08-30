#include "Map.hpp"

Map::Map(const PosX& numOfColumns, const PosY& numOfRows) :
    _numOfColumns{numOfColumns},
    _numOfRows{numOfRows}
{
    for(size_t x = 0; x < _numOfRows.get(); ++x)
    {
        _rows.push_back(std::vector<Tile>{});
        for(size_t y = 0; y < _numOfColumns.get(); ++y)
        {
            _rows[x].push_back(Tile{});
        }
    }
}

bool Map::buildWallOnTile(const PosX& horizontalPos, const PosY& verticalPos)
{
    Tile& updatedTile = getTileAt(horizontalPos, verticalPos);
    if(canPlaceThingsOnTile(updatedTile))
    {
        updatedTile.buildWall();
        return true;
    }
    
    return false;
}

bool Map::placePointsOnTile(const PosX& horizontalPos, const PosY& verticalPos)
{
    Tile& updatedTile = getTileAt(horizontalPos, verticalPos);
    if(canPlaceThingsOnTile(updatedTile))
    {
        updatedTile.placePoints();
        return true;
    }
    
    return false;
}

bool Map::isTilePassable(const PosX& horizontalPos, const PosY& verticalPos) const
{
    const Tile& tileAtPosition = getTileAt(horizontalPos, verticalPos);
    return tileAtPosition.isPassable();
}

bool Map::hasTilePoints(const PosX& horizontalPos, const PosY& verticalPos) const
{
    const Tile& tileAtPosition = getTileAt(horizontalPos, verticalPos);
    return tileAtPosition.hasPoints();
}

bool Map::canPlaceThingsOnTile(const Tile& tileToCheck) const
{
    return not tileToCheck.hasPoints() and tileToCheck.isPassable();
}

Tile& Map::getTileAt(const PosX& horizontalPos, const PosY& verticalPos)
{
    return _rows[verticalPos.get()][horizontalPos.get()];
}

const Tile& Map::getTileAt(const PosX& horizontalPos, const PosY& verticalPos) const
{
    return _rows[verticalPos.get()][horizontalPos.get()];
}