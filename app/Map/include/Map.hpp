#pragma once

#include "Tile.hpp"
#include "StrongType.hpp"

class Map
{
public:
    using NumOfTiles = StrongType<size_t, struct NumOfTilesParameter>;
    using NumOfRows = StrongType<size_t, struct NumOfRowsParameter>;
    using RowOfTiles = std::vector<Tile>;

    Map(NumOfTiles numOfTiles, NumOfRows numOfRows)
    {
        for(size_t i = 0; i < numOfRows.get(); ++i)
        {
            _rows.push_back(std::vector<Tile>{});
            for(size_t j = 0; j < numOfTiles.get(); ++j)
            {
                _rows[i].push_back(Tile{});
            }
        }
    }

    RowOfTiles& operator[](size_t rowIndex)
    {
        return _rows[rowIndex];
    }
private:
    std::vector<RowOfTiles> _rows {};
};