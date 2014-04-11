#include "AggregateCellStateChanges.hpp"
#include "CellStateChangesAggregated.hpp"
using namespace ::ConwayGameOfLife;
using namespace ::EventArchitecture;

AggregateCellStateChanges::AggregateCellStateChanges(::EventArchitecture::IPublish& bus) :
    _bus(bus)
{}

void AggregateCellStateChanges::handle(CellStateChanged) {
}

void AggregateCellStateChanges::handle(GameInitiated) {
}
