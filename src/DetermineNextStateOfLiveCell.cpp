#include "DetermineNextStateOfLiveCell.hpp"
using namespace ::ConwayGameOfLife;

DetermineNextStateOfLiveCell::DetermineNextStateOfLiveCell(
    IHandle<CellLived>& cellLivedHandler,
    IHandle<CellDied>& cellDiedHandler) :
    _cellLivedHandler(cellLivedHandler),
    _cellDiedHandler(cellDiedHandler)
{}

void DetermineNextStateOfLiveCell::handle(LivingNeighborsOfLiveCellCounted inEvent)
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

void DetermineNextStateOfLiveCell::cellStaysAliveAt(CartesianPosition location) const
{
    CellLived outEvent;
    outEvent.location = location;
    _cellLivedHandler.handle(outEvent);
}

void DetermineNextStateOfLiveCell::cellDiesAt(CartesianPosition location) const
{
    CellDied outEvent;
    outEvent.location = location;
    _cellDiedHandler.handle(outEvent);
}

