#ifndef _EVENTARCHITECTURE_ROUTER_HPP_
#define _EVENTARCHITECTURE_ROUTER_HPP_

// Event Architecture
#include "IHandle.hpp"
#include "Event.hpp"
#include "ReferenceType.hpp"

// C++ Standard libraries
#include <unordered_map>
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
            registry[typeid(TEvent)] = new Unpackager<TEvent>(handler);
        }
        
        void invokeHandler(const Event* event)
        {
            auto unpackager = registry.at(typeid(*event));
            unpackager->invokeHandler(event);
        }

	private:
        class IUnpackage {
        public:
            virtual void invokeHandler(const Event*) const = 0;
        };

        friend class std::unordered_map<std::type_index, IUnpackage*>;
        std::unordered_map<std::type_index, IUnpackage*> registry;

        template<typename TEvent>
        class Unpackager: public IUnpackage {
        public:
            Unpackager(IHandle<TEvent>& handler) :
                _handler(handler)
            {}

            void invokeHandler(const Event* event) const {
                auto unpackagedEvent = static_cast<const TEvent*>(event);
                _handler.handle(*unpackagedEvent);
            }
        private:
            IHandle<TEvent>& _handler;
        };
	};
}
#endif
