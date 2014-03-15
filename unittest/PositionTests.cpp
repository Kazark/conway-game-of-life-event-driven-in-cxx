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

TEST(PositionTests, can_create_a_position_relative_to_a_grid_of_certain_size_from_a_scalar)
{
    auto position = Position::InGridOfSize(3).fromScalar(6);
    EXPECT_EQ(Position(0, 2), position);
}

TEST(PositionTests, can_convert_itself_to_a_scalar_relative_to_a_grid)
{
    auto scalar = Position(2, 3).inGridOfSize(5).toScalar();
    EXPECT_EQ(17, scalar);
}

TEST(PositionTests, can_determine_whether_it_is_out_of_bounds_with_respect_to_give_grid)
{
    EXPECT_TRUE(Position(-1, 0).inGridOfSize(2).isOutOfBounds());
    EXPECT_TRUE(Position(0, -1).inGridOfSize(2).isOutOfBounds());
    EXPECT_FALSE(Position(0, 0).inGridOfSize(2).isOutOfBounds());
    EXPECT_FALSE(Position(1, 1).inGridOfSize(2).isOutOfBounds());
    EXPECT_TRUE(Position(2, 0).inGridOfSize(2).isOutOfBounds());
    EXPECT_TRUE(Position(0, 2).inGridOfSize(2).isOutOfBounds());
}
