#ifndef _EVENTARCHITECTURE_CHANNEL_HPP_
#define _EVENTARCHITECTURE_CHANNEL_HPP_

#include "IHandle.hpp"
#include "InputChannel.hpp"
#include "OutputChannel.hpp"
#include "ReferenceType.hpp"

#include <queue>
#include <list>

namespace EventArchitecture {
	class Channel : public InputChannel, public OutputChannel, public ReferenceType {
	public:
        Channel(IHandle<const Event*>&);
        ~Channel();
        void enqueue(Event*);
        void deliverOne();
        bool hasMore() const;

	private:
        IHandle<const Event*>& _handler;
        std::queue<Event*, std::list<Event*>> _eventQueue;
	};
}
#endif
