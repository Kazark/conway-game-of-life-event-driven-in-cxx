#ifndef _EVENTARCHITECTURE_CHANNEL_HPP_
#define _EVENTARCHITECTURE_CHANNEL_HPP_

#include "IHandle.hpp"
#include "InputChannel.hpp"
#include "OutputChannel.hpp"

#include <queue>
#include <list>

namespace EventArchitecture {
	class Channel : public InputChannel, public OutputChannel {
	public:
        Channel(IHandle<const Event*>&);
        ~Channel();
        void enqueue(Event*);
        void deliverOne();
        bool hasMore() const;

        template<class TEvent>
        class WrapInHandlerFor : public IHandle<const TEvent&> {
        public:
            WrapInHandlerFor(Channel& channel) : _channel(channel) {}
            void handle(const TEvent& event) {
                _channel.enqueue(new TEvent(event));
            }
        private:
            Channel& _channel;
        };

	private:
        IHandle<const Event*>& _handler;
        std::queue<Event*, std::list<Event*>> _eventQueue;
	};
}
#endif
