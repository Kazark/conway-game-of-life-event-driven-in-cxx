#include "gtest/gtest.h"

// Code under test
#include "Channel.hpp"
using namespace ::EventArchitecture;

// Testing code
#include "EventForTestingHandler.hpp"

TEST(ChannelTests, is_empty_on_initialization)
{
    EventPointerHandlerForTesting handler;

    Channel objectUnderTest{handler};

    ASSERT_FALSE(objectUnderTest.hasMore());
}

TEST(ChannelTests, can_enqueue_events)
{
    EventPointerHandlerForTesting handler;
    auto* event = new EventForTesting{7U};
    Channel objectUnderTest{handler};

    objectUnderTest.handle(event);

    ASSERT_TRUE(objectUnderTest.hasMore());
}

TEST(ChannelTests, pops_event_off_the_queue_when_delivering_it)
{
    EventPointerHandlerForTesting handler;
    auto* event = new EventForTesting{7U};
    Channel objectUnderTest{handler};

    objectUnderTest.handle(event);
    objectUnderTest.deliverOne();

    ASSERT_FALSE(objectUnderTest.hasMore());
}
