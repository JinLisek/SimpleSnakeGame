#pragma once

#include "Tile.hpp"

class TileRepresentationTestHelper
{
public:
    const Tile emptyTile = createDefaultTile();
    const Tile walledTile = createWalledTile();
    const Tile pointsTile = createPointsTile();

    void checkEqualityOfStrings(const std::string& expected, const std::string& actual)
    {
        EXPECT_STREQ(expected.c_str(), actual.c_str());
    }

private:
    Tile createDefaultTile()
    {
        return Tile {};
    }

    Tile createWalledTile()
    {
        Tile tile;
        tile.buildWall();

        return tile;
    }

    Tile createPointsTile()
    {
        Tile tile;
        tile.placePoints();

        return tile;
    }
};

