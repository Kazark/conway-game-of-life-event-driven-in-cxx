#include "DetermineNextCellState.hpp"
#include "CellStateChanged.hpp"
using namespace ::ConwayGameOfLife;
using namespace ::EventArchitecture;

DetermineNextCellState::DetermineNextCellState(IPublish& bus) :
    _bus(bus)
{}

void DetermineNextCellState::handle(LivingNeighborsOfCellCounted inEvent) {
    CellStateChanged outEvent;
    outEvent.position = inEvent.cellPosition;
    outEvent.cellIsNowAlive = (inEvent.numberOfLivingNeighbors == 3);
    _bus.publish(outEvent);
}
