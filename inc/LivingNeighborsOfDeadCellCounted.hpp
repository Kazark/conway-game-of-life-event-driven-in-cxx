#ifndef _LIVINGNEIGHBORSOFDEADCELLCOUNTED_HPP_
#define _LIVINGNEIGHBORSOFDEADCELLCOUNTED_HPP_

#include "CartesianPosition.hpp"
#include "Event.hpp"

namespace ConwayGameOfLife {
	struct LivingNeighborsOfDeadCellCounted : public ::EventArchitecture::Event {
        CartesianPosition cellLocation;
        unsigned numberOfLivingNeighbors;
	};
}
#endif
