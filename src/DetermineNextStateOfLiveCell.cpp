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
        cellDiesAt(inEvent.cellPosition);
    }
    else
    {
        cellStaysAliveAt(inEvent.cellPosition);
    }
}

void DetermineNextStateOfLiveCell::cellStaysAliveAt(Position position) const
{
    CellLived outEvent;
    outEvent.position = position;
    _cellLivedHandler.handle(outEvent);
}

void DetermineNextStateOfLiveCell::cellDiesAt(Position position) const
{
    CellDied outEvent;
    outEvent.position = position;
    _cellDiedHandler.handle(outEvent);
}

