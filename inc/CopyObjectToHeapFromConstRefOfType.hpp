
#ifndef _EVENTARCHITECTURE_COPYOBJECTTOHEAPFROMCONSTREFOFTYPE_HPP_
#define _EVENTARCHITECTURE_COPYOBJECTTOHEAPFROMCONSTREFOFTYPE_HPP_
namespace EventArchitecture {
    template<typename TConcrete>
	class CopyObjectToHeapFromConstRefOfType {
	public:
        template<typename TAbstract>
        TAbstract* operator()(const TAbstract& object) const {
            return new TConcrete(static_cast<const TConcrete&>(object));
        }
	private:
	};
}
#endif
