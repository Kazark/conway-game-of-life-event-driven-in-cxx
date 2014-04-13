#include "AggregateCellStateChanges.hpp"
#include "CellStateChangesAggregated.hpp"
using namespace ::ConwayGameOfLife;
using namespace ::EventArchitecture;

AggregateCellStateChanges::AggregateCellStateChanges(::EventArchitecture::IPublish& bus) :
    _bus(bus),
    _buildGrid()
{}

void AggregateCellStateChanges::handle(GameInitiated event) {
    _buildGrid = BuildGrid::OfSize(event.grid.size());
}

void AggregateCellStateChanges::handle(CellStateChanged event) {
    _buildGrid.atPositionSetCellState(event.position, event.cellIsNowAlive);
    if (_buildGrid.finished()) {
        _bus.publish(CellStateChangesAggregated(_buildGrid.build()));
        _buildGrid.reset();
    }
}
