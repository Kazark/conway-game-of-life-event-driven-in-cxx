#ifndef _EVENTARCHITECTURE_HEAPALLOCATORFORSUBTYPESOF_HPP_
#define _EVENTARCHITECTURE_HEAPALLOCATORFORSUBTYPESOF_HPP_

#include <functional>
#include <unordered_map>
#include <typeindex>
#include <stdexcept>

namespace EventArchitecture {
    template<typename TBase>
	class HeapAllocatorForSubtypesOf {
	public:
        template<typename TChild>
        void registerSubtype() {
            _copiers[typeid(TChild)] = [](const TBase& obj) { return new TChild(static_cast<const TChild&>(obj)); };
        }

        TBase* fromConstRef(const TBase& object) {
            try {
                return _copiers.at(typeid(object))(object);
            } catch (std::out_of_range&) {
                return nullptr;
            }
        }

	private:
        std::unordered_map<std::type_index, std::function<TBase*(const TBase&)>> _copiers;
	};
}
#endif
