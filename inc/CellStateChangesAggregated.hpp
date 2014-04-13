#ifndef _CONWAYGAMEOFLIFE_CELLSTATECHANGESAGGREGATED_HPP_
#define _CONWAYGAMEOFLIFE_CELLSTATECHANGESAGGREGATED_HPP_

#include "Event.hpp"
#include "Grid.hpp"
#include "Cell.hpp"

namespace ConwayGameOfLife {
	struct CellStateChangesAggregated: public ::EventArchitecture::Event {
        CellStateChangesAggregated(Grid grid) :
            aggregateState(grid)
        {}

        Grid aggregateState;
	};
}
#endif
