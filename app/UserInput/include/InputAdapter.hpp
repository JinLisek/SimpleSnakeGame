#pragma once

#include <thread>
#include "IPlayerController.hpp"

class InputAdapter
{
public:
    InputAdapter(IPlayerController&  playerController);
    ~InputAdapter();

    bool isWaitingForInput() const { return _isWaitingForInput; }

    void beginWaitingOnInput();
    void stopWaitingOnInput();

private:
    bool _isWaitingForInput = false;
    IPlayerController& _playerController;
    std::thread _inputThread;
};