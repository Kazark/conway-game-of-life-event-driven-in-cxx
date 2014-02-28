#include "gtest/gtest.h"

// Code Under Test
#include "Router.hpp"
using namespace ::EventArchitecture;

// Testing code
#include "EventForTestingHandler.hpp"

TEST(EventRouterTests, registers_and_invokes_handlers)
{
    auto event = EventForTesting(3U);
    EventForTestingHandler handler;
    Router objectUnderTest;

    objectUnderTest.registerHandler(handler);
    objectUnderTest.invokeHandler(static_cast<Event*>(&event));

    ASSERT_TRUE(handler.handledEventWithId(event.id));
}