#ifndef _CONWAYGAMEOFLIFE_GRID_HPP_
#define _CONWAYGAMEOFLIFE_GRID_HPP_

#include "ArrayIterator.hpp"

#include <vector>
#include <initializer_list>

namespace ConwayGameOfLife {
    class Cell;
	class Grid {
	public:
        Grid(std::vector<bool>);

        ArrayIterator<const Cell&, Grid> iterator() const;

        int size() const;
        int numberOfCells() const;        

	private:
        const Cell& operator[](int) const;
        int length() const;

        friend class ArrayIterator<const Cell&, Grid>;

        int _size;
        int _numberOfCells;
        std::vector<Cell> _gridData;
	};
}
#endif
