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
    Channel objectUnderTest{handler};

    objectUnderTest.enqueue(new EventForTesting{7U});

    ASSERT_TRUE(objectUnderTest.hasMore());
}

TEST(ChannelTests, pops_event_off_the_queue_when_delivering_it)
{
    EventPointerHandlerForTesting handler;
    Channel objectUnderTest{handler};

    objectUnderTest.enqueue(new EventForTesting{7U});
    objectUnderTest.deliverOne();

    ASSERT_FALSE(objectUnderTest.hasMore());
}

TEST(ChannelTests, delivers_events)
{
    EventPointerHandlerForTesting handler;
    auto* event = new EventForTesting{7U};
    Channel objectUnderTest{handler};

    objectUnderTest.enqueue(event);
    objectUnderTest.deliverOne();

    ASSERT_TRUE(handler.handledEventWithId(event->id));
}

TEST(ChannelTests, delivers_only_one_event_at_a_time)
{
    EventPointerHandlerForTesting handler;
    Channel objectUnderTest{handler};

    objectUnderTest.enqueue(new EventForTesting{7U});
    objectUnderTest.enqueue(new EventForTesting{9U});
    objectUnderTest.deliverOne();

    ASSERT_TRUE(objectUnderTest.hasMore());
}

TEST(ChannelTests, has_FIFO_queueing_discipline)
{
    EventPointerHandlerForTesting handler;
    auto* event = new EventForTesting{7U};
    Channel objectUnderTest{handler};

    objectUnderTest.enqueue(event);
    objectUnderTest.enqueue(new EventForTesting{9U});
    objectUnderTest.deliverOne();

    ASSERT_TRUE(handler.handledEventWithId(event->id));
}

TEST(ChannelTests, has_subclass_to_wrap_it_in_a_handler)
{
    EventPointerHandlerForTesting handler;
    Channel objectUnderTest{handler};
    EventForTesting event{7U};
    Channel::WrapInHandlerFor<EventForTesting> handlerWrapper{objectUnderTest};

    handlerWrapper.handle(event);
    objectUnderTest.deliverOne();

    ASSERT_TRUE(handler.handledEventWithId(event.id));
}
