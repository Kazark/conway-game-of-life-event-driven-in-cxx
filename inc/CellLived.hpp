#ifndef _CONWAYGAMEOFLIFE_CELLLIVED_HPP_
#define _CONWAYGAMEOFLIFE_CELLLIVED_HPP_

#include "CartesianPosition.hpp"

namespace ConwayGameOfLife {
	struct CellLived {
        unsigned GenerationNumber;
        CartesianPosition location;
	};
}
#endif
