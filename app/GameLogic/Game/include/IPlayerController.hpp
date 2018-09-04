#pragma once

class IPlayerController
{
public:
    virtual ~IPlayerController() = default;

    virtual void turnRight() = 0;
    virtual void turnLeft() = 0;
};