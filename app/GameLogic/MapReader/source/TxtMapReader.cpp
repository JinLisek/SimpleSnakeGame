#include <iostream>

#include "TxtMapReader.hpp"
#include "Map.hpp"
#include "FileReader.hpp"
#include "PositionTypes.hpp"

namespace
{

size_t findNumberInFirstLineAndEraseTheLine(std::string& text) //TODO: move it somewhere else?
{
    auto endOfLinePosition = text.find('\n');
    std::string textValue {text.substr(0, endOfLinePosition)};
    text.erase(0, endOfLinePosition + 1);
    return std::stoul(textValue);//TODO: exceptions
}

Map readMapFromFile(const std::string& filePath) //TODO: REFACTOR!!!!!!!
{
    FileReader file{filePath};
    std::string fileContent = file.getFileContent();
    
    const unsigned mapWidth = findNumberInFirstLineAndEraseTheLine(fileContent); //TODO: add exceptions when incorrect map size
    const unsigned mapHeight = findNumberInFirstLineAndEraseTheLine(fileContent);

    auto map = Map{PosX{mapWidth}, PosY{mapHeight}};

    unsigned vertical = 0;
    unsigned horizontal = 0;

    for(const auto inputChar : fileContent)
    {
        if(inputChar == '#') //TODO: refactor to factory or something?
        {
            map.buildWallOnTile(PosX{horizontal}, PosY{vertical});
        }
        else if(inputChar == '$')
        {
            map.placePointsOnTile(PosX{horizontal}, PosY{vertical});
        }
        else if(inputChar == '\n')
        {
            ++vertical;
            horizontal = -1;
        }

        ++horizontal;
    }

    return std::move(map);
}

Snake readSnakeFromFile(const std::string& filePath) //TODO: remove duplication with above
{
        FileReader file{filePath};
    std::string fileContent = file.getFileContent();
    
    const unsigned mapWidth = findNumberInFirstLineAndEraseTheLine(fileContent); //TODO: add exceptions when incorrect map size
    const unsigned mapHeight = findNumberInFirstLineAndEraseTheLine(fileContent);

    unsigned vertical = 0;
    unsigned horizontal = 0;

    for(const auto inputChar : fileContent)
    {
        if(inputChar == 'H') //TODO: refactor to factory or something?
        {
            break;
        }
        else if(inputChar == '\n')
        {
            ++vertical;
            horizontal = -1;
        }

        ++horizontal;
    }

    return Snake{PosX{horizontal}, PosY{vertical}};
}

}

TxtMapReader::TxtMapReader(const std::string& filePath) :
    _filePath {filePath},
    _map{readMapFromFile(_filePath)},
    _snake{readSnakeFromFile(_filePath)}
{
}

std::unique_ptr<Map> TxtMapReader::readMap() const
{
    return std::make_unique<Map>(_map);
}

std::unique_ptr<Snake> TxtMapReader::readSnake() const
{
    return std::make_unique<Snake>(_snake);
}