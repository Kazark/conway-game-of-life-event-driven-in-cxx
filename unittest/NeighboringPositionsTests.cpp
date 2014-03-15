#include "gtest/gtest.h"

#include "NeighboringPositions.hpp"
using namespace ::ConwayGameOfLife;

#include <algorithm>

class NeighboringPositionsTests : public ::testing::Test {
public:
    NeighboringPositionsTests() :
        position(3, 0),
        objectUnderTest(position)
    {}

    Position position;
    NeighboringPositions objectUnderTest;
};

TEST_F(NeighboringPositionsTests, knows_the_position_of_the_cell_one_unit_north)
{
    ASSERT_EQ(Position(3, -1), objectUnderTest.northern());
}

TEST_F(NeighboringPositionsTests, knows_the_position_of_the_cell_one_unit_north_and_one_unit_east)
{
    ASSERT_EQ(Position(4, -1), objectUnderTest.northeastern());
}

TEST_F(NeighboringPositionsTests, knows_the_position_of_the_cell_one_unit_east)
{
    ASSERT_EQ(Position(4, 0), objectUnderTest.eastern());
}

TEST_F(NeighboringPositionsTests, knows_the_position_of_the_cell_one_unit_south_and_one_unit_east)
{
    ASSERT_EQ(Position(4, 1), objectUnderTest.southeastern());
}

TEST_F(NeighboringPositionsTests, knows_the_position_of_the_cell_one_unit_south)
{
    ASSERT_EQ(Position(3, 1), objectUnderTest.southern());
}

TEST_F(NeighboringPositionsTests, knows_the_position_of_the_cell_one_unit_south_and_one_unit_west)
{
    ASSERT_EQ(Position(2, 1), objectUnderTest.southwestern());
}

TEST_F(NeighboringPositionsTests, knows_the_position_of_the_cell_one_unit_west)
{
    ASSERT_EQ(Position(2, 0), objectUnderTest.western());
}

TEST_F(NeighboringPositionsTests, knows_the_position_of_the_cell_one_unit_north_and_one_unit_west)
{
    ASSERT_EQ(Position(2, -1), objectUnderTest.northwestern());
}

TEST_F(NeighboringPositionsTests, has_an_iterator)
{
    int count = 0;
    for (auto neighbor : objectUnderTest.iterator())
    {
        EXPECT_NE(position, neighbor);
        count++;
    }
    ASSERT_EQ(8, count);
}
