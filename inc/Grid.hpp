#ifndef _CONWAYGAMEOFLIFE_GRID_HPP_
#define _CONWAYGAMEOFLIFE_GRID_HPP_

#include "ArrayIterator.hpp"
#include "FixedLengthArray.hpp"

namespace ConwayGameOfLife {
    class Cell;
	class Grid {
	public:
        Grid(FixedLengthArray<bool>);

        ArrayIterator<const Cell&, Grid> iterator() const;

        int size() const;
        int numberOfCells() const;        

        bool operator==(const Grid&) const;
        bool operator!=(const Grid&) const;

	private:
        const Cell& operator[](int) const;
        int length() const;

        friend class ArrayIterator<const Cell&, Grid>;

        int _size;
        int _numberOfCells;
        FixedLengthArray<Cell> _gridData;
	};
}
#endif
