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
    ASSERT_TRUE(publisher.onlyOne());
    ASSERT_EQ(event.grid, publisher.lastEventOfType<GenerationCompleted>()->grid);
}

TEST_F(HasGameReachedTerminalStateTests, publishes_StasisReached_if_game_begins_in_stasis)
{
    Grid grid {{ true, false, true, false }};
    objectUnderTest.handle(GameInitiated(grid));
    objectUnderTest.handle(CellStateChangesAggregated(grid));
    ASSERT_EQ(1, publisher.numberOfEventsOfType<StasisReached>());
}

TEST_F(HasGameReachedTerminalStateTests, publishes_GenerationCompleted_if_game_state_is_not_terminal)
{
    GameInitiated firstGeneration{ true, true, true, false };
    CellStateChangesAggregated secondGeneration{ true, false, true, false };
    objectUnderTest.handle(firstGeneration);
    objectUnderTest.handle(secondGeneration);
    ASSERT_EQ(secondGeneration.aggregateState, publisher.lastEventOfType<GenerationCompleted>()->grid);
}

TEST_F(HasGameReachedTerminalStateTests, publishes_StasisReached_if_game_settles_into_stasis)
{
    GameInitiated firstGeneration{ true, true, true, false };
    CellStateChangesAggregated secondGeneration{ true, false, true, false };
    objectUnderTest.handle(firstGeneration);
    objectUnderTest.handle(secondGeneration);
    objectUnderTest.handle(secondGeneration);
    ASSERT_EQ(2, publisher.numberOfEventsOfType<GenerationCompleted>());
    ASSERT_TRUE(publisher.lastEventWasOfType<StasisReached>());
}
