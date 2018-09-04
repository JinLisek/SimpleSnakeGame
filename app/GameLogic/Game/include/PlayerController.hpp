#pragma once

#include "IPlayerController.hpp"

class PlayerController : public IPlayerController
{
public:
    virtual ~PlayerController() override = default;

    virtual void turnRight() override {};
    virtual void turnLeft() override {};
};