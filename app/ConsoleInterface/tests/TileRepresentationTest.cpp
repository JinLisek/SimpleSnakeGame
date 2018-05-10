#include <gtest/gtest.h>

#include <memory>

#include "TileRepresentationFactory.hpp"
#include "TileRepresentation.hpp"
#include "Tile.hpp"

#include "TileRepresentationTestHelper.hpp"

using namespace testing;

void checkEqualityOfStrings(const std::string& expected, const std::string& actual)
{
    EXPECT_STREQ(expected.c_str(), actual.c_str());
}


class TileRepresentationTest
    :   public Test,
        public TileRepresentationTestHelper
{
public:
    const TileRepresentationFactory tileRepresentationFactory {};

    const std::string EMPTY_TILE_STRING = std::string{" "};
    const std::string WALLED_TILE_STRING = std::string{"#"};
    const std::string POINTS_TILE_STRING = std::string{"."};
};

TEST_F(TileRepresentationTest, CheckThatDefaultTileIsPrintedAsEmpty)
{
    const auto emptyTileRepresentation = tileRepresentationFactory.createTileRepresentation(emptyTile);

    checkEqualityOfStrings(EMPTY_TILE_STRING, emptyTileRepresentation->toString());
}

TEST_F(TileRepresentationTest, CheckThatTileWithWallIsPrintedAsHash)
{
    const auto walledTileRepresentation = tileRepresentationFactory.createTileRepresentation(walledTile);

    checkEqualityOfStrings(WALLED_TILE_STRING, walledTileRepresentation->toString());
}

TEST_F(TileRepresentationTest, CheckThatTileWithPointsIsPrintedAsDot)
{
    const auto pointsTileRepresentation = tileRepresentationFactory.createTileRepresentation(pointsTile);

    checkEqualityOfStrings(POINTS_TILE_STRING, pointsTileRepresentation->toString());
}