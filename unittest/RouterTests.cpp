#include "gtest/gtest.h"

// Code Under Test
#include "Router.hpp"
using namespace ::EventArchitecture;

// Testing code
#include "EventForTestingHandler.hpp"

TEST(RouterTests, registers_and_invokes_handlers)
{
    EventForTesting event{3U};
    EventForTestingHandler handler;
    Router objectUnderTest;

    objectUnderTest.registerHandler(handler);
    objectUnderTest.handle(static_cast<Event*>(&event));

    ASSERT_TRUE(handler.handledEventWithId(event.id));
}
