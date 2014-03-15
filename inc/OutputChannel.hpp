#ifndef _EVENTARCHITECTURE_OUTPUTCHANNEL_HPP_
#define _EVENTARCHITECTURE_OUTPUTCHANNEL_HPP_
namespace EventArchitecture {
	class OutputChannel {
	public:
        virtual ~OutputChannel() {}
        virtual void deliverOne() = 0;
        virtual bool hasMore() const = 0;
	};
}
#endif
