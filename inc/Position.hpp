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

        class InGrid {
        public:
            Position fromScalar(int);

        private:
            InGrid(const Position&, int);
            friend class Position;

            const Position& _position;
            int _gridSize;
        };

        InGrid inGridOfSize(int) const;
        static InGrid InGridOfSize(int);

    private:
        int _x;
        int _y;
	};
}
#endif
