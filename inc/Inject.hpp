#ifndef _EVENTARCHITECTURE_INJECT_HPP_
#define _EVENTARCHITECTURE_INJECT_HPP_

#include "LazyInitContainer.hpp"

namespace EventArchitecture {
    template<typename... TDependencies>
	struct Inject {
        template<typename T>
        static T* Into(LazyInitContainer& container) {
            return new T(*container.getInstanceOf<TDependencies>()...);
        }
	};
}
#endif
