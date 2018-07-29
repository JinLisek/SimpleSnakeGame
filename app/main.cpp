#include <iostream>
#include "TileRepresentation.hpp"
#include "TileRepresentationFactory.hpp"
#include "Map.hpp"
#include "MapRepresentation.hpp"

int main()
{
    unsigned mapRows = 20;
    unsigned mapColumns = 80;

    Map map(Map::VerticalPosition {mapRows}, Map::HorizontalPosition {mapColumns});
    MapRepresentation mapRepresentation {map};

    for(unsigned x = 6; x < 11; ++x)
    {
        for(unsigned y = 30; y < 40; ++y)
        {
            map.buildWallOnTile(Map::VerticalPosition {x}, Map::HorizontalPosition {y});
        }
    }

    std::cout << mapRepresentation.draw() << std::endl;

    return 0;
}
