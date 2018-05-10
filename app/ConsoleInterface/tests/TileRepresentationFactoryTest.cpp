#include <gtest/gtest.h>
#include <memory>

#include "TileRepresentationFactory.hpp"
#include "TileRepresentation.hpp"
#include "Tile.hpp"

#include "TileRepresentationTestHelper.hpp"

using namespace testing;

template <typename ExpectedType, typename ActualType>
void checkEqualityOfTypesWithPointer(ActualType actualObject)
{
    EXPECT_EQ(typeid(ExpectedType), typeid(*actualObject));
}


class TileRepresentationFactoryTest
    :   public Test,
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
