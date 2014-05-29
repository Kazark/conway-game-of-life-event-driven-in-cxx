#include "HasGameReachedTerminalState.hpp"
#include "GenerationCompleted.hpp"
#include "StasisReached.hpp"
using namespace ConwayGameOfLife;
using namespace EventArchitecture;

HasGameReachedTerminalState::HasGameReachedTerminalState(::EventArchitecture::IPublish& bus) :
    _bus(bus),
    _previousGrid()
{}

void HasGameReachedTerminalState::handle(GameInitiated event) {
    _previousGrid = event.grid;
    _bus.publish(GenerationCompleted(_previousGrid));
}

void HasGameReachedTerminalState::handle(CellStateChangesAggregated event) {
    if (_previousGrid == event.aggregateState)
    {
        _bus.publish(StasisReached());
    }
    else
    {
        _bus.publish(GenerationCompleted(event.aggregateState));
    }
}
