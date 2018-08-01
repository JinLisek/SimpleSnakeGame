#pragma once

#include <thread>

class KeyboardInput
{
public:
    ~KeyboardInput();
    void beginWaitingOnInput();

private:
    std::thread inputThread;
};