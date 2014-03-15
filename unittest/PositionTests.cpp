#include "gtest/gtest.h"

#include "Position.hpp"
using namespace ::ConwayGameOfLife;

TEST(PositionTests, has_equals_and_not_equals_operators)
{
    EXPECT_NE(Position(0, 0), Position(0, 1));
    EXPECT_NE(Position(0, 0), Position(1, 0));
    EXPECT_NE(Position(0, 1), Position(1, 0));
    EXPECT_EQ(Position(1, 1), Position(1, 1));
}

TEST(PositionTests, has_x_and_y_accessors)
{
    EXPECT_EQ(1, Position(1, 2).x());
    EXPECT_EQ(2, Position(1, 2).y());
}
