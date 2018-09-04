#include "InputAdapter.hpp"
#include "SFML/Window/Keyboard.hpp"
#include "Game.hpp"

namespace
{

void userInputLoop(const InputAdapter& inputAdapter)
{
    while(Game::gameState != GameState::Quit)
    {
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
        {
            Game::gameState = GameState::Quit;
            break;
        }
    }
}

}

InputAdapter::~InputAdapter()
{
    if(inputThread.joinable())
        inputThread.join();
}

void InputAdapter::beginWaitingOnInput()
{
    _isWaitingForInput = true;

    if(not inputThread.joinable())
        inputThread = std::thread{userInputLoop, std::ref(*this)};
}

void InputAdapter::stopWaitingOnInput()
{
    _isWaitingForInput = false;
}