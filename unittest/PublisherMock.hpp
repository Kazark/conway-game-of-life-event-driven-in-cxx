#ifndef _PUBLISHERMOCK_HPP_
#define _PUBLISHERMOCK_HPP_

#include "IPublish.hpp"
#include <vector>
#include <algorithm>
#include <typeindex>

class PublisherMock: public ::EventArchitecture::IPublish {
public:
    virtual void publish(const ::EventArchitecture::Event& event) {
        _publishedEventTypes.push_back(typeid(event));
    }

    template<typename T>
    int numberOfEventsOfType() {
        return std::count(_publishedEventTypes.begin(), _publishedEventTypes.end(), typeid(T));
    }

private:
    std::vector<std::type_index> _publishedEventTypes;
};

#endif
