#ifndef _EVENTARCHITECTURE_UNPACKAGER_HPP_
#define _EVENTARCHITECTURE_UNPACKAGER_HPP_

#include "IUnpackage.hpp"
#include "IHandle.hpp"

namespace EventArchitecture {
    template<typename TEvent>
	class Unpackager: public IUnpackage {
	public:
        Unpackager(IHandle<TEvent>& handler) :
            _handler(handler)
        {}

        void invokeHandlerFor(Event* event) const {
            auto unpackagedEvent = static_cast<TEvent*>(event);
            _handler.handle(*unpackagedEvent);
        }
	private:
        IHandle<TEvent>& _handler;
	};
}
#endif
