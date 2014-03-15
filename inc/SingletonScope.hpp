#ifndef _EVENTARCHITECTURE_SINGLETONSCOPE_HPP_
#define _EVENTARCHITECTURE_SINGLETONSCOPE_HPP_

#include "ReferenceType.hpp"

#include <unordered_map>
#include <typeindex>
#include <functional>
#include <vector>
#include <stdexcept>

namespace EventArchitecture {
	class SingletonScope {
	public:
        ~SingletonScope() {
            for (auto pair : _scope) {
                delete pair.second;
            }
        }

        template<typename T>
        T* getInstanceOf() {
            try
            {
                return dynamic_cast<T*>(_scope.at(typeid(T)));
            }
            catch (std::out_of_range&)
            {
                return nullptr;
            }
        }

        template<typename T>
        void saveInstance(T* instance) {
            _scope[typeid(T)] = instance;
        }

	private:
        std::unordered_map<std::type_index, ReferenceType*> _scope;
	};
}
#endif
