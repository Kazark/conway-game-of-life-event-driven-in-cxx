#include "Channel.hpp"
using namespace ::EventArchitecture;

Channel::Channel(IHandle<Event*>& handler) :
    _handler(handler)
{}

void Channel::handle(const Event&/* event*/) {
}

bool Channel::hasMore() const {
    return false;
}
