#ifndef _EVENTFORTESTINGHANDLER_HPP_
#define _EVENTFORTESTINGHANDLER_HPP_

// Production code
#include "IHandle.hpp"
// Testing code
#include "EventForTesting.hpp"
// C++
#include <unordered_set>

class EventForTestingHandler: public EventArchitecture::IHandle<EventForTesting> {
public:
    void handle(EventForTesting eventData)
    {
        eventIDs.insert(eventData.id);
    }

    bool handledEventWithId(unsigned id)
    {
        return eventIDs.find(id) != eventIDs.end();
    }

private:
    std::unordered_set<unsigned> eventIDs;
};

class EventPointerHandlerForTesting : public ::EventArchitecture::IHandle<EventArchitecture::Event*> {
public:
    void handle(::EventArchitecture::Event* event) {
        innerHandler.handle(*dynamic_cast<EventForTesting*>(event));
    }

    bool handledEventWithId(unsigned id)
    {
        return innerHandler.handledEventWithId(id);
    }

private:
    EventForTestingHandler innerHandler;
};

#endif
