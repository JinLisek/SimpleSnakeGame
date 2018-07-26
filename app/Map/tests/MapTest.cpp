#include <gtest/gtest.h>

#include "Map.hpp"

using namespace testing;

class MapTest : public Test
{
public:
    const size_t MAP_WIDTH = 3;
    const size_t MAP_HEIGHT = 4;

    const Map::VerticalPosition TILE_VERTICAL_POS {3};
    const Map::HorizontalPosition TILE_HORIZONTAL_POS {2};

    Map mapUnderTest { Map::VerticalPosition {MAP_HEIGHT}, Map::HorizontalPosition {MAP_WIDTH} };
};


TEST_F(MapTest, CheckThatMapIsBuiltWithCorrectWidthAndHeightAndThatTilesArePassableWithoutPoints)
{
    for(size_t x = 0; x < MAP_HEIGHT; ++x)
    {
        for(size_t y = 0; y < MAP_WIDTH; ++y)
        {
            EXPECT_TRUE(mapUnderTest.isTilePassable(Map::VerticalPosition {x}, Map::HorizontalPosition {y}));
            EXPECT_FALSE(mapUnderTest.hasTilePoints(Map::VerticalPosition {x}, Map::HorizontalPosition {y}));
        }
    }
}


TEST_F(MapTest, CheckThatAfterBuildingWallTileOnMapIsUnpassable)
{
    EXPECT_TRUE(mapUnderTest.isTilePassable(TILE_VERTICAL_POS, TILE_HORIZONTAL_POS));
    ASSERT_TRUE(mapUnderTest.buildWallOnTile(TILE_VERTICAL_POS, TILE_HORIZONTAL_POS));
    EXPECT_FALSE(mapUnderTest.isTilePassable(TILE_VERTICAL_POS, TILE_HORIZONTAL_POS));
}

TEST_F(MapTest, CheckThatAfterPlacingPointsTileOnMapHasPoints)
{
    EXPECT_FALSE(mapUnderTest.hasTilePoints(TILE_VERTICAL_POS, TILE_HORIZONTAL_POS));
    ASSERT_TRUE(mapUnderTest.placePointsOnTile(TILE_VERTICAL_POS, TILE_HORIZONTAL_POS));
    EXPECT_TRUE(mapUnderTest.hasTilePoints(TILE_VERTICAL_POS, TILE_HORIZONTAL_POS));
}


TEST_F(MapTest, CheckThatMapCannotBuldWallWhenTileHasPoints)
{
    mapUnderTest.placePointsOnTile(TILE_VERTICAL_POS, TILE_HORIZONTAL_POS);
    ASSERT_FALSE(mapUnderTest.buildWallOnTile(TILE_VERTICAL_POS, TILE_HORIZONTAL_POS));
}

TEST_F(MapTest, CheckThatMapCannotBuldWallWhenTileHasWall)
{
    mapUnderTest.buildWallOnTile(TILE_VERTICAL_POS, TILE_HORIZONTAL_POS);
    ASSERT_FALSE(mapUnderTest.buildWallOnTile(TILE_VERTICAL_POS, TILE_HORIZONTAL_POS));
}

TEST_F(MapTest, CheckThatMapCannotPlacePointsWhenTileHasWall)
{
    mapUnderTest.buildWallOnTile(TILE_VERTICAL_POS, TILE_HORIZONTAL_POS);
    ASSERT_FALSE(mapUnderTest.placePointsOnTile(TILE_VERTICAL_POS, TILE_HORIZONTAL_POS));
}

TEST_F(MapTest, CheckThatMapCannotPlacePointsWhenTileHasPoints)
{
    mapUnderTest.placePointsOnTile(TILE_VERTICAL_POS, TILE_HORIZONTAL_POS);
    ASSERT_FALSE(mapUnderTest.placePointsOnTile(TILE_VERTICAL_POS, TILE_HORIZONTAL_POS));
}

TEST_F(MapTest, CheckThatMapGetTileGivesExpectedTile)
{
    mapUnderTest.placePointsOnTile(TILE_VERTICAL_POS, TILE_HORIZONTAL_POS);
    Tile tile = mapUnderTest.getTileAt(TILE_VERTICAL_POS, TILE_HORIZONTAL_POS);
    ASSERT_TRUE(tile.hasPoints());
}