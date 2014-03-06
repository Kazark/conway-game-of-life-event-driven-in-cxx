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
