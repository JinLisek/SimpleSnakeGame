#pragma once

#include <memory>

class Map;

class IMapReader
{
public:
    virtual ~IMapReader() = default;
    
    virtual std::unique_ptr<Map> readMapFromFile(const std::string& filePath) const = 0;//TODO: How to link boost::filesystem::path in cmake?
};