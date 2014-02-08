#include "gtest/gtest.h"

#include "LivingNeighborsOfDeadCellCountedHandler.hpp"
using namespace ::ConwayGameOfLife;

#include "MockHandler.hpp"

struct LivingNeighborsOfDeadCellCountedHandlerTests: public ::testing::Test
{
    LivingNeighborsOfDeadCellCountedHandlerTests() :
        cellDiedHandler(),
        cellLivedHandler(),
        objectUnderTest(cellLivedHandler, cellDiedHandler)
    {
    };

    MockHandler<CellDied> cellDiedHandler;
    MockHandler<CellLived> cellLivedHandler;
    LivingNeighborsOfDeadCellCountedHandler objectUnderTest;
};

TEST_F(LivingNeighborsOfDeadCellCountedHandlerTests, Dead_cell_remains_dead_with_less_than_three_living_neighbors)
{
    LivingNeighborsOfDeadCellCounted event;
    event.numberOfLivingNeighbors = 2;

    objectUnderTest.handle(event);

    EXPECT_TRUE(cellDiedHandler.wasCalled);
    EXPECT_FALSE(cellLivedHandler.wasCalled);
}

TEST_F(LivingNeighborsOfDeadCellCountedHandlerTests, Dead_cell_with_three_living_neighbors_comes_to_life)
{
    LivingNeighborsOfDeadCellCounted event;
    event.numberOfLivingNeighbors = 3;

    objectUnderTest.handle(event);

    EXPECT_FALSE(cellDiedHandler.wasCalled);
    EXPECT_TRUE(cellLivedHandler.wasCalled);
}

TEST_F(LivingNeighborsOfDeadCellCountedHandlerTests, Dead_cell_remains_dead_with_more_than_three_living_neighbors)
{
    LivingNeighborsOfDeadCellCounted event;
    event.numberOfLivingNeighbors = 4;

    objectUnderTest.handle(event);

    EXPECT_TRUE(cellDiedHandler.wasCalled);
    EXPECT_FALSE(cellLivedHandler.wasCalled);
}

TEST_F(LivingNeighborsOfDeadCellCountedHandlerTests, Position_published_when_cell_remains_dead)
{
    LivingNeighborsOfDeadCellCounted event;
    event.cellLocation = CartesianPosition(1, 2);

    objectUnderTest.handle(event);

    ASSERT_EQ(event.cellLocation, cellDiedHandler.handledEvent.location);
}

TEST_F(LivingNeighborsOfDeadCellCountedHandlerTests, Position_published_when_cell_comes_to_life)
{
    LivingNeighborsOfDeadCellCounted event;
    event.numberOfLivingNeighbors = 3;
    event.cellLocation = CartesianPosition(1, 2);

    objectUnderTest.handle(event);

    ASSERT_EQ(event.cellLocation, cellLivedHandler.handledEvent.location);
}
