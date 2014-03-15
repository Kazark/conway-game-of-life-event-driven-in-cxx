#ifndef _CONWAYGAMEOFLIFE_CELL_HPP_
#define _CONWAYGAMEOFLIFE_CELL_HPP_

#include "Position.hpp"

namespace ConwayGameOfLife {
    class Grid;
	class Cell {
	public:
        Cell();
        Cell(Grid*);
        //void neighbors() const;
        bool isLiving;
        Position position;
	private:
        Grid* _grid;
	};
}
#endif
