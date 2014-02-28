#ifndef _EVENTARCHITECTURE_IUNPACKAGE_HPP_
#define _EVENTARCHITECTURE_IUNPACKAGE_HPP_

#include "Event.hpp"

namespace EventArchitecture {
	class IUnpackage {
    public:
        virtual void invokeHandlerFor(Event*) const = 0;
	};
}
#endif
