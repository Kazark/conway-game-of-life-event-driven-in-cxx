#ifndef _CONWAYGAMEOFLIFE_LIVINGNEIGHBORSOFLIVECELLCOUNTED_HPP_
#define _CONWAYGAMEOFLIFE_LIVINGNEIGHBORSOFLIVECELLCOUNTED_HPP_

#include "Position.hpp"
#include "Event.hpp"

namespace ConwayGameOfLife {
	struct LivingNeighborsOfLiveCellCounted : public ::EventArchitecture::Event {
        Position cellPosition;
        unsigned numberOfLivingNeighbors;
	};
}
#endif
