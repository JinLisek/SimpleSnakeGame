#pragma once

#include "PositionTypes.hpp"
#include "Point.hpp"

class Snake
{
public:
    Snake(const PosX& posX, const PosY& posY);
    Point getPosition() const;

private:
    Point _position;
};