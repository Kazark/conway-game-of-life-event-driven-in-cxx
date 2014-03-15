#include "DetermineNextStateOfDeadCell.hpp"
using namespace ::ConwayGameOfLife;

DetermineNextStateOfDeadCell::DetermineNextStateOfDeadCell(
    IHandle<CellLived>& cellLivedHandler,
    IHandle<CellDied>& cellDiedHandler) :
    _cellLivedHandler(cellLivedHandler),
    _cellDiedHandler(cellDiedHandler)
{}

void DetermineNextStateOfDeadCell::handle(LivingNeighborsOfDeadCellCounted inEvent)
{
    if (inEvent.numberOfLivingNeighbors == 3)
    {
        cellComesToLifeAt(inEvent.cellLocation);
    }
    else
    {
        cellRemainsDeadAt(inEvent.cellLocation);
    }
}

void DetermineNextStateOfDeadCell::cellComesToLifeAt(Position position) const
{
    CellLived outEvent;
    outEvent.position = position;
    _cellLivedHandler.handle(outEvent);
}

void DetermineNextStateOfDeadCell::cellRemainsDeadAt(Position position) const
{
    CellDied outEvent;
    outEvent.position = position;
    _cellDiedHandler.handle(outEvent);
}

