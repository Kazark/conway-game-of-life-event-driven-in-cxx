#include "gtest/gtest.h"

// Code under test
#include "DeliverEventsUntilNoneLeft.hpp"
#include "Channel.hpp"
using namespace ::EventArchitecture;

// Testing code
#include "EventForTestingHandler.hpp"

TEST(DeliverEventsUntilNoneLeftTests, delivers_events_of_the_channel_on_at_a_time_until_none_are_left)
{
    EventForTestingHandler handler;
    Router router;
    router.registerHandler(handler);
    Channel channel{router};

    channel.enqueue(new EventForTesting{1U});
    channel.enqueue(new EventForTesting{2U});
    channel.enqueue(new EventForTesting{3U});

    DeliverEventsUntilNoneLeft(channel).run();

    ASSERT_FALSE(channel.hasMore());
}

