#include "Bus.hpp"
using namespace ::EventArchitecture;

Bus::Bus() :
    _eventRouter(),
    _channel(_eventRouter),
    _heapAllocator()
{}

void Bus::publish(const Event& event) {
    _channel.enqueue(_heapAllocator.fromConstRef(event));
}

OutputChannel& Bus::outputChannel() {
    return _channel;
}
