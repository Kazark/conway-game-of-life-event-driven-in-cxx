#include "gtest/gtest.h"

#include "BuildGrid.hpp"
#include "Cell.hpp"
using namespace ::ConwayGameOfLife;

struct BuildGridTests: public ::testing::Test {
    BuildGridTests() :
        objectUnderTest(BuildGrid::OfSize(2))
    {
    }

    BuildGrid objectUnderTest;

    void setThreeStates() {
        objectUnderTest.atPositionSetCellState({1, 0}, false);
        objectUnderTest.atPositionSetCellState({0, 1}, true);
        objectUnderTest.atPositionSetCellState({0, 0}, true);
    }

    void setFourStates() {
        setThreeStates();
        objectUnderTest.atPositionSetCellState({1, 1}, true);
    }
};

TEST_F(BuildGridTests, grid_is_not_finished_when_initialized)
{
    ASSERT_FALSE(objectUnderTest.finished());
}

TEST_F(BuildGridTests, grid_is_not_finished_until_all_cells_have_been_filled)
{
    setThreeStates();

    ASSERT_FALSE(objectUnderTest.finished());
}

TEST_F(BuildGridTests, grid_is_finished_once_all_cells_have_been_filled)
{
    setFourStates();

    ASSERT_TRUE(objectUnderTest.finished());
}

TEST_F(BuildGridTests, builds_grid_of_correct_size)
{
    ASSERT_EQ(2, objectUnderTest.build().size());
}

TEST_F(BuildGridTests, builds_grid_correctly_even_when_cells_are_not_assigned_in_order)
{
    setFourStates();

    ASSERT_EQ(Grid({true, false, true, true}), objectUnderTest.build());
}

TEST_F(BuildGridTests, is_able_to_reset_its_state)
{
    setThreeStates();
    objectUnderTest.reset();
    objectUnderTest.atPositionSetCellState({1, 1}, true);

    ASSERT_FALSE(objectUnderTest.finished());
}
