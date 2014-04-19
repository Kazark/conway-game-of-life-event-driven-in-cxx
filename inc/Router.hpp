#ifndef _EVENTARCHITECTURE_ROUTER_HPP_
#define _EVENTARCHITECTURE_ROUTER_HPP_

// Event Architecture
#include "IHandle.hpp"
#include "Event.hpp"
#include "ReferenceType.hpp"

// C++ Standard libraries
#include <unordered_map>
#include <vector>
#include <typeindex>
#include <stdexcept>

namespace EventArchitecture {
	class Router: public ReferenceType {
	public:
        ~Router() {
            for (auto pair : registry) {
                delete pair.second;
            }
        }

        template<typename TEvent>
        void registerHandler(IHandle<TEvent>& handler)
        {
            std::type_index key = typeid(TEvent);
            if (registry.count(key) == 0) {
                auto publisher = new Publisher<TEvent>();
                registry[key] = publisher;
                publisher->addHandler(handler);
            } else {
                static_cast<Publisher<TEvent>&>(*registry[key]).addHandler(handler);
            }
        }

        void invokeHandlers(const Event* event)
        {
            auto publisher = registry.at(typeid(*event));
            publisher->invokeHandlers(event);
        }

	private:
        class HandlerProxy {
        public:
            virtual ~HandlerProxy() {}
            virtual void invokeHandlers(const Event*) const = 0;
        };

        friend class std::unordered_map<std::type_index, HandlerProxy*>;
        std::unordered_map<std::type_index, HandlerProxy*> registry;

        template<typename TEvent>
        class Publisher: public HandlerProxy {
        public:
            void addHandler(IHandle<TEvent>& handler) {
                _handlers.push_back(&handler);
            }

            void invokeHandlers(const Event* event) const {
                auto unpackagedEvent = static_cast<const TEvent*>(event);
                for (auto handler : _handlers)
                {
                    handler->handle(*unpackagedEvent);
                }
            }
        private:
            std::vector<IHandle<TEvent>*> _handlers;
        };
	};
}
#endif
