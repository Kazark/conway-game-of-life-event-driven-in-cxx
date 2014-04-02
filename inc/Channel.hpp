#ifndef _EVENTARCHITECTURE_CHANNEL_HPP_
#define _EVENTARCHITECTURE_CHANNEL_HPP_

#include "Router.hpp"
#include "InputChannel.hpp"
#include "OutputChannel.hpp"
#include "ReferenceType.hpp"

#include <queue>
#include <list>

namespace EventArchitecture {
	class Channel : public InputChannel, public OutputChannel, public ReferenceType {
	public:
        Channel(Router&);
        ~Channel();
        void enqueue(Event*);
        void deliverOne();
        bool hasMore() const;

	private:
        Router& _router;
        std::queue<Event*, std::list<Event*>> _eventQueue;
	};
}
#endif
