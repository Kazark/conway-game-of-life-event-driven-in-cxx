#ifndef _EVENTARCHITECTURE_CHANNEL_HPP_
#define _EVENTARCHITECTURE_CHANNEL_HPP_

#include "IHandle.hpp"
#include "Event.hpp"

#include <queue>
#include <list>

namespace EventArchitecture {
	class Channel : public IHandle<Event*> {
	public:
        Channel(IHandle<Event*>&);
        ~Channel();
        void handle(Event*);
        bool hasMore() const;

	private:
        IHandle<Event*>& _handler;
        std::queue<Event*, std::list<Event*>> _eventQueue;
	};
}
#endif
