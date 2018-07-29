#include <gtest/gtest.h>

#include <memory>

#include "TileRepresentationFactory.hpp"
#include "TileRepresentation.hpp"
#include "Tile.hpp"

#include "TileRepresentationTestHelper.hpp"
#include "ConsoleColours.hpp"

using namespace testing;

class TileRepresentationTest
    :   public Test,
        public TileRepresentationTestHelper
{
public:
    const TileRepresentationFactory tileRepresentationFactory {};

    const std::string EMPTY_TILE_STRING = std::string{"."};
    const std::string WALLED_TILE_STRING = std::string{"#"};
    const std::string POINTS_TILE_STRING = std::string{"$"};
};

TEST_F(TileRepresentationTest, CheckThatEmptyTileIsPrintedAsGreenDot)
{
    const auto emptyTileRepresentation = tileRepresentationFactory.createTileRepresentation(emptyTile);

    checkEqualityOfStrings(greenText + EMPTY_TILE_STRING, emptyTileRepresentation->draw());
}

TEST_F(TileRepresentationTest, CheckThatTileWithWallIsPrintedAsWhiteHash)
{
    const auto walledTileRepresentation = tileRepresentationFactory.createTileRepresentation(walledTile);

    checkEqualityOfStrings(whiteText + WALLED_TILE_STRING, walledTileRepresentation->draw());
}

TEST_F(TileRepresentationTest, CheckThatTileWithPointsIsPrintedAsYellowDollar)
{
    const auto pointsTileRepresentation = tileRepresentationFactory.createTileRepresentation(pointsTile);

    checkEqualityOfStrings(yellowText + POINTS_TILE_STRING, pointsTileRepresentation->draw());
}