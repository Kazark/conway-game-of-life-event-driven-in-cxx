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
    outEvent.cellIsNowAlive = isNextStateOfCellLiving(inEvent);
    _bus.publish(outEvent);
}

bool DetermineNextCellState::isNextStateOfCellLiving(LivingNeighborsOfCellCounted event) const {
    return event.numberOfLivingNeighbors == 3 ||
          (event.numberOfLivingNeighbors == 2 && event.isCellAlive);
}
