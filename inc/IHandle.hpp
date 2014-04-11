#ifndef _EVENTARCHITECTURE_IHANDLE_HPP_
#define _EVENTARCHITECTURE_IHANDLE_HPP_

#include "ReferenceType.hpp"

namespace EventArchitecture {
	template<class TEvent> class IHandle: public virtual ReferenceType {
	public:
        virtual ~IHandle() {}
        virtual void handle(TEvent) = 0;
	};
}
#endif
