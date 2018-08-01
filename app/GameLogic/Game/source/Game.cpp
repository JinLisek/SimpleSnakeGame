#include "Game.hpp"
#include "TxtMapReader.hpp"

GameState Game::gameState = GameState::Playing;

std::unique_ptr<Map> Game::getMap()
{
    TxtMapReader mapReader{};
    return mapReader.readMapFromFile("../Maps/DefaultMap.txt");
}