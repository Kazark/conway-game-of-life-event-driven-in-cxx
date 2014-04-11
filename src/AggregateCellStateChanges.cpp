#include "AggregateCellStateChanges.hpp"
#include "CellStateChangesAggregated.hpp"
using namespace ::ConwayGameOfLife;
using namespace ::EventArchitecture;

AggregateCellStateChanges::AggregateCellStateChanges(::EventArchitecture::IPublish& bus) :
    _bus(bus),
    _numberToAggregate(0),
    _numberAggregated(0)
{}

void AggregateCellStateChanges::handle(GameInitiated event) {
    _numberToAggregate = event.grid.numberOfCells();
}

void AggregateCellStateChanges::handle(CellStateChanged) {
    _numberAggregated++;
    if (_numberAggregated == _numberToAggregate) {
        _bus.publish(CellStateChangesAggregated());
        _numberAggregated = 0;
    }
}
