#pragma once

#include <string>
#include <fstream>

class FileReader
{
public:
    FileReader(const std::string& filePath); //TODO: change to boost::filesystem::path
    ~FileReader();

    std::string getFileContent();
private:
    std::ifstream fileStream;
};