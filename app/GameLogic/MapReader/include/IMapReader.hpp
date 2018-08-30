#pragma once

#include <memory>

class Map;
class Snake;

class IMapReader
{
public:
    virtual ~IMapReader() = default;
    
    virtual std::unique_ptr<Map> readMap() const = 0;
    virtual std::unique_ptr<Snake> readSnake() const = 0;
};