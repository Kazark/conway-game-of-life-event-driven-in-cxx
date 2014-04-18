#include "Channel.hpp"
using namespace ::EventArchitecture;

Channel::Channel(Router& router) :
    _router(router)
{}

Channel::~Channel() {
    while (hasMore()) {
        delete _eventQueue.front();
        _eventQueue.pop();
    };
}

void Channel::enqueue(Event* event) {
    _eventQueue.push(event);
}

void Channel::deliverOne() {
    auto* event = _eventQueue.front();
    _router.invokeHandlers(event);
    _eventQueue.pop();
    delete event;
}

bool Channel::hasMore() const {
    return !_eventQueue.empty();
}
