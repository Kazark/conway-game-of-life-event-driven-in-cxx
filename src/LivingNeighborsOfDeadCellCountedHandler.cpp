#include "LivingNeighborsOfDeadCellCountedHandler.hpp"
using namespace ::ConwayGameOfLife;

LivingNeighborsOfDeadCellCountedHandler::LivingNeighborsOfDeadCellCountedHandler(
    IHandle<CellLived>& cellLivedHandler,
    IHandle<CellDied>& cellDiedHandler) :
    _cellLivedHandler(cellLivedHandler),
    _cellDiedHandler(cellDiedHandler)
{}

void LivingNeighborsOfDeadCellCountedHandler::handle(LivingNeighborsOfDeadCellCounted inEvent)
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

void LivingNeighborsOfDeadCellCountedHandler::cellComesToLifeAt(CartesianPosition location) const
{
    CellLived outEvent;
    outEvent.location = location;
    _cellLivedHandler.handle(outEvent);
}

void LivingNeighborsOfDeadCellCountedHandler::cellRemainsDeadAt(CartesianPosition location) const
{
    CellDied outEvent;
    outEvent.location = location;
    _cellDiedHandler.handle(outEvent);
}

