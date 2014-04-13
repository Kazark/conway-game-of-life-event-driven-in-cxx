#ifndef _CONWAYGAMEOFLIFE_BUILDGRID_HPP_
#define _CONWAYGAMEOFLIFE_BUILDGRID_HPP_

#include "Grid.hpp"
#include "Position.hpp"

#include <vector>

namespace ConwayGameOfLife {
	class BuildGrid {
	public:
        static BuildGrid OfSize(int);
        BuildGrid();
        ~BuildGrid();
        BuildGrid(BuildGrid&&);
        BuildGrid(const BuildGrid&) = delete;
        BuildGrid& operator=(const BuildGrid&) = delete;
        BuildGrid& operator=(BuildGrid&&);

        void atPositionSetCellState(Position, bool);
        bool finished() const;
        void reset();
        Grid build() const;

	private:
        BuildGrid(int size);

        int _size;
        int _numberOfCells;
        int _numberSet;
        bool* _gridData;
	};
}
#endif
