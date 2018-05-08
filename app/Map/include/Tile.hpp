#pragma once

class Tile
{
public:
    Tile();

    bool isPassable();
    bool hasPoints();

    void buildWall();
    void destroyWall();

    void placePoints();
    void takePoints();

private:
    bool _isPassable = true;
    bool _hasPoints = false;
};