#ifndef _CONWAYGAMEOFLIFE_CELLDIED_HPP_
#define _CONWAYGAMEOFLIFE_CELLDIED_HPP_

#include "CartesianPosition.hpp"

namespace ConwayGameOfLife {
	struct CellDied {
        unsigned GenerationNumber;
        CartesianPosition location;
	};
}
#endif
