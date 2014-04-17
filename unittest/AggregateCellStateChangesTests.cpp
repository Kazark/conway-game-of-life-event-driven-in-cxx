#include "gtest/gtest.h"

#include "AggregateCellStateChanges.hpp"
#include "CellStateChangesAggregated.hpp"
using namespace ::ConwayGameOfLife;
using namespace ::EventArchitecture;

#include "PublisherMock.hpp"

struct AggregateCellStateChangesTests: public ::testing::Test
{
    AggregateCellStateChangesTests() :
        heapAllocator(),
        publisher(heapAllocator),
        objectUnderTest(publisher)
    {
        heapAllocator.registerSubtype<CellStateChangesAggregated>();
        objectUnderTest.handle(GameInitiated({ true, false, false, true }));
    };

    HeapAllocatorForSubtypesOf<Event> heapAllocator;
    PublisherMock publisher;
    AggregateCellStateChanges objectUnderTest;

    void threeStateChanges() {
        objectUnderTest.handle(CellStateChanged());
        objectUnderTest.handle(CellStateChanged());
        objectUnderTest.handle(CellStateChanged());
    }

    void fourStateChanges() {
        threeStateChanges();
        objectUnderTest.handle(CellStateChanged());
    }
};

TEST_F(AggregateCellStateChangesTests, does_not_emit_event_before_all_state_changes_have_been_handled)
{
    threeStateChanges();

    ASSERT_FALSE(publisher.any());
}

TEST_F(AggregateCellStateChangesTests, emits_aggregate_event_once_all_state_changes_have_been_handled)
{
    fourStateChanges();

    ASSERT_EQ(1, publisher.numberOfEventsOfType<CellStateChangesAggregated>());
    ASSERT_EQ(2, publisher.lastEventOfType<CellStateChangesAggregated>()->aggregateState.size());
}

TEST_F(AggregateCellStateChangesTests, resets_its_state_after_publishing)
{
    fourStateChanges();
    threeStateChanges();
    EXPECT_EQ(1, publisher.numberOfEventsOfType<CellStateChangesAggregated>());

    objectUnderTest.handle(CellStateChanged());

    ASSERT_EQ(2, publisher.numberOfEventsOfType<CellStateChangesAggregated>());
}
