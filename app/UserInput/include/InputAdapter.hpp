#pragma once

#include <thread>

class InputAdapter
{
public:
    ~InputAdapter();

    bool isWaitingForInput() const { return _isWaitingForInput; }

    void beginWaitingOnInput();
    void stopWaitingOnInput();
private:
    bool _isWaitingForInput = false;
    std::thread inputThread;
};