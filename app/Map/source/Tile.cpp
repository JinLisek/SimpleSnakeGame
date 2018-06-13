#include "Tile.hpp"

Tile::Tile(){}

bool Tile::isPassable() const
{
    return _isPassable;
}

bool Tile::hasPoints() const
{
    return _hasPoints;
}

void Tile::buildWall()
{
    if(hasPoints())
        throw WallAndPointsOnSameTileException {};
    _isPassable = false;
}

void Tile::destroyWall()
{
    _isPassable = true;
}

void Tile::placePoints()
{
    if(not isPassable())
        throw WallAndPointsOnSameTileException {};

    _hasPoints = true;
}

void Tile::takePoints()
{
    _hasPoints = false;
}