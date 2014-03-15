#include "gtest/gtest.h"

#include "DetermineNextStateOfLiveCell.hpp"
using namespace ::ConwayGameOfLife;

#include "MockHandler.hpp"

struct DetermineNextStateOfLiveCellTests: public ::testing::Test
{
    DetermineNextStateOfLiveCellTests() :
        cellDiedHandler(),
        cellLivedHandler(),
        objectUnderTest(cellLivedHandler, cellDiedHandler)
    {
    };

    MockHandler<CellDied> cellDiedHandler;
    MockHandler<CellLived> cellLivedHandler;
    DetermineNextStateOfLiveCell objectUnderTest;
};

TEST_F(DetermineNextStateOfLiveCellTests, Live_cell_dies_with_less_than_two_living_neighbors)
{
    LivingNeighborsOfLiveCellCounted event;
    event.numberOfLivingNeighbors = 1;

    objectUnderTest.handle(event);

    EXPECT_TRUE(cellDiedHandler.wasCalled);
    EXPECT_FALSE(cellLivedHandler.wasCalled);
}

TEST_F(DetermineNextStateOfLiveCellTests, Live_cell_with_two_living_neighbors_stays_alive)
{
    LivingNeighborsOfLiveCellCounted event;
    event.numberOfLivingNeighbors = 2;

    objectUnderTest.handle(event);

    EXPECT_FALSE(cellDiedHandler.wasCalled);
    EXPECT_TRUE(cellLivedHandler.wasCalled);
}

TEST_F(DetermineNextStateOfLiveCellTests, Live_cell_with_three_living_neighbors_stays_alive)
{
    LivingNeighborsOfLiveCellCounted event;
    event.numberOfLivingNeighbors = 3;

    objectUnderTest.handle(event);

    EXPECT_FALSE(cellDiedHandler.wasCalled);
    EXPECT_TRUE(cellLivedHandler.wasCalled);
}

TEST_F(DetermineNextStateOfLiveCellTests, Living_cell_with_more_than_three_living_neighbors_dies)
{
    LivingNeighborsOfLiveCellCounted event;
    event.numberOfLivingNeighbors = 4;

    objectUnderTest.handle(event);

    EXPECT_TRUE(cellDiedHandler.wasCalled);
    EXPECT_FALSE(cellLivedHandler.wasCalled);
}

TEST_F(DetermineNextStateOfLiveCellTests, Position_published_when_cell_dies)
{
    LivingNeighborsOfLiveCellCounted event;
    event.numberOfLivingNeighbors = 8;
    event.cellLocation = CartesianPosition(1, 2);

    objectUnderTest.handle(event);

    ASSERT_EQ(event.cellLocation, cellDiedHandler.handledEvent.position);
}

TEST_F(DetermineNextStateOfLiveCellTests, Position_published_when_cell_remains_alive)
{
    LivingNeighborsOfLiveCellCounted event;
    event.numberOfLivingNeighbors = 3;
    event.cellLocation = CartesianPosition(1, 2);

    objectUnderTest.handle(event);

    ASSERT_EQ(event.cellLocation, cellLivedHandler.handledEvent.position);
}
