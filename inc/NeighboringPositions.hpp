#ifndef _CONWAYGAMEOFLIFE_NEIGHBORINGPOSITIONS_HPP_
#define _CONWAYGAMEOFLIFE_NEIGHBORINGPOSITIONS_HPP_

#include "CartesianPosition.hpp"

namespace ConwayGameOfLife {
	class NeighboringPositions {
	public:
        NeighboringPositions(CartesianPosition);
        CartesianPosition northern() const;
        CartesianPosition northeastern() const;
        CartesianPosition eastern() const;
        CartesianPosition southeastern() const;
        CartesianPosition southern() const;
        CartesianPosition southwestern() const;
        CartesianPosition western() const;
        CartesianPosition northwestern() const;

	private:
        CartesianPosition my;
	};
}
#endif
