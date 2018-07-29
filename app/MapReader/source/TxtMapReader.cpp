#include "TxtMapReader.hpp"
#include "Map.hpp"
#include "FileReader.hpp"
#include <iostream>

size_t findNumberInFirstLineAndEraseTheLine(std::string& text) //TODO: move it somewhere else?
{
    auto endOfLinePosition = text.find('\n');
    std::string textValue {text.substr(0, endOfLinePosition)};
    text.erase(0, endOfLinePosition + 1);
    return std::stoul(textValue);//TODO: exceptions
}

std::unique_ptr<Map> TxtMapReader::readMapFromFile(const std::string& filePath) const //TODO: REFACTOR!!!!!!!
{
    FileReader file{filePath};
    std::string fileContent = file.getFileContent();
    
    const size_t mapWidth = findNumberInFirstLineAndEraseTheLine(fileContent); //TODO: add exceptions when incorrect map size
    const size_t mapHeight = findNumberInFirstLineAndEraseTheLine(fileContent);

    auto map = std::make_unique<Map>(Map::VerticalPosition{mapHeight}, Map::HorizontalPosition{mapWidth});

    size_t vertical = 0;
    size_t horizontal = 0;

    for(const auto inputChar : fileContent)
    {
        if(inputChar == '#') //TODO: refactor to factory or something?
        {
            map->buildWallOnTile(Map::VerticalPosition{vertical}, Map::HorizontalPosition{horizontal});
        }
        else if(inputChar == '$')
        {
            map->placePointsOnTile(Map::VerticalPosition{vertical}, Map::HorizontalPosition{horizontal});
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