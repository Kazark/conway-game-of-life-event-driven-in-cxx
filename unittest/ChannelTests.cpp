#include "gtest/gtest.h"

// Code under test
#include "Channel.hpp"
using namespace ::EventArchitecture;

// Testing code
#include "EventForTestingHandler.hpp"

struct ChannelTests: public ::testing::Test
{
    ChannelTests() :
        handler(),
        router(),
        objectUnderTest(router)
    {
        router.registerHandler(handler);
    };

    EventForTestingHandler handler;
    Router router;
    Channel objectUnderTest;
};

TEST_F(ChannelTests, is_empty_on_initialization)
{
    ASSERT_FALSE(objectUnderTest.hasMore());
}

TEST_F(ChannelTests, can_enqueue_events)
{
    objectUnderTest.enqueue(new EventForTesting{7U});

    ASSERT_TRUE(objectUnderTest.hasMore());
}

TEST_F(ChannelTests, pops_event_off_the_queue_when_delivering_it)
{
    objectUnderTest.enqueue(new EventForTesting{7U});
    objectUnderTest.deliverOne();

    ASSERT_FALSE(objectUnderTest.hasMore());
}

TEST_F(ChannelTests, delivers_events)
{
    auto* event = new EventForTesting{7U};

    objectUnderTest.enqueue(event);
    objectUnderTest.deliverOne();

    ASSERT_TRUE(handler.handledEventWithId(event->id));
}

TEST_F(ChannelTests, delivers_only_one_event_at_a_time)
{
    objectUnderTest.enqueue(new EventForTesting{7U});
    objectUnderTest.enqueue(new EventForTesting{9U});
    objectUnderTest.deliverOne();

    ASSERT_TRUE(objectUnderTest.hasMore());
}

TEST_F(ChannelTests, has_FIFO_queueing_discipline)
{
    auto* event = new EventForTesting{7U};

    objectUnderTest.enqueue(event);
    objectUnderTest.enqueue(new EventForTesting{9U});
    objectUnderTest.deliverOne();

    ASSERT_TRUE(handler.handledEventWithId(event->id));
}
