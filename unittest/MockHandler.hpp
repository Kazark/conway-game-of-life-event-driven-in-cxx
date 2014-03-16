#ifndef _MOCKHANDLER_HPP_
#define _MOCKHANDLER_HPP_

// Production code
#include "IHandle.hpp"
// C++
#include <vector>

template<typename TEvent>
class MockHandler: public ::EventArchitecture::IHandle<TEvent> {
public:
    void handle(TEvent eventData)
    {
        handledEvents.push_back(eventData);
        wasCalled = true;
    }

    bool wasCalled;
    std::vector<TEvent> handledEvents;
};
#endif
