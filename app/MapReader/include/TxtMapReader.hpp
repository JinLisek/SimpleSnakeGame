#pragma once

#include "IMapReader.hpp"

class TxtMapReader : public IMapReader
{
public:
    ~TxtMapReader() override = default;

    std::unique_ptr<Map> readMapFromFile(const std::string& filePath) const override;
};