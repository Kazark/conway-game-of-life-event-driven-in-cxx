#ifndef _PUBLISHERMOCK_HPP_
#define _PUBLISHERMOCK_HPP_

#include "HeapAllocatorForSubtypesOf.hpp"
#include "Event.hpp"
#include "IPublish.hpp"

#include <vector>
#include <algorithm>
#include <typeindex>

class PublisherMock: public ::EventArchitecture::IPublish {
public:
    PublisherMock(EventArchitecture::HeapAllocatorForSubtypesOf<EventArchitecture::Event>& heapAllocator) :
        _heapAllocator(heapAllocator)
    {}

    ~PublisherMock() {
        for (auto event : _publishedEvents) {
            delete event;
        }
    }

    void publish(const ::EventArchitecture::Event& event) {
        _publishedEventTypes.push_back(typeid(event));
        _publishedEvents.push_back(_heapAllocator.fromConstRef(event));
    }

    template<typename T>
    int numberOfEventsOfType() {
        return std::count(_publishedEventTypes.begin(), _publishedEventTypes.end(), typeid(T));
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
        if (_publishedEvents.size() == 0)
        {
            return nullptr;
        }
        return static_cast<T*>(_publishedEvents.back());
    }

    bool any() const {
        return _publishedEvents.size() > 0;
    }

private:
    std::vector<std::type_index> _publishedEventTypes;
    std::vector<EventArchitecture::Event*> _publishedEvents;
    EventArchitecture::HeapAllocatorForSubtypesOf<EventArchitecture::Event>& _heapAllocator;
};

#endif
