#ifndef _EVENTARCHITECTURE_IHANDLE_HPP_
#define _EVENTARCHITECTURE_IHANDLE_HPP_
namespace EventArchitecture {
	template<class TEvent> class IHandle {
	public:
        virtual void handle(TEvent) = 0;
	};
}
#endif
