#pragma once

#include "IMapReader.hpp"
#include "Map.hpp"
#include "Snake.hpp"

class TxtMapReader : public IMapReader
{
public:
    ~TxtMapReader() override = default;
    TxtMapReader(const std::string& filePath); //TODO: How to link boost::filesystem::path in cmake?

    std::unique_ptr<Map> readMap() const override; //TODO: shorten name
    std::unique_ptr<Snake> readSnake() const override;

private:
    std::string _filePath;
    Map _map;
    Snake _snake;
};