#ifndef _CONWAYGAMEOFLIFE_BUILDGRID_HPP_
#define _CONWAYGAMEOFLIFE_BUILDGRID_HPP_

#include "Grid.hpp"
#include "Position.hpp"

#include <vector>

namespace ConwayGameOfLife {
	class BuildGrid {
	public:
        static BuildGrid OfSize(int);
        ~BuildGrid() {
            delete[] _gridData;
        }

        void atPositionSetCellState(Position, bool);
        bool finished() const;
        Grid build();

	private:
        BuildGrid(int size);

        int _size;
        int _numberSet;
        bool* _gridData;
	};
}
#endif
