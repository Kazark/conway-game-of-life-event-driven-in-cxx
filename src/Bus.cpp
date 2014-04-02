#include "Bus.hpp"
using namespace ::EventArchitecture;

Bus::Bus(Router& router, Channel& channel) :
    _eventRouter(router),
    _channel(channel),
    _heapAllocator()
{}

void Bus::publish(const Event& event) {
    auto eventOnHeap = _heapAllocator.fromConstRef(event);
    if (eventOnHeap == nullptr) {
        return;
    }
    _channel.enqueue(eventOnHeap);
}
