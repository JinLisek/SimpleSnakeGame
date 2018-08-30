#include "Game.hpp"
#include "TxtMapReader.hpp"

GameState Game::gameState = GameState::Playing;

std::unique_ptr<Map> Game::getMap()
{
    TxtMapReader mapReader{"../Maps/DefaultMap.txt"};
    return mapReader.readMap();
}