#include "CountLivingNeighbors.hpp"
#include "LivingNeighborsOfCellCounted.hpp"
using namespace ::ConwayGameOfLife;
using namespace ::EventArchitecture;

CountLivingNeighbors::CountLivingNeighbors(IPublish& bus) :
    _bus(bus)
{
}

void CountLivingNeighbors::handle(GenerationCompleted event) {
    for (auto cell : event.grid.iterator()) {
        LivingNeighborsOfCellCounted event;
        event.isCellAlive = cell.isLiving;
        event.cellPosition = cell.position;
        _bus.publish(event);
    }
}
