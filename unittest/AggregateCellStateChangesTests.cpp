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
        objectUnderTest.handle({ true, false, false, true });
    };

    HeapAllocatorForSubtypesOf<Event> heapAllocator;
    PublisherMock publisher;
    AggregateCellStateChanges objectUnderTest;
};

TEST_F(AggregateCellStateChangesTests, does_not_emit_event_before_all_state_changes_have_been_published)
{
    objectUnderTest.handle(CellStateChanged());
    objectUnderTest.handle(CellStateChanged());
    objectUnderTest.handle(CellStateChanged());

    ASSERT_FALSE(publisher.any());
}

