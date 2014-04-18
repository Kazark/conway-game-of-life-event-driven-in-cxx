#include "gtest/gtest.h"

// Code Under Test
#include "Router.hpp"
using namespace ::EventArchitecture;

// Testing code
#include "EventForTestingHandler.hpp"

TEST(RouterTests, throws_error_if_no_handler_registered_for_event)
{
    EventForTesting event{3U};

    ASSERT_THROW(Router().invokeHandlers(&event), std::out_of_range);
}

TEST(RouterTests, can_register_and_invoke_single_handler)
{
    EventForTesting event{3U};
    EventForTestingHandler handler;
    Router objectUnderTest;

    objectUnderTest.registerHandler(handler);
    objectUnderTest.invokeHandlers(static_cast<Event*>(&event));

    ASSERT_TRUE(handler.handledEventWithId(event.id));
}

TEST(RouterTests, invokes_all_registered_handlers_for_an_event)
{
    EventForTesting event{7U};
    EventForTestingHandler handler1;
    EventForTestingHandler handler2;
    Router objectUnderTest;

    objectUnderTest.registerHandler(handler1);
    objectUnderTest.registerHandler(handler2);
    objectUnderTest.invokeHandlers(&event);

    ASSERT_TRUE(handler1.handledEventWithId(event.id));
    ASSERT_TRUE(handler2.handledEventWithId(event.id));
}
