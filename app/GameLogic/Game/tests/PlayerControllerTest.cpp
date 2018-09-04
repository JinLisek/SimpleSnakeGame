#include <gtest/gtest.h>

#include "PlayerController.hpp"

using namespace testing;

class PlayerControllerTest : public Test
{
public:

};

TEST_F(PlayerControllerTest, CheckThatEmptyTileIsPrintedAsGreenDot)
{
    PlayerController objectUnderTest {};
}