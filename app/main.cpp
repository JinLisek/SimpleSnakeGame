#include <iostream>
#include <chrono>
#include <thread>
#include "TileRepresentation.hpp"
#include "TileRepresentationFactory.hpp"
#include "Map.hpp"
#include "MapRepresentation.hpp"
#include "TxtMapReader.hpp"
#include "KeyboardInput.hpp"

bool QUIT = false;

void getUserInput()
{
    char inputCharacter;
    while(true)
    {
       inputCharacter = getch();

        if(inputCharacter == 27)
        {
            QUIT = true;
            break;
        }
    }
}

void clear() { //TODO: Change so it's not saved in console buffor
    // CSI[2J clears screen, CSI[H moves the cursor to top-left corner
    std::cout << "\x1B[2J\x1B[H";
}

void drawMap()
{
    TxtMapReader mapReader{};
    auto map = mapReader.readMapFromFile("../Maps/DefaultMap.txt");
    MapRepresentation mapRepresentation {*map};

    while(true)
    {
        clear();
        std::cout << mapRepresentation.draw() << std::endl;

        if(QUIT)
            break;

        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    }
}

int main()
{
    std::thread keyboardInput(getUserInput);
    std::thread graphicalOutput(drawMap);

    keyboardInput.join();
    graphicalOutput.join();

    return 0;
}
