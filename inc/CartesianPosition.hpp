#ifndef _CONWAYGAMEOFLIFE_CARTESIANPOSITION_HPP_
#define _CONWAYGAMEOFLIFE_CARTESIANPOSITION_HPP_
namespace ConwayGameOfLife {
	struct CartesianPosition {
        int x;
        int y;

        CartesianPosition() : x(), y() {}
        CartesianPosition(int x, int y) : x(x), y(y) {}

        bool operator==(const CartesianPosition& that) const {
            return this->x == that.x && this->y == that.y;
        }
	};
}
#endif
