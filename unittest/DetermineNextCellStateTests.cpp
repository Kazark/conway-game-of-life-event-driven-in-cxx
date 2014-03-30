#include "gtest/gtest.h"

#include "DetermineNextCellState.hpp"
#include "CellStateChanged.hpp"
using namespace ::ConwayGameOfLife;

#include "HeapAllocatorForSubtypesOf.hpp"
using namespace ::EventArchitecture;

#include "EnhancedPublisherMock.hpp"

struct DetermineNextCellStateTests: public ::testing::Test
{
    DetermineNextCellStateTests() :
        publisher(heapAllocator),
        objectUnderTest(publisher)
    {
        heapAllocator.registerSubtype<CellStateChanged>();
    };

    HeapAllocatorForSubtypesOf<Event> heapAllocator;
    EnhancedPublisherMock publisher;
    DetermineNextCellState objectUnderTest;
};

TEST_F(DetermineNextCellStateTests, Dead_cell_remains_dead_with_less_than_three_living_neighbors)
{
    LivingNeighborsOfCellCounted event;
    event.numberOfLivingNeighbors = 2;
    event.isCellAlive = false;

    objectUnderTest.handle(event);

    EXPECT_FALSE(publisher.lastEventOfType<CellStateChanged>()->cellIsNowAlive);
}

TEST_F(DetermineNextCellStateTests, Dead_cell_with_three_living_neighbors_comes_to_life)
{
    LivingNeighborsOfCellCounted event;
    event.numberOfLivingNeighbors = 3;
    event.isCellAlive = false;

    objectUnderTest.handle(event);

    EXPECT_TRUE(publisher.lastEventOfType<CellStateChanged>()->cellIsNowAlive);
}

TEST_F(DetermineNextCellStateTests, Dead_cell_remains_dead_with_more_than_three_living_neighbors)
{
    LivingNeighborsOfCellCounted event;
    event.numberOfLivingNeighbors = 4;
    event.isCellAlive = false;

    objectUnderTest.handle(event);

    EXPECT_FALSE(publisher.lastEventOfType<CellStateChanged>()->cellIsNowAlive);
}

TEST_F(DetermineNextCellStateTests, Publishes_position_from_incoming_event)
{
    LivingNeighborsOfCellCounted event;
    event.numberOfLivingNeighbors = 0;
    event.cellPosition = Position(1, 2);
    event.isCellAlive = false;

    objectUnderTest.handle(event);

    ASSERT_EQ(event.cellPosition, publisher.lastEventOfType<CellStateChanged>()->position);
}

TEST_F(DetermineNextCellStateTests, Live_cell_dies_with_less_than_two_living_neighbors)
{
    LivingNeighborsOfCellCounted event;
    event.numberOfLivingNeighbors = 1;
    event.isCellAlive = true;

    objectUnderTest.handle(event);

    EXPECT_FALSE(publisher.lastEventOfType<CellStateChanged>()->cellIsNowAlive);
}

TEST_F(DetermineNextCellStateTests, Live_cell_with_two_living_neighbors_stays_alive)
{
    LivingNeighborsOfCellCounted event;
    event.numberOfLivingNeighbors = 2;
    event.isCellAlive = true;

    objectUnderTest.handle(event);

    EXPECT_TRUE(publisher.lastEventOfType<CellStateChanged>()->cellIsNowAlive);
}

TEST_F(DetermineNextCellStateTests, Live_cell_with_three_living_neighbors_stays_alive)
{
    LivingNeighborsOfCellCounted event;
    event.numberOfLivingNeighbors = 3;
    event.isCellAlive = true;

    objectUnderTest.handle(event);

    EXPECT_TRUE(publisher.lastEventOfType<CellStateChanged>()->cellIsNowAlive);
}

TEST_F(DetermineNextCellStateTests, Living_cell_with_more_than_three_living_neighbors_dies)
{
    LivingNeighborsOfCellCounted event;
    event.numberOfLivingNeighbors = 4;
    event.isCellAlive = true;

    objectUnderTest.handle(event);

    EXPECT_FALSE(publisher.lastEventOfType<CellStateChanged>()->cellIsNowAlive);
}

