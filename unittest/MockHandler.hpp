#ifndef _MOCKHANDLER_HPP_
#define _MOCKHANDLER_HPP_

// Production code
#include "IHandle.hpp"
// Testing code
#include "EventForTesting.hpp"
// C++
#include <unordered_set>

template<typename TEvent>
class MockHandler: public EventArchitecture::IHandle<TEvent> {
public:
    void handle(TEvent eventData)
    {
        handledEvent = eventData;
        wasCalled = true;
    }

    bool wasCalled;
    TEvent handledEvent;
};
#endif
