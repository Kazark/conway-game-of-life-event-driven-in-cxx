#ifndef _CONWAYGAMEOFLIFE_GAMEINITIATED_HPP_
#define _CONWAYGAMEOFLIFE_GAMEINITIATED_HPP_

#include "Event.hpp"
#include "Grid.hpp"

namespace ConwayGameOfLife {
	struct GameInitiated : public ::EventArchitecture::Event {
        GameInitiated(std::initializer_list<bool> grid) : grid(grid) {}
        GameInitiated(Grid grid) : grid(grid) {}
        Grid grid;
	};
}
#endif
