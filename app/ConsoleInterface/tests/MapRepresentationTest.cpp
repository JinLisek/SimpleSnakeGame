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
    Map map {PosX {MAP_WIDTH}, PosY {MAP_HEIGHT}};

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

        for(unsigned x = 0; x < MAP_HEIGHT; ++x)
        {
            for(unsigned y = 0; y < MAP_WIDTH; ++y)
            {
                result += mapArray[x][y];
            }
            result += "\n";
        }

        return result;
    }
};

constexpr unsigned MapRepresentationTest::TILE_HEIGHT;
constexpr unsigned MapRepresentationTest::TILE_WIDTH;
constexpr unsigned MapRepresentationTest::MAP_HEIGHT;
constexpr unsigned MapRepresentationTest::MAP_WIDTH;

TEST_F(MapRepresentationTest, CheckThatMapRepresentationForDefaultMapGivesRepresentationWithOnlyGreenDots)
{
    checkEqualityOfStrings(mapArrayToString(mapArray), objectUnderTest.draw());
}

TEST_F(MapRepresentationTest, CheckThatMapRepresentationWithBuiltWallGivesRepresentationWithGreenDotsAndWhiteHash)
{
    map.buildWallOnTile(PosX {TILE_WIDTH}, PosY {TILE_HEIGHT});    
    mapArray[TILE_HEIGHT][TILE_WIDTH] = WALL_TILE_REPRESENTATION;
    checkEqualityOfStrings(mapArrayToString(mapArray), objectUnderTest.draw());
}

TEST_F(MapRepresentationTest, CheckThatMapRepresentationWithPointsGivesRepresentationWithGreenDotsAndYellowDollar)
{
    map.placePointsOnTile(PosX {TILE_WIDTH}, PosY {TILE_HEIGHT});    
    mapArray[TILE_HEIGHT][TILE_WIDTH] = POINTS_TILE_REPRESENTATION;
    checkEqualityOfStrings(mapArrayToString(mapArray), objectUnderTest.draw());
}
