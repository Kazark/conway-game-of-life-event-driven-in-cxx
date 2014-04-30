#include "gtest/gtest.h"

#include "HasGameReachedTerminalState.hpp"
#include "GenerationCompleted.hpp"
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
    }

    HeapAllocatorForSubtypesOf<Event> heapAllocator;
    PublisherMock publisher;
    HasGameReachedTerminalState objectUnderTest;
};

TEST_F(HasGameReachedTerminalStateTests, publishes_GenerationCompleted_from_GameInitiated)
{
    GameInitiated event{ true, false, true, false };
    objectUnderTest.handle(event);
    ASSERT_TRUE(publisher.any());
}
