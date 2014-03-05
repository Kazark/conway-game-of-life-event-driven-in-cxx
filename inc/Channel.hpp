#ifndef _EVENTARCHITECTURE_CHANNEL_HPP_
#define _EVENTARCHITECTURE_CHANNEL_HPP_

#include "IHandle.hpp"
#include "Event.hpp"

namespace EventArchitecture {
	class Channel : public IHandle<const Event&> {
	public:
        Channel(IHandle<Event*>&);
        void handle(const Event&);
        bool hasMore() const;

	private:
        IHandle<Event*>& _handler;
	};
}
#endif
