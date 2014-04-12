#ifndef _CONWAYGAMEOFLIFE_BUILDGRID_HPP_
#define _CONWAYGAMEOFLIFE_BUILDGRID_HPP_

#include "Grid.hpp"
#include "Position.hpp"

namespace ConwayGameOfLife {
	class BuildGrid {
	public:
        static BuildGrid OfSize(int);

        void atPositionSetCellState(Position, bool);

        bool finished() const;

	private:
        BuildGrid(int size);

        int _size;
        int _numberSet;
	};
}
#endif
