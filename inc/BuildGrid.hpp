#ifndef _CONWAYGAMEOFLIFE_BUILDGRID_HPP_
#define _CONWAYGAMEOFLIFE_BUILDGRID_HPP_

#include "Grid.hpp"
#include "Position.hpp"
#include "FixedLengthArray.hpp"

namespace ConwayGameOfLife {
	class BuildGrid {
	public:
        static BuildGrid OfSize(int);
        BuildGrid();

        void atPositionSetCellState(Position, bool);
        bool finished() const;
        void reset();
        Grid build() const;

	private:
        BuildGrid(int size);

        int _size;
        int _numberOfCells;
        int _numberSet;

        FixedLengthArray<bool> _gridData;
	};
}
#endif
