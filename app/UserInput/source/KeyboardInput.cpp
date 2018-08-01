#include "KeyboardInput.hpp"
#include "SFML/Window/Keyboard.hpp"
#include "Game.hpp"

void getUserInput()
{
    while(true)
    {
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
        {
            Game::gameState = GameState::Quit;
            break;
        }
    }
}

KeyboardInput::~KeyboardInput()
{
    if(inputThread.joinable())
        inputThread.join();
}

void KeyboardInput::beginWaitingOnInput()
{
    inputThread = std::thread{getUserInput};
}