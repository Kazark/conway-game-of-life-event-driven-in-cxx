#ifndef _CONWAYGAMEOFLIFE_CELL_HPP_
#define _CONWAYGAMEOFLIFE_CELL_HPP_

#include "CartesianPosition.hpp"

namespace ConwayGameOfLife {
    class Grid;
	class Cell {
	public:
        Cell();
        Cell(Grid*);
        //void neighbors() const;
        bool isLiving;
        CartesianPosition location;
	private:
        Grid* _grid;
	};
}
#endif
