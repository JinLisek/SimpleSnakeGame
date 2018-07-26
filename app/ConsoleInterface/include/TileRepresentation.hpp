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
    ~EmptyTileRepresentation() override = default;

    std::string toString() const override;
};

class WalledTileRepresentation : public ITileRepresentation
{
public:
    ~WalledTileRepresentation() override = default;

    std::string toString() const override;
};

class PointsTileRepresentation : public ITileRepresentation
{
public:
    ~PointsTileRepresentation() override = default;

    std::string toString() const override;
};