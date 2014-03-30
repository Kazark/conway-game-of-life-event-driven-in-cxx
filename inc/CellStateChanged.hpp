#ifndef _CONWAYGAMEOFLIFE_CELLSTATECHANGED_HPP_
#define _CONWAYGAMEOFLIFE_CELLSTATECHANGED_HPP_

#include "Position.hpp"
#include "Event.hpp"

namespace ConwayGameOfLife {
	struct CellStateChanged: public ::EventArchitecture::Event {
        Position position;
        bool cellIsNowAlive;
	};
}
#endif
