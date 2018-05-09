#include <gtest/gtest.h>
#include <memory>

#include "TileRepresentationFactory.hpp"
#include "TileRepresentation.hpp"
#include "Tile.hpp"

#include "TileRepresentationTestHelper.hpp"

template <typename T, typename Y>
void checkEqualityOfTypesWithPointer(Y actual)
{
    EXPECT_EQ(typeid(T), typeid(*actual));
}


class TileRepresentationFactoryTest
    :   public ::testing::Test,
        public TileRepresentationTestHelper
{
public:
    void checkEqualityOfStrings(const std::string& expected, const std::string& actual)
    {
        EXPECT_STREQ(expected.c_str(), actual.c_str());
    }

    const TileRepresentationFactory tileRepresentationFactoryUnderTest {};
};

TEST_F(TileRepresentationFactoryTest, CheckThatFactoryCreatesEmptyRepresentationForDefaultTile)
{
    checkEqualityOfTypesWithPointer<EmptyTileRepresentation>(tileRepresentationFactoryUnderTest.createTileRepresentation(emptyTile));
}

TEST_F(TileRepresentationFactoryTest, CheckThatFactoryCreatesWalledTileRepresentationForTileWithWall)
{
    checkEqualityOfTypesWithPointer<WalledTileRepresentation>(tileRepresentationFactoryUnderTest.createTileRepresentation(walledTile));
}

TEST_F(TileRepresentationFactoryTest, CheckThatFactoryCreatesPointsTileRepresentationForTileWithPoints)
{
    checkEqualityOfTypesWithPointer<PointsTileRepresentation>(tileRepresentationFactoryUnderTest.createTileRepresentation(pointsTile));
}
