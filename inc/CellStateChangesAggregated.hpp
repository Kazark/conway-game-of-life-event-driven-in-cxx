#ifndef _CONWAYGAMEOFLIFE_CELLSTATECHANGESAGGREGATED_HPP_
#define _CONWAYGAMEOFLIFE_CELLSTATECHANGESAGGREGATED_HPP_

#include "Event.hpp"
#include "Grid.hpp"
#include <initializer_list>

namespace ConwayGameOfLife {
	struct CellStateChangesAggregated: public ::EventArchitecture::Event {
        CellStateChangesAggregated(std::initializer_list<bool> data) :
            aggregateState(data)
        {}
        CellStateChangesAggregated(Grid grid) :
            aggregateState(grid)
        {}

        Grid aggregateState;
	};
}
#endif
