#ifndef _EVENTARCHITECTURE_HEAPALLOCATORFORSUBTYPESOF_HPP_
#define _EVENTARCHITECTURE_HEAPALLOCATORFORSUBTYPESOF_HPP_

#include "ReferenceType.hpp"

#include <functional>
#include <unordered_map>
#include <typeindex>
#include <stdexcept>

namespace EventArchitecture {
    template<typename TBase>
	class HeapAllocatorForSubtypesOf: public ReferenceType {
	public:
        template<typename TChild>
        void registerSubtype() {
            _copiers[typeid(TChild)] = [](const TBase& obj) { return new TChild(static_cast<const TChild&>(obj)); };
        }

        TBase* fromConstRef(const TBase& object) {
            std::type_index key = typeid(object);
            if (_copiers.count(key) == 0)
            {
                return nullptr;
            }
            auto copy = _copiers.at(key);
            return copy(object);
        }

	private:
        std::unordered_map<std::type_index, std::function<TBase*(const TBase&)>> _copiers;
	};
}
#endif
