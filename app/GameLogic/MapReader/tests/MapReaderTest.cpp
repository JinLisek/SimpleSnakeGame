#include <gtest/gtest.h>

#include "TxtMapReader.hpp"
#include "Map.hpp"

using namespace testing;

class MapReaderTest : public Test
{
public:

    static constexpr size_t MAP_HEIGHT = 3;
    static constexpr size_t MAP_WIDTH = 3;

    static constexpr size_t CENTER_TILE_VERTICAL_POS = 1;
    static constexpr size_t CENTER_TILE_HORIZONTAL_POS = 1;

    Tile tiles[MAP_HEIGHT][MAP_WIDTH]
    {
        {{}, {}, {}},
        {{}, {}, {}},
        {{}, {}, {}}
    };

    void checkTilesInGeneratedMap(const Map& map, const Tile tiles[MAP_HEIGHT][MAP_WIDTH])
    {
        for(unsigned x = 0; x < MAP_HEIGHT; ++x)
        {
            for(unsigned y = 0; y < MAP_WIDTH; ++y)
            {
                EXPECT_EQ(tiles[x][y].isPassable(), map.isTilePassable(PosX{y}, PosY{x}));
                EXPECT_EQ(tiles[x][y].hasPoints(), map.hasTilePoints(PosX{y}, PosY{x}));
            }
        }
    }

    void checkMapSize(const Map& map)
    {
        EXPECT_EQ(MAP_HEIGHT, map.getNumOfRows());
        EXPECT_EQ(MAP_WIDTH, map.getNumOfColumns());
    }
};

constexpr size_t MapReaderTest::MAP_HEIGHT;
constexpr size_t MapReaderTest::MAP_WIDTH;

TEST_F(MapReaderTest, CheckThatMapReaderReadsEmptyMap)
{
    TxtMapReader reader{"test_input/Empty3x3Map.txt"};
    auto map = reader.readMap();

    checkMapSize(*map);
    checkTilesInGeneratedMap(*map, tiles);
}

TEST_F(MapReaderTest, CheckThatMapReaderReadsMapWithWall)
{
    TxtMapReader reader{"test_input/3x3MapWithWallInTheCenter.txt"};
    auto map = reader.readMap();

    tiles[CENTER_TILE_VERTICAL_POS][CENTER_TILE_HORIZONTAL_POS].buildWall();

    checkMapSize(*map);
    checkTilesInGeneratedMap(*map, tiles);
}

TEST_F(MapReaderTest, CheckThatMapReaderReadsMapWithPoints)
{
    TxtMapReader reader{"test_input/3x3MapWithPointsInTheCenter.txt"};
    auto map = reader.readMap();

    tiles[CENTER_TILE_VERTICAL_POS][CENTER_TILE_HORIZONTAL_POS].placePoints();

    checkMapSize(*map);
    checkTilesInGeneratedMap(*map, tiles);
}

TEST_F(MapReaderTest, CheckThatMapReaderReadsMapWithSnake)
{
    TxtMapReader reader{"test_input/3x3MapWithSnakeInTheCenter.txt"};
    auto snake =  reader.readSnake();

    EXPECT_EQ(1, snake->getPosition().x);
    EXPECT_EQ(1, snake->getPosition().y);
}

TEST_F(MapReaderTest, CheckThatMapReaderReadsBiggerEmptyMap)
{
    TxtMapReader reader{"test_input/Empty100x10Map.txt"};
    auto map = reader.readMap();

    EXPECT_EQ(10, map->getNumOfRows());
    EXPECT_EQ(100, map->getNumOfColumns());
}