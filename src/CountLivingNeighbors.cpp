#include "CountLivingNeighbors.hpp"
#include "LivingNeighborsOfCellCounted.hpp"
#include "NeighboringPositions.hpp"
using namespace ::ConwayGameOfLife;
using namespace ::EventArchitecture;

CountLivingNeighbors::CountLivingNeighbors(IPublish& bus) :
    _bus(bus)
{
}

void CountLivingNeighbors::handle(GenerationCompleted inEvent) {
    for (auto cell : inEvent.grid.iterator()) {
        LivingNeighborsOfCellCounted outEvent;
        outEvent.isCellAlive = cell.isLiving;
        outEvent.cellPosition = cell.position;
        outEvent.numberOfLivingNeighbors = 0;
        for (auto neighboringPosition : NeighboringPositions(cell.position).iterator())
        {
            if (inEvent.grid.cellAt(neighboringPosition).isLiving) {
                outEvent.numberOfLivingNeighbors++;
            }
        }
        _bus.publish(outEvent);
    }
}
