#include "gtest/gtest.h"

#include "Bus.hpp"
using namespace ::EventArchitecture;

#include "EventForTestingHandler.hpp"

struct BusTests: public ::testing::Test
{
    BusTests() :
        router(),
        channel(router),
        objectUnderTest(router, channel)
    {
    };

    Router router;
    Channel channel;
    Bus objectUnderTest;
};

TEST_F(BusTests, smoke_test)
{
    EventForTestingHandler handler;
    EventForTesting event{3};

    objectUnderTest.registerHandler(handler);
    objectUnderTest.publish(event);
    channel.deliverOne();

    handler.handledEventWithId(event.id);
}

TEST_F(BusTests, does_not_enqueue_anything_on_channel_when_no_event_handler_registered_for_type)
{
    EventForTesting event{3};

    objectUnderTest.publish(event);

    ASSERT_FALSE(channel.hasMore());
}
