#include "gtest/gtest.h"

// Code Under Test
#include "Router.hpp"
using namespace ::EventArchitecture;

// Testing code
#include "EventForTestingHandler.hpp"

TEST(RouterTests, throws_error_if_no_handler_registered_for_event)
{
    EventForTesting event{3U};

    ASSERT_THROW(Router().invokeHandler(&event), std::out_of_range);
}

TEST(RouterTests, registers_and_invokes_handlers)
{
    EventForTesting event{3U};
    EventForTestingHandler handler;
    Router objectUnderTest;

    objectUnderTest.registerHandler(handler);
    objectUnderTest.invokeHandler(static_cast<Event*>(&event));

    ASSERT_TRUE(handler.handledEventWithId(event.id));
}
