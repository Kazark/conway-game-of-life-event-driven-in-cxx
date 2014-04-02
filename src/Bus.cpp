#include "Bus.hpp"
using namespace ::EventArchitecture;

Bus::Bus(Router& router, Channel& channel) :
    _eventRouter(router),
    _channel(channel),
    _heapAllocator()
{}

void Bus::publish(const Event& event) {
    _channel.enqueue(_heapAllocator.fromConstRef(event));
}
