#include "gtest/gtest.h"

#include "CountLivingNeighbors.hpp"
using namespace ::ConwayGameOfLife;

#include "MockHandler.hpp"

struct CountLivingNeighborsTests: public ::testing::Test
{
    CountLivingNeighborsTests() :
        liveHandler(),
        deadHandler(),
        objectUnderTest(liveHandler, deadHandler)
    {
    };

    MockHandler<LivingNeighborsOfLiveCellCounted> liveHandler;
    MockHandler<LivingNeighborsOfDeadCellCounted> deadHandler;
    CountLivingNeighbors objectUnderTest;
};

TEST_F(CountLivingNeighborsTests, emits_one_event_for_each_cell_in_the_grid_of_the_completed_generation)
{
    GenerationCompleted event = { true, false, true, true };
    objectUnderTest.handle(event);
    EXPECT_EQ(3U, liveHandler.handledEvents.size());
    EXPECT_EQ(1U, deadHandler.handledEvents.size());
}
