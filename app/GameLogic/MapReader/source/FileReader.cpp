#include <streambuf>
#include "FileReader.hpp"
#include "FileReaderException.hpp"

FileReader::FileReader(const std::string& filePath) :
    fileStream{filePath}
{
    if(not fileStream)
        throw FileReaderException{};
}

FileReader::~FileReader()
{
    fileStream.close();
}

std::string FileReader::getFileContent()
{
    return std::string {std::istreambuf_iterator<char>(fileStream), std::istreambuf_iterator<char>()};
}