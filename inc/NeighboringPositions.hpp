#ifndef _CONWAYGAMEOFLIFE_NEIGHBORINGPOSITIONS_HPP_
#define _CONWAYGAMEOFLIFE_NEIGHBORINGPOSITIONS_HPP_

#include "Position.hpp"

namespace ConwayGameOfLife {
	class NeighboringPositions {
	public:
        NeighboringPositions(Position);
        Position northern() const;
        Position northeastern() const;
        Position eastern() const;
        Position southeastern() const;
        Position southern() const;
        Position southwestern() const;
        Position western() const;
        Position northwestern() const;

	private:
        Position my;
	};
}
#endif
