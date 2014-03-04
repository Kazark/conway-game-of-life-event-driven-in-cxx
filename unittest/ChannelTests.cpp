#include "gtest/gtest.h"

// Code under test
#include "Channel.hpp"
using namespace ::EventArchitecture;

// Testing code
#include "EventForTestingHandler.hpp"

TEST(ChannelTests, test)
{
    EventPointerHandlerForTesting handler;
    EventForTesting event{7U};

    Channel objectUnderTest{handler};

    objectUnderTest.handle(&event);
}
