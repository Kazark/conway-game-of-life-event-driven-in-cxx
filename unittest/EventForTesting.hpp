#ifndef _EVENTFORTESTING_HPP_
#define _EVENTFORTESTING_HPP_

#include "Event.hpp"

struct EventForTesting : public EventArchitecture::Event {
    EventForTesting(unsigned id) : id(id) {}
    const unsigned id;
};
#endif
