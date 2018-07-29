#include <gtest/gtest.h>

#include "FileReader.hpp"
#include "FileReaderException.hpp"

using namespace testing;

class FileReaderTest : public Test
{
public:
};

TEST_F(FileReaderTest, CheckThatExceptionIsThrownWhenFileIsNotPresent)
{
    EXPECT_THROW(FileReader{"FileThatDoesNotExist.abrakadabra"}, FileReaderException);
}

TEST_F(FileReaderTest, CheckThatFileReaderDoesNotThrowForEmptyFile)
{
    FileReader reader {"test_input/EmptyFile.txt"};
}

TEST_F(FileReaderTest, CheckThatFileReaderGivesFiveDotsForFiveDotsFile)
{
    FileReader reader {"test_input/FiveDots.txt"};

    const auto fileContent = reader.getFileContent();

    EXPECT_STREQ(".....", fileContent.c_str());
}

TEST_F(FileReaderTest, CheckThatFileReaderGivesAlphabet)
{
    FileReader reader {"test_input/Alphabet.txt"};

    const auto fileContent = reader.getFileContent();

    EXPECT_STREQ(
        "abcdefghijklmnopqrstuvwxyz\nABCDEFGHIJKLMNOPQRSTUVWXYZ",
        fileContent.c_str());
}