#ifndef _ENHANCEDPUBLISHERMOCK_HPP_
#define _ENHANCEDPUBLISHERMOCK_HPP_

// Test code
#include "PublisherMock.hpp"

// Production code
#include "HeapAllocatorForSubtypesOf.hpp"
#include "Event.hpp"

class EnhancedPublisherMock: public PublisherMock {
public:
    EnhancedPublisherMock(EventArchitecture::HeapAllocatorForSubtypesOf<EventArchitecture::Event>& heapAllocator) :
        _heapAllocator(heapAllocator)
    {}

    virtual void publish(const ::EventArchitecture::Event& event) {
        PublisherMock::publish(event);
        _publishedEvents.push_back(_heapAllocator.fromConstRef(event));
    }

    template<typename T>
    int numberOfEventsOfTypeWhere(std::function<bool(const T&)> predicate)
    {
        int count = 0;
        for (auto event : _publishedEvents) {
            if (typeid(event) == typeid(T) && predicate(static_cast<const T&>(event))) {
                ++count;
            }
        }
        return count;
    }

    template<typename T>
    T* lastEventOfType()
    {
        return static_cast<T*>(_publishedEvents.back());
    }

private:
    std::vector<EventArchitecture::Event*> _publishedEvents;
    EventArchitecture::HeapAllocatorForSubtypesOf<EventArchitecture::Event>& _heapAllocator;
};

#endif
