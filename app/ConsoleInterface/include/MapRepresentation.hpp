#pragma once

#include "TileRepresentationFactory.hpp"

class Map;

class MapRepresentation
{
public:
    MapRepresentation(const Map& map);

    std::string draw() const;

private:
    const Map& _map;
    TileRepresentationFactory tileRepresentationFactory {};
};