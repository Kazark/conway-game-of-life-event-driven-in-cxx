#ifndef _CONWAYGAMEOFLIFE_NEIGHBORINGPOSITIONS_HPP_
#define _CONWAYGAMEOFLIFE_NEIGHBORINGPOSITIONS_HPP_

#include "CartesianPosition.hpp"

namespace ConwayGameOfLife {
	class NeighboringPositions {
	public:
        NeighboringPositions(CartesianPosition);
        CartesianPosition northern() const;

	private:
        CartesianPosition my;
	};
}
#endif
