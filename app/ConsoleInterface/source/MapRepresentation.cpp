#include <string>
#include "Map.hpp"
#include "MapRepresentation.hpp"
#include "TileRepresentation.hpp"
#include "ConsoleColours.hpp"

MapRepresentation::MapRepresentation(const Map& map) :
    _map {map}
{
}

std::string MapRepresentation::draw() const
{
    std::string representation {};

    for(size_t x = 0; x < _map.getNumOfRows(); ++x)
    {
        for(size_t y = 0; y < _map.getNumOfColumns(); ++y)
        {
            const auto tile = _map.getTileAt(Map::VerticalPosition {x}, Map::HorizontalPosition {y});
            const auto& tileRepresentation = tileRepresentationFactory.createTileRepresentation(tile);
            representation += tileRepresentation->draw();
        }

        representation += "\n";
    }

    return representation;
};