#include "Bus.hpp"
using namespace ::EventArchitecture;

Bus::Bus(Router& router, Channel& channel, HeapAllocatorForSubtypesOf<Event>& heapAllocator) :
    _eventRouter(router),
    _channel(channel),
    _heapAllocator(heapAllocator)
{}

void Bus::publish(const Event& event) {
    auto eventOnHeap = _heapAllocator.fromConstRef(event);
    if (eventOnHeap == nullptr) {
        return;
    }
    _channel.enqueue(eventOnHeap);
}
