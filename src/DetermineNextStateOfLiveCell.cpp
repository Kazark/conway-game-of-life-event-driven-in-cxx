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

void DetermineNextStateOfLiveCell::cellStaysAliveAt(CartesianPosition position) const
{
    CellLived outEvent;
    outEvent.position = position;
    _cellLivedHandler.handle(outEvent);
}

void DetermineNextStateOfLiveCell::cellDiesAt(CartesianPosition position) const
{
    CellDied outEvent;
    outEvent.position = position;
    _cellDiedHandler.handle(outEvent);
}

