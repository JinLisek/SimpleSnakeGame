#include <gtest/gtest.h>

#include "Map.hpp"

using namespace testing;

class MapTest : public Test
{
public:
    const size_t mapWidth = 3;
    const size_t mapHeight = 3;
};

TEST_F(MapTest, CheckThatMapSizeIsCorrectGivenParameters)
{
    Map map(Map::NumOfTiles{mapWidth}, Map::NumOfRows{mapHeight});

    for(size_t x = 0; x < mapWidth; ++x)
    {
        EXPECT_EQ(mapWidth, map[x].size());
    }
}