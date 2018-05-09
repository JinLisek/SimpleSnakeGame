#pragma once

#include <memory>

class Tile;
class ITileRepresentation;

class TileRepresentationFactory
{
public:
    std::unique_ptr<ITileRepresentation> createTileRepresentation(Tile tileToRepresent) const;
};