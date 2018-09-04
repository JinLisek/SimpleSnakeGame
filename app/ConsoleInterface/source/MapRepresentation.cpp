#include <string>
#include "Map.hpp"
#include "MapRepresentation.hpp"
#include "TileRepresentation.hpp"
#include "ConsoleColours.hpp"
#include "PositionTypes.hpp"

MapRepresentation::MapRepresentation(const Map& map) :
    _map {map}
{
}

std::string MapRepresentation::draw() const
{
    std::string representation {};

    for(unsigned x = 0; x < _map.getNumOfRows(); ++x)
    {
        for(unsigned y = 0; y < _map.getNumOfColumns(); ++y)
        {
            const auto tile = _map.getTileAt(PosX {y}, PosY {x});
            const auto& tileRepresentation = tileRepresentationFactory.createTileRepresentation(tile);
            representation += tileRepresentation->draw();
        }

        representation += "\n";
    }

    return representation;
};