#include "Position.hpp"
using namespace ::ConwayGameOfLife;

Position::Position() : _x(), _y() {}
Position::Position(int x, int y) : _x(x), _y(y) {}

int Position::x() const { return _x; }
int Position::y() const { return _y; }

bool Position::operator==(const Position& that) const {
    return this->_x == that._x && this->_y == that._y;
}

bool Position::operator!=(const Position& that) const {
    return !(*this == that);
}


Position::InGrid::InGrid(const Position& position, int gridSize) :
    _position(position),
    _gridSize(gridSize)
{}

Position::InGrid Position::inGridOfSize(int size) const {
    return InGrid(*this, size);
}

Position::InGrid Position::InGridOfSize(int size) {
    return InGrid(Position(), size);
}

Position Position::InGrid::fromScalar(int scalar) const {
    return Position(scalar % _gridSize, scalar / _gridSize);
}

int Position::InGrid::toScalar() const {
    return _position.y() * _gridSize + _position.x();
}
