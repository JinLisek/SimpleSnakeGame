#pragma once

class Tile
{
public:
    Tile();

    bool isPassable() const;
    bool hasPoints() const;

    void buildWall();
    void destroyWall();

    void placePoints();
    void takePoints();

private:
    bool _isPassable = true;
    bool _hasPoints = false;
};

class TileException
{
};

class WallAndPointsOnSameTileException : public TileException
{
};