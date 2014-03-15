#ifndef _CONWAYGAMEOFLIFE_CARTESIANPOSITION_HPP_
#define _CONWAYGAMEOFLIFE_CARTESIANPOSITION_HPP_
namespace ConwayGameOfLife {
	struct Position {
        int x;
        int y;

        Position() : x(), y() {}
        Position(int x, int y) : x(x), y(y) {}

        bool operator==(const Position& that) const {
            return this->x == that.x && this->y == that.y;
        }
	};
}
#endif
