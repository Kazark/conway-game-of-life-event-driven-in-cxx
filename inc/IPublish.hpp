#ifndef _EVENTARCHITECTURE_IPUBLISH_HPP_
#define _EVENTARCHITECTURE_IPUBLISH_HPP_

#include "Event.hpp"

namespace EventArchitecture {
	class IPublish {
	public:
        virtual ~IPublish() {};
        virtual void publish(const Event&) = 0;
	private:
	};
}
#endif
