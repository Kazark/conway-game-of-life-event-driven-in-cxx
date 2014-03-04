#include "Channel.hpp"
using namespace ::EventArchitecture;

Channel::Channel(IHandle<Event*>& handler) :
    _handler(handler)
{}

void Channel::handle(Event* event) {
}
