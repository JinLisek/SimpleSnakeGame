#pragma once

#include <thread>

class GraphicsOutput
{
public:
    ~GraphicsOutput();
    void beginDrawingGraphics();

private:
    std::thread graphicsThread;
};