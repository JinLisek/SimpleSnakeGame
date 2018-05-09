#pragma once

#include <string>

class Tile;

class ITileRepresentation
{
public:
    virtual ~ITileRepresentation() = default;
    virtual std::string toString() const = 0;
};

class EmptyTileRepresentation : public ITileRepresentation
{
public:
    std::string toString() const override;
};

class WalledTileRepresentation : public ITileRepresentation
{
public:
    std::string toString() const override;
};

class PointsTileRepresentation : public ITileRepresentation
{
public:
    std::string toString() const override;
};