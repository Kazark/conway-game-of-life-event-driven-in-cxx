#ifndef _LIVINGNEIGHBORSOFDEADCELLCOUNTED_HPP_
#define _LIVINGNEIGHBORSOFDEADCELLCOUNTED_HPP_

#include "Position.hpp"
#include "Event.hpp"

namespace ConwayGameOfLife {
	struct LivingNeighborsOfDeadCellCounted : public ::EventArchitecture::Event {
        Position cellPosition;
        unsigned numberOfLivingNeighbors;
	};
}
#endif
