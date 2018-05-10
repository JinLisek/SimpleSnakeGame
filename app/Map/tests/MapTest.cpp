#include <gtest/gtest.h>

#include "Map.hpp"

using namespace testing;

class MapTest : public Test
{

};

TEST_F(MapTest, ToBeContinued)
{
    Map map(Map::NumOfTiles{10}, Map::NumOfRows{10});
    const auto tileRow = map[0];

    EXPECT_EQ(10, tileRow.size());
}