#include "gtest/gtest.h"

#include "Bus.hpp"
using namespace ::EventArchitecture;

#include "EventForTestingHandler.hpp"

TEST(BusTests, smoke_test)
{
    Bus objectUnderTest;
    EventForTestingHandler handler;
    EventForTesting event{3};

    objectUnderTest.registerHandler(handler);
    objectUnderTest.publish(event);
    objectUnderTest.outputChannel().deliverOne();

    handler.handledEventWithId(event.id);
}

