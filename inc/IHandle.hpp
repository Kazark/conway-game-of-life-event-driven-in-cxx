#ifndef _EVENTARCHITECTURE_ISUBSCRIBETO_HPP_
#define _EVENTARCHITECTURE_IHANDLE_HPP_
namespace EventArchitecture {
	template<class TEvent> class IHandle {
	public:
        virtual ~IHandle() = 0;
        virtual void handle(const TEvent) = 0;
	};
}
#endif
