#ifndef _CONWAYGAMEOFLIFE_LIVINGNEIGHBORSOFLIVECELLCOUNTED_HPP_
#define _CONWAYGAMEOFLIFE_LIVINGNEIGHBORSOFLIVECELLCOUNTED_HPP_

#include "CartesianPosition.hpp"
#include "Event.hpp"

namespace ConwayGameOfLife {
	struct LivingNeighborsOfLiveCellCounted : public ::EventArchitecture::Event {
        CartesianPosition cellLocation;
        unsigned numberOfLivingNeighbors;
	};
}
#endif
