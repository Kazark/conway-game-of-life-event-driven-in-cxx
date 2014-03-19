#include "CountLivingNeighbors.hpp"
#include "LivingNeighborsOfDeadCellCounted.hpp"
#include "LivingNeighborsOfLiveCellCounted.hpp"
using namespace ::ConwayGameOfLife;
using namespace ::EventArchitecture;

CountLivingNeighbors::CountLivingNeighbors(IPublish& bus) :
    _bus(bus)
{
}

void CountLivingNeighbors::handle(GenerationCompleted event) {
    for (auto cell : event.grid.iterator()) {
        if (cell.isLiving) {
            _bus.publish(LivingNeighborsOfLiveCellCounted());
        } else {
            _bus.publish(LivingNeighborsOfDeadCellCounted());
        }
    }
}
