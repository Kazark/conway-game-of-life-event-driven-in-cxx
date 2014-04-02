#include "gtest/gtest.h"

#include "CountLivingNeighbors.hpp"
#include "LivingNeighborsOfCellCounted.hpp"
using namespace ::ConwayGameOfLife;
using namespace ::EventArchitecture;

#include "PublisherMock.hpp"

struct CountLivingNeighborsTests: public ::testing::Test
{
    CountLivingNeighborsTests() :
        heapAllocator(),
        publisher(heapAllocator),
        objectUnderTest(publisher)
    {
        heapAllocator.registerSubtype<LivingNeighborsOfCellCounted>();
    };

    HeapAllocatorForSubtypesOf<Event> heapAllocator;
    PublisherMock publisher;
    CountLivingNeighbors objectUnderTest;
};

TEST_F(CountLivingNeighborsTests, emits_one_event_for_each_cell_in_the_grid_of_the_completed_generation)
{
    GenerationCompleted event = { true, false, true, true };
    objectUnderTest.handle(event);
    EXPECT_EQ(4, publisher.numberOfEventsOfType<LivingNeighborsOfCellCounted>());
}

TEST_F(CountLivingNeighborsTests, publishes_event_for_living_cell)
{
    GenerationCompleted event = { true };
    objectUnderTest.handle(event);
    EXPECT_TRUE(publisher.lastEventOfType<LivingNeighborsOfCellCounted>()->isCellAlive);
}

TEST_F(CountLivingNeighborsTests, publishes_event_for_dead_cell)
{
    GenerationCompleted event = { false };
    objectUnderTest.handle(event);
    EXPECT_FALSE(publisher.lastEventOfType<LivingNeighborsOfCellCounted>()->isCellAlive);
}

TEST_F(CountLivingNeighborsTests, publishes_position_information_for_cells)
{
    GenerationCompleted event = { true, false, true, true };
    objectUnderTest.handle(event);
    EXPECT_EQ(Position(1, 1), publisher.lastEventOfType<LivingNeighborsOfCellCounted>()->cellPosition);
}
