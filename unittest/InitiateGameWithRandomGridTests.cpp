#include "gtest/gtest.h"

#include "InitiateGameWithRandomGrid.hpp"
#include "GameInitiated.hpp"
using namespace ::ConwayGameOfLife;

#include "HeapAllocatorForSubtypesOf.hpp"
#include "EnhancedPublisherMock.hpp"
using namespace ::EventArchitecture;

TEST(InitiateGameWithRandomGridTests, publishes_message_with_grid_whose_size_defaults_to_4)
{
    HeapAllocatorForSubtypesOf<Event> heapAllocator;
    EnhancedPublisherMock publisher(heapAllocator);
    heapAllocator.registerSubtype<GameInitiated>();
    InitiateGameWithRandomGrid objectUnderTest(publisher);
    
    objectUnderTest.initiate();

    ASSERT_EQ(4, publisher.lastEventOfType<GameInitiated>()->grid.size());
}
