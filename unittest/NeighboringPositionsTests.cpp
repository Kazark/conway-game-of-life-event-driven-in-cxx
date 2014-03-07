#include "gtest/gtest.h"

#include "NeighboringPositions.hpp"
using namespace ::ConwayGameOfLife;

class NeighboringPositionsTests : public ::testing::Test {
public:
    NeighboringPositionsTests() :
        position(3, 0),
        objectUnderTest(position)
    {}

    CartesianPosition position;
    NeighboringPositions objectUnderTest;
};

TEST_F(NeighboringPositionsTests, knows_the_position_of_the_cell_one_unit_north)
{
    ASSERT_EQ(CartesianPosition(3, -1), objectUnderTest.northern());
}

TEST_F(NeighboringPositionsTests, knows_the_position_of_the_cell_one_unit_north_and_one_unit_east)
{
    ASSERT_EQ(CartesianPosition(4, -1), objectUnderTest.northeastern());
}

TEST_F(NeighboringPositionsTests, knows_the_position_of_the_cell_one_unit_east)
{
    ASSERT_EQ(CartesianPosition(4, 0), objectUnderTest.eastern());
}

TEST_F(NeighboringPositionsTests, knows_the_position_of_the_cell_one_unit_south_and_one_unit_east)
{
    ASSERT_EQ(CartesianPosition(4, 1), objectUnderTest.southeastern());
}

TEST_F(NeighboringPositionsTests, knows_the_position_of_the_cell_one_unit_south)
{
    ASSERT_EQ(CartesianPosition(3, 1), objectUnderTest.southern());
}

TEST_F(NeighboringPositionsTests, knows_the_position_of_the_cell_one_unit_south_and_one_unit_west)
{
    ASSERT_EQ(CartesianPosition(2, 1), objectUnderTest.southwestern());
}

TEST_F(NeighboringPositionsTests, knows_the_position_of_the_cell_one_unit_west)
{
    ASSERT_EQ(CartesianPosition(2, 0), objectUnderTest.western());
}

TEST_F(NeighboringPositionsTests, knows_the_position_of_the_cell_one_unit_north_and_one_unit_west)
{
    ASSERT_EQ(CartesianPosition(2, -1), objectUnderTest.northwestern());
}
