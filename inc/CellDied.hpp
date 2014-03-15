#ifndef _CONWAYGAMEOFLIFE_CELLDIED_HPP_
#define _CONWAYGAMEOFLIFE_CELLDIED_HPP_

#include "CartesianPosition.hpp"
#include "Event.hpp"

namespace ConwayGameOfLife {
	struct CellDied : public ::EventArchitecture::Event {
        CartesianPosition position;
	};
}
#endif
