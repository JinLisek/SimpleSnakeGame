#include <gtest/gtest.h>

#include "Tile.hpp"

TEST(TileTest, checkThatTileExists)
{
    Tile tile(0);
    ASSERT_TRUE(tile.isEmpty());
}