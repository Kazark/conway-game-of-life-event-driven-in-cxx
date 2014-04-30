#include "HasGameReachedTerminalState.hpp"
#include "GenerationCompleted.hpp"
using namespace ConwayGameOfLife;
using namespace EventArchitecture;

HasGameReachedTerminalState::HasGameReachedTerminalState(::EventArchitecture::IPublish& bus) :
    _bus(bus)
{}

void HasGameReachedTerminalState::handle(GameInitiated inEvent) {
    _bus.publish(GenerationCompleted(inEvent.grid));
}

void HasGameReachedTerminalState::handle(CellStateChangesAggregated) {
}
