#include "InputAdapter.hpp"
#include "GraphicsOutput.hpp"
#include "PlayerController.hpp"

int main()
{
    GraphicsOutput graphics {};
    graphics.beginDrawingGraphics();

    PlayerController playerController {};
    InputAdapter inputAdapter {playerController};
    inputAdapter.beginWaitingOnInput();

    return 0;
}
