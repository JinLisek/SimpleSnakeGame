#include "TileRepresentation.hpp"
#include "Tile.hpp"

std::string EmptyTileRepresentation::toString() const
{
    return std::string {"."};
}

std::string WalledTileRepresentation::toString() const
{
    return std::string {"#"};
}

std::string PointsTileRepresentation::toString() const
{
    return std::string {"$"};
}