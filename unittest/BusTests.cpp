#include "gtest/gtest.h"

#include "Bus.hpp"
using namespace ::EventArchitecture;

#include "EventForTestingHandler.hpp"

TEST(BusTests, smoke_test)
{
    Router router;
    Channel channel{router};
    Bus objectUnderTest{router, channel};
    EventForTestingHandler handler;
    EventForTesting event{3};

    objectUnderTest.registerHandler(handler);
    objectUnderTest.publish(event);
    channel.deliverOne();

    handler.handledEventWithId(event.id);
}

TEST(BusTests, does_not_enqueue_anything_on_channel_when_event_not_registered)
{
    Router router;
    Channel channel{router};
    Bus objectUnderTest{router, channel};
    EventForTestingHandler handler;
    EventForTesting event{3};

    objectUnderTest.registerHandler(handler);
    objectUnderTest.publish(event);
    channel.deliverOne();

    handler.handledEventWithId(event.id);
}
