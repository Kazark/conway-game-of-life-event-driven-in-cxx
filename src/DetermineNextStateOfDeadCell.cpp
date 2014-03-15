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

void DetermineNextStateOfDeadCell::cellComesToLifeAt(CartesianPosition location) const
{
    CellLived outEvent;
    outEvent.location = location;
    _cellLivedHandler.handle(outEvent);
}

void DetermineNextStateOfDeadCell::cellRemainsDeadAt(CartesianPosition location) const
{
    CellDied outEvent;
    outEvent.location = location;
    _cellDiedHandler.handle(outEvent);
}

