#ifndef _CONWAYGAMEOFLIFE_CARTESIANPOSITION_HPP_
#define _CONWAYGAMEOFLIFE_CARTESIANPOSITION_HPP_
namespace ConwayGameOfLife {
	class Position {
    public:
        Position();
        Position(int x, int y);

        bool operator==(const Position&) const;

        int x() const;
        int y() const;

    private:
        int _x;
        int _y;
	};
}
#endif
