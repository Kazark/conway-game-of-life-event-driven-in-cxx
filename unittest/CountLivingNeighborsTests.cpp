#include "gtest/gtest.h"

#include "CountLivingNeighbors.hpp"
using namespace ::ConwayGameOfLife;

#include "PublisherMock.hpp"
#include "LivingNeighborsOfLiveCellCounted.hpp"
#include "LivingNeighborsOfDeadCellCounted.hpp"

struct CountLivingNeighborsTests: public ::testing::Test
{
    CountLivingNeighborsTests() :
        publisher(),
        objectUnderTest(publisher)
    {
    };

    PublisherMock publisher;
    CountLivingNeighbors objectUnderTest;
};

TEST_F(CountLivingNeighborsTests, emits_one_event_for_each_cell_in_the_grid_of_the_completed_generation)
{
    GenerationCompleted event = { true, false, true, true };
    objectUnderTest.handle(event);
    EXPECT_EQ(3, publisher.numberOfEventsOfType<LivingNeighborsOfLiveCellCounted>());
    EXPECT_EQ(1, publisher.numberOfEventsOfType<LivingNeighborsOfDeadCellCounted>());
}
