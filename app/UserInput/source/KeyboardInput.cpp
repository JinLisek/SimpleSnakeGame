#include "KeyboardInput.hpp"
#include "SFML/Window/Keyboard.hpp"
#include "SFML/Window.hpp"
#include "Game.hpp"

void getUserInput()
{
    sf::Window window(sf::VideoMode(800, 600), "Window Title");

    while(window.isOpen())
    {
        sf::Event event;

        while(window.pollEvent(event))
        {
            if(event.type == sf::Event::Closed)
                window.close();
        }

        window.display();
    }

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