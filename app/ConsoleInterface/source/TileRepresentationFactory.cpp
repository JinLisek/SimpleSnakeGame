#include "TileRepresentationFactory.hpp"
#include "TileRepresentation.hpp"
#include "Tile.hpp"

std::unique_ptr<ITileRepresentation> TileRepresentationFactory::createTileRepresentation(Tile tileToRepresent) const
{
    if(not tileToRepresent.isPassable())
        return std::make_unique<WalledTileRepresentation>();

    if(tileToRepresent.hasPoints())
        return std::make_unique<PointsTileRepresentation>();

    return std::make_unique<EmptyTileRepresentation>();
}