#ifndef _EVENTARCHITECTURE_BUS_HPP_
#define _EVENTARCHITECTURE_BUS_HPP_

#include "Channel.hpp"
#include "Router.hpp"
#include "IPublish.hpp"
#include "CopyObjectToHeapFromConstRefOfType.hpp"

#include <functional>
#include <unordered_map>

namespace EventArchitecture {
	class Bus : public IPublish {
	public:
        Bus();

        template<typename TEvent>
        void registerHandler(IHandle<TEvent>& handler)
        {
            _eventRouter.registerHandler(handler);
            _copiers[typeid(TEvent)] = CopyObjectToHeapFromConstRefOfType<TEvent>();
        }

        void publish(const Event&);

        OutputChannel& outputChannel();

	private:
        Router _eventRouter;
        Channel _channel;
        std::unordered_map<std::type_index, std::function<Event*(const Event&)>> _copiers;
	};
}
#endif
