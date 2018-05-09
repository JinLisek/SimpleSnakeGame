#include <gtest/gtest.h>

#include "Tile.hpp"

class TileTest : public ::testing::Test
{
public:
    Tile tileObjectUnderTest;
};

TEST_F(TileTest, CheckThatFileIsPassableAndHasNoPointsByDefault)
{
    EXPECT_TRUE(tileObjectUnderTest.isPassable());
    EXPECT_FALSE(tileObjectUnderTest.hasPoints());
}

TEST_F(TileTest, CheckThatAfterBuildingWallItsUnpassableAndAfterDestroyingTheWallTileIsPassableAgain)
{
    tileObjectUnderTest.buildWall();
    EXPECT_FALSE(tileObjectUnderTest.isPassable());

    tileObjectUnderTest.destroyWall();
    EXPECT_TRUE(tileObjectUnderTest.isPassable());
}

TEST_F(TileTest, CheckThatAfterPlacingPointsTileHasPointsAndAfterTakingPointsTileNoLongerHasPoints)
{
    tileObjectUnderTest.placePoints();
    EXPECT_TRUE(tileObjectUnderTest.hasPoints());

    tileObjectUnderTest.takePoints();
    EXPECT_FALSE(tileObjectUnderTest.hasPoints());
}

TEST_F(TileTest, CheckThatPointsWontBePlacedWhenTileHasWall)
{
    tileObjectUnderTest.buildWall();
    EXPECT_FALSE(tileObjectUnderTest.hasPoints());

    EXPECT_THROW(tileObjectUnderTest.placePoints(), WallAndPointsOnSameTileException);
    EXPECT_FALSE(tileObjectUnderTest.hasPoints());
}

TEST_F(TileTest, CheckThatWallWontBePlacedWhenTileHaspoints)
{
    tileObjectUnderTest.placePoints();
    EXPECT_TRUE(tileObjectUnderTest.isPassable());

    EXPECT_THROW(tileObjectUnderTest.buildWall(), WallAndPointsOnSameTileException);
    EXPECT_TRUE(tileObjectUnderTest.isPassable());
}