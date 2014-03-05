#ifndef _EVENTARCHITECTURE_CHANNEL_HPP_
#define _EVENTARCHITECTURE_CHANNEL_HPP_

#include "IHandle.hpp"
#include "Event.hpp"

#include <queue>
#include <list>

namespace EventArchitecture {
	class Channel {
	public:
        Channel(IHandle<Event*>&);
        ~Channel();
        void enqueue(Event*);
        void deliverOne();
        bool hasMore() const;

        template<class TEvent>
        class WrapInHandlerFor : public IHandle<TEvent> {
        public:
            WrapInHandlerFor(Channel& channel) : _channel(channel) {}
            void handle(TEvent event) {
                _channel.enqueue(new TEvent(event));
            }
        private:
            Channel& _channel;
        };

	private:
        IHandle<Event*>& _handler;
        std::queue<Event*, std::list<Event*>> _eventQueue;
	};
}
#endif
