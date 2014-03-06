#ifndef _EVENTARCHITECTURE_DELIVEREVENTSUNTILNONELEFT_HPP_
#define _EVENTARCHITECTURE_DELIVEREVENTSUNTILNONELEFT_HPP_

#include "Channel.hpp"

namespace EventArchitecture {
	class DeliverEventsUntilNoneLeft {
	public:
        DeliverEventsUntilNoneLeft(Channel&);
        void run();
	private:
        Channel& _channel;
	};
}
#endif
