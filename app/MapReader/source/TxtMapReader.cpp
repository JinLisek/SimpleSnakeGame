#include <fstream>

#include "TxtMapReader.hpp"
#include "Map.hpp"

std::unique_ptr<Map> TxtMapReader::readMapFromFile(const std::string& filePath) const //TODO: REFACTOR!!!!!!!
{
    std::ifstream mapInputFile {filePath};

    auto map = std::make_unique<Map>(Map::VerticalPosition{3}, Map::HorizontalPosition{3});

    std::string tileRow {};

    unsigned x = 0;
    unsigned y = 0;

    if(mapInputFile.is_open())
    {
        while(getline(mapInputFile, tileRow))
        {
            for(const auto tileChar : tileRow)
            {
                if(tileChar == '#')
                {
                    map->buildWallOnTile(Map::VerticalPosition{y}, Map::HorizontalPosition{x});
                }
                else if(tileChar == '$')
                {
                    map->placePointsOnTile(Map::VerticalPosition{y}, Map::HorizontalPosition{x});
                }
                ++x;
            }
            x = 0;
            ++y;
        }
    }

    mapInputFile.close();

    return std::move(map);
}