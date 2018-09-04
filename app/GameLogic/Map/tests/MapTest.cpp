#include <gtest/gtest.h>

#include "Map.hpp"

using namespace testing;

class MapTest : public Test
{
public:
    const unsigned MAP_WIDTH = 3;
    const unsigned MAP_HEIGHT = 4;

    const PosY TILE_VERTICAL_POS {3};
    const PosX TILE_HORIZONTAL_POS {2};

    Map mapUnderTest { PosX {MAP_WIDTH}, PosY {MAP_HEIGHT} };
};


TEST_F(MapTest, CheckThatMapIsBuiltWithCorrectWidthAndHeightAndThatTilesArePassableWithoutPoints)
{
    for(unsigned x = 0; x < MAP_HEIGHT; ++x)
    {
        for(unsigned y = 0; y < MAP_WIDTH; ++y)
        {
            EXPECT_TRUE(mapUnderTest.isTilePassable(PosX {y}, PosY {x}));
            EXPECT_FALSE(mapUnderTest.hasTilePoints(PosX {y}, PosY {x}));
        }
    }
}


TEST_F(MapTest, CheckThatAfterBuildingWallTileOnMapIsUnpassable)
{
    EXPECT_TRUE(mapUnderTest.isTilePassable(TILE_HORIZONTAL_POS, TILE_VERTICAL_POS));
    ASSERT_TRUE(mapUnderTest.buildWallOnTile(TILE_HORIZONTAL_POS, TILE_VERTICAL_POS));
    EXPECT_FALSE(mapUnderTest.isTilePassable(TILE_HORIZONTAL_POS, TILE_VERTICAL_POS));
}

TEST_F(MapTest, CheckThatAfterPlacingPointsTileOnMapHasPoints)
{
    EXPECT_FALSE(mapUnderTest.hasTilePoints(TILE_HORIZONTAL_POS, TILE_VERTICAL_POS));
    ASSERT_TRUE(mapUnderTest.placePointsOnTile(TILE_HORIZONTAL_POS, TILE_VERTICAL_POS));
    EXPECT_TRUE(mapUnderTest.hasTilePoints(TILE_HORIZONTAL_POS, TILE_VERTICAL_POS));
}


TEST_F(MapTest, CheckThatMapCannotBuldWallWhenTileHasPoints)
{
    mapUnderTest.placePointsOnTile(TILE_HORIZONTAL_POS, TILE_VERTICAL_POS);
    ASSERT_FALSE(mapUnderTest.buildWallOnTile(TILE_HORIZONTAL_POS, TILE_VERTICAL_POS));
}

TEST_F(MapTest, CheckThatMapCannotBuldWallWhenTileHasWall)
{
    mapUnderTest.buildWallOnTile(TILE_HORIZONTAL_POS, TILE_VERTICAL_POS);
    ASSERT_FALSE(mapUnderTest.buildWallOnTile(TILE_HORIZONTAL_POS, TILE_VERTICAL_POS));
}

TEST_F(MapTest, CheckThatMapCannotPlacePointsWhenTileHasWall)
{
    mapUnderTest.buildWallOnTile(TILE_HORIZONTAL_POS, TILE_VERTICAL_POS);
    ASSERT_FALSE(mapUnderTest.placePointsOnTile(TILE_HORIZONTAL_POS, TILE_VERTICAL_POS));
}

TEST_F(MapTest, CheckThatMapCannotPlacePointsWhenTileHasPoints)
{
    mapUnderTest.placePointsOnTile(TILE_HORIZONTAL_POS, TILE_VERTICAL_POS);
    ASSERT_FALSE(mapUnderTest.placePointsOnTile(TILE_HORIZONTAL_POS, TILE_VERTICAL_POS));
}

TEST_F(MapTest, CheckThatMapGetTileGivesExpectedTile)
{
    mapUnderTest.placePointsOnTile(TILE_HORIZONTAL_POS, TILE_VERTICAL_POS);
    Tile tile = mapUnderTest.getTileAt(TILE_HORIZONTAL_POS, TILE_VERTICAL_POS);
    ASSERT_TRUE(tile.hasPoints());
}