#ifndef _LIVINGNEIGHBORSOFDEADCELLCOUNTED_HPP_
#define _LIVINGNEIGHBORSOFDEADCELLCOUNTED_HPP_

#include "CartesianPosition.hpp"

namespace ConwayGameOfLife {
	struct LivingNeighborsOfDeadCellCounted {
        CartesianPosition cellLocation;
        unsigned numberOfLivingNeighbors;
	};
}
#endif
