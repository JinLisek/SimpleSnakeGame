#include "TileRepresentation.hpp"
#include "Tile.hpp"
#include "ConsoleColours.hpp"

std::string EmptyTileRepresentation::draw() const
{
    return greenText + std::string {"."};
}

std::string WalledTileRepresentation::draw() const
{
    return whiteText + std::string {"#"};
}

std::string PointsTileRepresentation::draw() const
{
    return yellowText + std::string {"$"};
}