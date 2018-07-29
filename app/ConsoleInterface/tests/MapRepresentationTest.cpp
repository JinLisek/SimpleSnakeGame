#include <gtest/gtest.h>

#include "MapRepresentation.hpp"
#include "Map.hpp"

#include "TileRepresentationTestHelper.hpp"
#include "ConsoleColours.hpp"

using namespace testing;

class MapRepresentationTest : 
    public Test,
    public TileRepresentationTestHelper
{
public:
    Map map {Map::VerticalPosition {MAP_HEIGHT}, Map::HorizontalPosition {MAP_WIDTH}};

    MapRepresentation objectUnderTest {map};

    static constexpr unsigned MAP_HEIGHT = 2;
    static constexpr unsigned MAP_WIDTH = 2;

    static constexpr unsigned TILE_HEIGHT = 1;
    static constexpr unsigned TILE_WIDTH = 1;

    const std::string EMPTY_TILE_REPRESENTATION {greenText + "."};
    const std::string WALL_TILE_REPRESENTATION {whiteText + "#"};
    const std::string POINTS_TILE_REPRESENTATION {yellowText + "$"};

    std::string mapArray[MAP_HEIGHT][MAP_WIDTH]
    {
        {EMPTY_TILE_REPRESENTATION, EMPTY_TILE_REPRESENTATION},
        {EMPTY_TILE_REPRESENTATION, EMPTY_TILE_REPRESENTATION}
    };

    std::string mapArrayToString(std::string mapArray[2][2])
    {
        std::string result {};

        for(size_t x = 0; x < MAP_HEIGHT; ++x)
        {
            for(size_t y = 0; y < MAP_WIDTH; ++y)
            {
                result += mapArray[x][y];
            }
            result += "\n";
        }

        return result;
    }
};

TEST_F(MapRepresentationTest, CheckThatMapRepresentationForDefaultMapGivesRepresentationWithOnlyGreenDots)
{
    checkEqualityOfStrings(mapArrayToString(mapArray), objectUnderTest.draw());
}

TEST_F(MapRepresentationTest, CheckThatMapRepresentationWithBuiltWallGivesRepresentationWithGreenDotsAndWhiteHash)
{
    map.buildWallOnTile(Map::VerticalPosition {TILE_HEIGHT}, Map::HorizontalPosition {TILE_WIDTH});    
    mapArray[TILE_HEIGHT][TILE_WIDTH] = WALL_TILE_REPRESENTATION;
    checkEqualityOfStrings(mapArrayToString(mapArray), objectUnderTest.draw());
}

TEST_F(MapRepresentationTest, CheckThatMapRepresentationWithPointsGivesRepresentationWithGreenDotsAndYellowDollar)
{
    map.placePointsOnTile(Map::VerticalPosition {TILE_HEIGHT}, Map::HorizontalPosition {TILE_WIDTH});    
    mapArray[TILE_HEIGHT][TILE_WIDTH] = POINTS_TILE_REPRESENTATION;
    checkEqualityOfStrings(mapArrayToString(mapArray), objectUnderTest.draw());
}
