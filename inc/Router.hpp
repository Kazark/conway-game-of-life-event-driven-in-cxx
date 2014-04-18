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
                auto unpackager = new Unpackager<TEvent>();
                registry[key] = unpackager;
                unpackager->addHandler(handler);
            } else {
                static_cast<Unpackager<TEvent>&>(*registry[key]).addHandler(handler);
            }
        }

        void invokeHandlers(const Event* event)
        {
            auto unpackager = registry.at(typeid(*event));
            unpackager->invokeHandlers(event);
        }

	private:
        class IUnpackage {
        public:
            virtual void invokeHandlers(const Event*) const = 0;
        };

        friend class std::unordered_map<std::type_index, IUnpackage*>;
        std::unordered_map<std::type_index, IUnpackage*> registry;

        template<typename TEvent>
        class Unpackager: public IUnpackage {
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
