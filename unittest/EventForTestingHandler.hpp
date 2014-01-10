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
#endif
