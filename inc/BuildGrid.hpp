#ifndef _CONWAYGAMEOFLIFE_BUILDGRID_HPP_
#define _CONWAYGAMEOFLIFE_BUILDGRID_HPP_

#include "Grid.hpp"

namespace ConwayGameOfLife {
	class BuildGrid {
	public:
        static BuildGrid OfSize(int);

        bool finished();
	private:
	};
}
#endif
