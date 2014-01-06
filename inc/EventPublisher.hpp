#ifndef _EVENTARCHITECTURE_EVENTPUBLISHER_HPP_
#define _EVENTARCHITECTURE_EVENTPUBLISHER_HPP_

#include "IHandle.hpp"

namespace EventArchitecture {
	template<class TEvent> class EventPublisher {
	public:
        void AddSubscriber(const IHandle<TEvent>*);
        void PublishEvent(const TEvent);
	};
}
#endif
