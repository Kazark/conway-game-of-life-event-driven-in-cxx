#include "gtest/gtest.h"

// Code Under Test
#include "EventPublisher.hpp"
using namespace ::EventArchitecture;

// Testing code
#include "EventForTestingHandler.hpp"

TEST(EventPublisherTests, publish_does_nothing_when_nothing_is_subscribed)
{
    EventPublisher<int> publisher;

    publisher.publishEvent(1);
}

TEST(EventPublisherTests, can_add_and_publish_to_subscribers)
{
    EventForTestingHandler subscriber1;
    EventForTestingHandler subscriber2;
    EventPublisher<EventForTesting> publisher;

    publisher.addSubscriber(&subscriber1);
    publisher.addSubscriber(&subscriber2);
    publisher.publishEvent(EventForTesting(7));

    EXPECT_TRUE(subscriber1.handledEventWithId(7));
    EXPECT_TRUE(subscriber2.handledEventWithId(7));
}
