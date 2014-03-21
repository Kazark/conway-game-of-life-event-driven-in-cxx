#ifndef _EVENTARCHITECTURE_BUS_HPP_
#define _EVENTARCHITECTURE_BUS_HPP_

#include "Channel.hpp"
#include "Router.hpp"
#include "IPublish.hpp"
#include "HeapAllocatorForSubtypesOf.hpp"

namespace EventArchitecture {
	class Bus : public IPublish {
	public:
        Bus();

        template<typename TEvent>
        void registerHandler(IHandle<TEvent>& handler)
        {
            _eventRouter.registerHandler(handler);
            _heapAllocator.registerSubtype<TEvent>();
        }

        void publish(const Event&);

        OutputChannel& outputChannel();

	private:
        Router _eventRouter;
        Channel _channel;
        HeapAllocatorForSubtypesOf<Event> _heapAllocator;
	};
}
#endif
