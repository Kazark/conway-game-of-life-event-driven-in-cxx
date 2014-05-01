#include "gtest/gtest.h"

#include "HasGameReachedTerminalState.hpp"
#include "GenerationCompleted.hpp"
#include "StasisReached.hpp"
using namespace ConwayGameOfLife;
using namespace EventArchitecture;

#include "PublisherMock.hpp"

struct HasGameReachedTerminalStateTests: public ::testing::Test {
    HasGameReachedTerminalStateTests():
        heapAllocator(),
        publisher(heapAllocator),
        objectUnderTest(publisher)
    {
        heapAllocator.registerSubtype<GenerationCompleted>();
        heapAllocator.registerSubtype<StasisReached>();
    }

    HeapAllocatorForSubtypesOf<Event> heapAllocator;
    PublisherMock publisher;
    HasGameReachedTerminalState objectUnderTest;
};

TEST_F(HasGameReachedTerminalStateTests, publishes_GenerationCompleted_from_GameInitiated)
{
    GameInitiated event{ true, false, true, false };
    objectUnderTest.handle(event);
    ASSERT_EQ(1, publisher.numberOfEventsOfType<GenerationCompleted>());
    ASSERT_EQ(event.grid, publisher.lastEventOfType<GenerationCompleted>()->grid);
}

TEST_F(HasGameReachedTerminalStateTests, publishes_StasisReached_if_game_begins_in_stasis)
{
    Grid grid {{ true, false, true, false }};
    objectUnderTest.handle(GameInitiated(grid));
    objectUnderTest.handle(CellStateChangesAggregated(grid));
    ASSERT_EQ(1, publisher.numberOfEventsOfType<StasisReached>());
}
