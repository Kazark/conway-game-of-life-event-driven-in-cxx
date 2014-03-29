#ifndef _EVENTARCHITECTURE_DELIVEREVENTSUNTILNONELEFT_HPP_
#define _EVENTARCHITECTURE_DELIVEREVENTSUNTILNONELEFT_HPP_

#include "OutputChannel.hpp"
#include "ReferenceType.hpp"

namespace EventArchitecture {
	class DeliverEventsUntilNoneLeft: public ReferenceType {
	public:
        DeliverEventsUntilNoneLeft(OutputChannel&);
        void run();
	private:
        OutputChannel& _channel;
	};
}
#endif
