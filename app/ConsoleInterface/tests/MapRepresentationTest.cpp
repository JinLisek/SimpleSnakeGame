#include <gtest/gtest.h>

#include "MapRepresentation.hpp"
#include "Map.hpp"

#include "TileRepresentationTestHelper.hpp"

using namespace testing;

class MapRepresentationTest : 
    public Test,
    public TileRepresentationTestHelper
{
public:
    Map map {Map::VerticalPosition {MAP_HEIGHT}, Map::HorizontalPosition {MAP_WIDTH}};

    MapRepresentation objectUnderTest {map};

    static constexpr unsigned MAP_HEIGHT = 3;
    static constexpr unsigned MAP_WIDTH = 3;

    static constexpr unsigned TILE_HEIGHT = 1;
    static constexpr unsigned TILE_WEIGHT = 1;

    std::string defaultMapRepresentation{"...\n...\n...\n"};
};

TEST_F(MapRepresentationTest, CheckThatMapRepresentationForDefaultMapGivesDefaultRepresentationWithDots)
{
    checkEqualityOfStrings(defaultMapRepresentation, objectUnderTest.draw());
}

TEST_F(MapRepresentationTest, CheckThatMapRepresentationWithBuiltWallsGivesRepresentationWithHashes)
{
    map.buildWallOnTile(Map::VerticalPosition {TILE_HEIGHT}, Map::HorizontalPosition {TILE_WEIGHT});    
    checkEqualityOfStrings("...\n.#.\n...\n", objectUnderTest.draw()); // TODO: Extract to function modyfing defaultMapRepresentation
}
