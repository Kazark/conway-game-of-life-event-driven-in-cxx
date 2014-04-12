#include "gtest/gtest.h"

#include "BuildGrid.hpp"
using namespace ::ConwayGameOfLife;

TEST(BuildGridTests, grid_is_not_finished_when_initialized)
{
    ASSERT_FALSE(BuildGrid::OfSize(4).finished());
}

TEST(BuildGridTests, grid_is_not_finished_until_all_cells_have_been_filled)
{
    auto objectUnderTest = BuildGrid::OfSize(2);

    objectUnderTest.atPositionSetCellState({0, 0}, false);
    objectUnderTest.atPositionSetCellState({0, 1}, true);
    objectUnderTest.atPositionSetCellState({1, 1}, true);

    ASSERT_FALSE(objectUnderTest.finished());
}

TEST(BuildGridTests, grid_is_finished_once_all_cells_have_been_filled)
{
    auto objectUnderTest = BuildGrid::OfSize(2);

    objectUnderTest.atPositionSetCellState({0, 0}, false);
    objectUnderTest.atPositionSetCellState({0, 1}, true);
    objectUnderTest.atPositionSetCellState({1, 0}, true);
    objectUnderTest.atPositionSetCellState({1, 1}, true);

    ASSERT_TRUE(objectUnderTest.finished());
}

