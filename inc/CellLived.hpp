#ifndef _CONWAYGAMEOFLIFE_CELLLIVED_HPP_
#define _CONWAYGAMEOFLIFE_CELLLIVED_HPP_

#include "Position.hpp"
#include "Event.hpp"

namespace ConwayGameOfLife {
	struct CellLived : public ::EventArchitecture::Event {
        Position position;
	};
}
#endif
