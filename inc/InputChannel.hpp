#ifndef _EVENTARCHITECTURE_INPUTCHANNEL_HPP_
#define _EVENTARCHITECTURE_INPUTCHANNEL_HPP_

#include "Event.hpp"

namespace EventArchitecture {
	class InputChannel {
	public:
        virtual ~InputChannel() {}
        virtual void enqueue(Event*) = 0;
	};
}
#endif
