#include "Tile.hpp"

Tile::Tile(){}

bool Tile::isPassable()
{
    return _isPassable;
}

bool Tile::hasPoints()
{
    return _hasPoints;
}

void Tile::buildWall()
{
    _isPassable = false;
}

void Tile::destroyWall()
{
    _isPassable = true;
}

void Tile::placePoints()
{
    if(not isPassable())
        throw PlacingPointsOnWallTileException{};
    _hasPoints = true;
}

void Tile::takePoints()
{
    _hasPoints = false;
}