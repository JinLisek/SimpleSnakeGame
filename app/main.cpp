#include "InputAdapter.hpp"
#include "GraphicsOutput.hpp"

int main()
{
    GraphicsOutput graphics {};
    graphics.beginDrawingGraphics();

    InputAdapter inputAdapter {};
    inputAdapter.beginWaitingOnInput();

    return 0;
}
