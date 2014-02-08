#include "LivingNeighborsOfDeadCellCountedHandler.hpp"
using namespace ::ConwayGameOfLife;

LivingNeighborsOfDeadCellCountedHandler::LivingNeighborsOfDeadCellCountedHandler(
    IHandle<CellLived>& cellLivedHandler,
    IHandle<CellDied>& cellDiedHandler) :
    _cellLivedHandler(cellLivedHandler),
    _cellDiedHandler(cellDiedHandler)
{}

void LivingNeighborsOfDeadCellCountedHandler::handle(LivingNeighborsOfDeadCellCounted eventData)
{
    if (eventData.numberOfLivingNeighbors == 3)
    {
        _cellLivedHandler.handle(CellLived());
    }
    else
    {
        _cellDiedHandler.handle(CellDied());
    }
}
