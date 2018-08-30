#include "KeyboardInput.hpp"
#include "GraphicsOutput.hpp"

int main()
{
    GraphicsOutput graphics {};
    graphics.beginDrawingGraphics();

    KeyboardInput keyInput {};
    keyInput.beginWaitingOnInput();

    return 0;
}
