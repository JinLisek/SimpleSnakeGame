#include <iostream>
#include "GraphicsOutput.hpp"
#include "Game.hpp"
#include "MapRepresentation.hpp"

void clear() { //TODO: Change so it's not saved in console buffor
    // CSI[2J clears screen, CSI[H moves the cursor to top-left corner
    std::cout << "\x1B[2J\x1B[H";
}

void drawMap()
{
    Game game {};
    auto map = game.getMap();
    MapRepresentation mapRepresentation {*map};

    while(true)
    {
        clear();
        std::cout << mapRepresentation.draw() << std::endl;

        if(Game::gameState == GameState::Quit)
            break;

        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    }
}

GraphicsOutput::~GraphicsOutput()
{
    if(graphicsThread.joinable())
        graphicsThread.join();
}

void GraphicsOutput::beginDrawingGraphics()
{
    graphicsThread = std::thread{drawMap};
}