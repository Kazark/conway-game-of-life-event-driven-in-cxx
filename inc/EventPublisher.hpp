#ifndef _EVENTARCHITECTURE_EVENTPUBLISHER_HPP_
#define _EVENTARCHITECTURE_EVENTPUBLISHER_HPP_

#include "IHandle.hpp"
#include <vector>

namespace EventArchitecture {
	template<class TEvent> class EventPublisher {
	public:
        void addSubscriber(IHandle<TEvent>* subscriber)
        {
            subscribers.push_back(subscriber);
        }
        void publishEvent(TEvent event)
        {
            for (auto subscriber : subscribers)
            {
                subscriber->handle(event);
            }
        }

    private:
        std::vector<IHandle<TEvent>*> subscribers;
	};
}
#endif
