#ifndef _EVENTARCHITECTURE_LAZYINITCONTAINER_HPP_
#define _EVENTARCHITECTURE_LAZYINITCONTAINER_HPP_

#include "SingletonScope.hpp"

#include <unordered_map>
#include <typeindex>
#include <functional>

namespace EventArchitecture {
	class LazyInitContainer {
	public:
        template<typename T>
        T& getInstanceOf() {
            auto instance = _scope.getInstanceOf<T>();
            if (instance == nullptr) {
                instance = dynamic_cast<T*>(_injectors.at(typeid(T))(*this));
                _scope.saveInstance(instance);
            }
            return *instance;
        }

        template<typename T>
        void registerInjector(std::function<T*(LazyInitContainer&)> injector) {
            _injectors[typeid(T)] = injector;
        }

	private:
        SingletonScope _scope;
        std::unordered_map<std::type_index, std::function<ReferenceType*(LazyInitContainer&)>> _injectors;
	};
}
#endif
