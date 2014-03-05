#include "Channel.hpp"
using namespace ::EventArchitecture;

Channel::Channel(IHandle<Event*>& handler) :
    _handler(handler)
{}

Channel::~Channel() {
    while (hasMore()) {
        delete _eventQueue.front();
        _eventQueue.pop();
    };
}

void Channel::handle(Event* event) {
    _eventQueue.push(event);
}

bool Channel::hasMore() const {
    return !_eventQueue.empty();
}
