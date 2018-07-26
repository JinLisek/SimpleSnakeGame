#include <iostream>
#include "TileRepresentation.hpp"
#include "TileRepresentationFactory.hpp"
#include "Map.hpp"

int main()
{
    unsigned mapRows = 20;
    unsigned mapColumns = 80;

    TileRepresentationFactory representationFactory {};

    Map map(Map::VerticalPosition {mapRows}, Map::HorizontalPosition {mapColumns});

    for(size_t x = 0; x < mapRows; ++x)
    {
        for(size_t y = 0; y < mapColumns; ++y)
        {
            auto tileRepresentation = representationFactory.createTileRepresentation(map.getTileAt(Map::VerticalPosition {x}, Map::HorizontalPosition {y}));
            std::cout << tileRepresentation->toString();
        }

        std::cout << std::endl;
    }

    return 0;
}
