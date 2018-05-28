#include <gtest/gtest.h>

#include "Map.hpp"

using namespace testing;

class MapTest : public Test
{
public:
    const size_t mapWidth = 3;
    const size_t mapHeight = 4;

    Map mapUnderTest { Map::VerticalPosition {mapHeight}, Map::HorizontalPosition {mapWidth} };
};

TEST_F(MapTest, CheckThatMapIsBuiltWithCorrectWidthAndHeightAndThatTilesAreDefault)
{
    for(size_t x = 0; x < mapHeight; ++x)
    {
        ASSERT_EQ(mapWidth, mapUnderTest[x].size());
        for(size_t y = 0; y < mapWidth; ++y)
        {
            EXPECT_TRUE(mapUnderTest[x][y].isPassable());
            EXPECT_FALSE(mapUnderTest[x][y].hasPoints());
        }
    }
}

TEST_F(MapTest, CheckThatMapCanBuldTileWall)
{
    EXPECT_TRUE(mapUnderTest[3][2].isPassable());
    ASSERT_TRUE(mapUnderTest.tryToBuildWall(Map::VerticalPosition {3}, Map::HorizontalPosition {2}));
    EXPECT_FALSE(mapUnderTest[3][2].isPassable());
}

//REFACTOR THIS TESTSUITE

TEST_F(MapTest, CheckThatMapCannotBuldWallWhenTileHasPoints)
{
    mapUnderTest[3][2].placePoints();
    EXPECT_TRUE(mapUnderTest[3][2].isPassable());
    ASSERT_TRUE(mapUnderTest.tryToBuildWall(Map::VerticalPosition {3}, Map::HorizontalPosition {2}));
    EXPECT_FALSE(mapUnderTest[3][2].isPassable());
}