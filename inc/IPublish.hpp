#ifndef _EVENTARCHITECTURE_IPUBLISH_HPP_
#define _EVENTARCHITECTURE_IPUBLISH_HPP_

#include "Event.hpp"
#include "ReferenceType.hpp"

namespace EventArchitecture {
	class IPublish: public ReferenceType {
	public:
        virtual ~IPublish() {}
        virtual void publish(const Event&) = 0;
	private:
	};
}
#endif
