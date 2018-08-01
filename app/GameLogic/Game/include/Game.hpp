#pragma once

#include <memory>
#include "Map.hpp"

enum class GameState { Playing, Quit };

class Game
{
public:
    std::unique_ptr<Map> getMap();

    static GameState gameState;
};