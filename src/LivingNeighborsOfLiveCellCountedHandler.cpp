#include "LivingNeighborsOfLiveCellCountedHandler.hpp"
using namespace ::ConwayGameOfLife;

LivingNeighborsOfLiveCellCountedHandler::LivingNeighborsOfLiveCellCountedHandler(
    IHandle<CellLived>& cellLivedHandler,
    IHandle<CellDied>& cellDiedHandler) :
    _cellLivedHandler(cellLivedHandler),
    _cellDiedHandler(cellDiedHandler)
{}

void LivingNeighborsOfLiveCellCountedHandler::handle(LivingNeighborsOfLiveCellCounted inEvent)
{
    if (inEvent.numberOfLivingNeighbors < 2 || inEvent.numberOfLivingNeighbors > 3)
    {
        cellDiesAt(inEvent.cellLocation);
    }
    else
    {
        cellStaysAliveAt(inEvent.cellLocation);
    }
}

void LivingNeighborsOfLiveCellCountedHandler::cellStaysAliveAt(CartesianPosition location) const
{
    CellLived outEvent;
    outEvent.location = location;
    _cellLivedHandler.handle(outEvent);
}

void LivingNeighborsOfLiveCellCountedHandler::cellDiesAt(CartesianPosition location) const
{
    CellDied outEvent;
    outEvent.location = location;
    _cellDiedHandler.handle(outEvent);
}

