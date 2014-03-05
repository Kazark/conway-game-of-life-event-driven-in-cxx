#ifndef _EVENTARCHITECTURE_CHANNEL_HPP_
#define _EVENTARCHITECTURE_CHANNEL_HPP_

#include "IHandle.hpp"
#include "Event.hpp"

#include <queue>
#include <list>

namespace EventArchitecture {
	class Channel : public IHandle<Event*> {
	public:
        Channel(IHandle<Event*>&);
        ~Channel();
        void handle(Event*);
        void deliverOne();
        bool hasMore() const;

        template<class TEvent>
        class HandlerWrapper : public IHandle<TEvent> {
        public:
            HandlerWrapper(Channel& channel) : _channel(channel) {}
            void handle(TEvent event) {
                _channel.handle(new TEvent(event));
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
