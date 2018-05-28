#pragma once

#include "Tile.hpp"
#include "StrongType.hpp"

class Map
{
public:
    using VerticalPosition = StrongType<size_t, struct NumOfTilesParameter>;
    using HorizontalPosition = StrongType<size_t, struct NumOfRowsParameter>;
    using RowOfTiles = std::vector<Tile>;

    Map(const HorizontalPosition& numOfTiles, const VerticalPosition& numOfRows)
    {
        for(size_t x = 0; x < numOfRows.get(); ++x)
        {
            _rows.push_back(std::vector<Tile>{});
            for(size_t y = 0; y < numOfTiles.get(); ++y)
            {
                _rows[x].push_back(Tile{});
            }
        }
    }

    bool tryToBuildWall(const HorizontalPosition& numOfTiles, const VerticalPosition& numOfRows)
    {
    }

    RowOfTiles& operator[](size_t rowIndex)
    {
        return _rows[rowIndex];
    }
private:
    std::vector<RowOfTiles> _rows {};
};