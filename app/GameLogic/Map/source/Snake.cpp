#include <utility>
#include "Snake.hpp"

Snake::Snake(const PosX& posX, const PosY& posY) :
    _position {posX.get(), posY.get()}
{
}

Point Snake::getPosition() const
{
    return _position;
}