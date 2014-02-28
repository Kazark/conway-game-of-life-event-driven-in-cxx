#include "gtest/gtest.h"

// Code Under Test
#include "Unpackager.hpp"
using namespace ::EventArchitecture;

// Testing code
#include "EventForTestingHandler.hpp"

TEST(UnpackagerTests, invokes_the_handler_with_the_event_cast_to_its_concrete_type)
{
    auto event = EventForTesting(3U);
    EventForTestingHandler handler;
    auto unpackager = Unpackager<EventForTesting>(handler);

    unpackager.invokeHandlerFor(static_cast<Event*>(&event));

    ASSERT_TRUE(handler.handledEventWithId(event.id));
}
