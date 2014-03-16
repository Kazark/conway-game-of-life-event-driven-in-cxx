#include "CountLivingNeighbors.hpp"
using namespace ::ConwayGameOfLife;
using namespace ::EventArchitecture;

CountLivingNeighbors::CountLivingNeighbors(IHandle<LivingNeighborsOfLiveCellCounted>& liveHandler,
                                           IHandle<LivingNeighborsOfDeadCellCounted>& deadHandler) :
    _liveCellEventHandler(liveHandler),
    _deadCellEventHandler(deadHandler)
{
}

void CountLivingNeighbors::handle(GenerationCompleted event) {
    for (auto cell : event.grid.iterator()) {
        if (cell.isLiving) {
            _liveCellEventHandler.handle(LivingNeighborsOfLiveCellCounted());
        } else {
            _deadCellEventHandler.handle(LivingNeighborsOfDeadCellCounted());
        }
    }
}
