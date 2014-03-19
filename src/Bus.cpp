#include "Bus.hpp"
using namespace ::EventArchitecture;

Bus::Bus() :
    _eventRouter(),
    _channel(_eventRouter),
    _copiers()
{}

void Bus::publish(const Event& event) {
    _channel.enqueue(_copiers.at(typeid(event))(event));
}

OutputChannel& Bus::outputChannel() {
    return _channel;
}
