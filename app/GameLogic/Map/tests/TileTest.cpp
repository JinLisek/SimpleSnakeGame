#include <gtest/gtest.h>

#include "Tile.hpp"

class TileTest : public ::testing::Test
{
public:
    Tile tileUnderTest;
};

TEST_F(TileTest, CheckThatFileIsPassableAndHasNoPointsByDefault)
{
    EXPECT_TRUE(tileUnderTest.isPassable());
    EXPECT_FALSE(tileUnderTest.hasPoints());
}

TEST_F(TileTest, CheckThatAfterBuildingWallItsUnpassableAndAfterDestroyingTheWallTileIsPassableAgain)
{
    tileUnderTest.buildWall();
    EXPECT_FALSE(tileUnderTest.isPassable());

    tileUnderTest.destroyWall();
    EXPECT_TRUE(tileUnderTest.isPassable());
}

TEST_F(TileTest, CheckThatAfterPlacingPointsTileHasPointsAndAfterTakingPointsTileNoLongerHasPoints)
{
    tileUnderTest.placePoints();
    EXPECT_TRUE(tileUnderTest.hasPoints());

    tileUnderTest.takePoints();
    EXPECT_FALSE(tileUnderTest.hasPoints());
}

TEST_F(TileTest, CheckThatPointsWontBePlacedWhenTileHasWall)
{
    tileUnderTest.buildWall();
    EXPECT_FALSE(tileUnderTest.hasPoints());

    EXPECT_THROW(tileUnderTest.placePoints(), WallAndPointsOnSameTileException);
    EXPECT_FALSE(tileUnderTest.hasPoints());
}

TEST_F(TileTest, CheckThatWallWontBePlacedWhenTileHaspoints)
{
    tileUnderTest.placePoints();
    EXPECT_TRUE(tileUnderTest.isPassable());

    EXPECT_THROW(tileUnderTest.buildWall(), WallAndPointsOnSameTileException);
    EXPECT_TRUE(tileUnderTest.isPassable());
}