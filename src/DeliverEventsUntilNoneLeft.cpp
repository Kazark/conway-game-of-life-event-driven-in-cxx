#include "DeliverEventsUntilNoneLeft.hpp"
using namespace ::EventArchitecture;

DeliverEventsUntilNoneLeft::DeliverEventsUntilNoneLeft(OutputChannel& channel) :
    _channel(channel)
{}

void DeliverEventsUntilNoneLeft::run() {
    while (_channel.hasMore()) {
        _channel.deliverOne();
    }
}
