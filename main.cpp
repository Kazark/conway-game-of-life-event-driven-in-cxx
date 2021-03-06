#include "Bus.hpp"
#include "LazyInitContainer.hpp"
#include "Inject.hpp"
#include "DeliverEventsUntilNoneLeft.hpp"
using namespace ::EventArchitecture;

#include "InitiateGameWithRandomGrid.hpp"
#include "CountLivingNeighbors.hpp"
#include "DetermineNextCellState.hpp"
#include "AggregateCellStateChanges.hpp"
#include "HasGameReachedTerminalState.hpp"
#include "PrintGeneration.hpp"
#include "OutputPlaintextCells.hpp"
using namespace ::ConwayGameOfLife;

#include <iostream>

int main(/*int argCount, char* argArray[]*/)
{
    LazyInitContainer container;
    container.registerInjector<HeapAllocatorForSubtypesOf<Event>>(Inject<>::Into<HeapAllocatorForSubtypesOf<Event>>);
    container.registerInjector<Router>(Inject<>::Into<Router>);
    container.registerInjector<Channel>(Inject<Router>::Into<Channel>);
    container.registerInjector<Bus>(Inject<Router, Channel, HeapAllocatorForSubtypesOf<Event>>::Into<Bus>);
    container.registerInjector<DeliverEventsUntilNoneLeft>(Inject<Channel>::Into<DeliverEventsUntilNoneLeft>);

    container.registerInjector<InitiateGameWithRandomGrid>(Inject<Bus>::Into<InitiateGameWithRandomGrid>);
    container.registerInjector<CountLivingNeighbors>(Inject<Bus>::Into<CountLivingNeighbors>);
    container.registerInjector<DetermineNextCellState>(Inject<Bus>::Into<DetermineNextCellState>);
    container.registerInjector<AggregateCellStateChanges>(Inject<Bus>::Into<AggregateCellStateChanges>);
    container.registerInjector<HasGameReachedTerminalState>(Inject<Bus>::Into<HasGameReachedTerminalState>);
    container.registerInjector<PrintGeneration>(Inject<OutputPlaintextCells>::Into<PrintGeneration>);

    container.registerInjector<OutputPlaintextCells>([](LazyInitContainer&) { return new OutputPlaintextCells(std::cout); });

    auto& bus = container.getInstanceOf<Bus>();
    bus.registerHandler(container.getInstanceOf<CountLivingNeighbors>());
    bus.registerHandler(container.getInstanceOf<DetermineNextCellState>());
    bus.registerHandler<GameInitiated>(container.getInstanceOf<AggregateCellStateChanges>());
    bus.registerHandler<CellStateChanged>(container.getInstanceOf<AggregateCellStateChanges>());
    bus.registerHandler<GameInitiated>(container.getInstanceOf<HasGameReachedTerminalState>());
    bus.registerHandler<CellStateChangesAggregated>(container.getInstanceOf<HasGameReachedTerminalState>());
    bus.registerHandler(container.getInstanceOf<PrintGeneration>());

    container.getInstanceOf<InitiateGameWithRandomGrid>().initiate();
    auto& mainLoop = container.getInstanceOf<DeliverEventsUntilNoneLeft>();
    mainLoop.run();

    return 0;
}
