#include "BuildGrid.hpp"
using namespace ::ConwayGameOfLife;

BuildGrid BuildGrid::OfSize(int size) {
    return BuildGrid(size);
}

BuildGrid::BuildGrid(int size) :
    _size(size),
    _numberSet(0)
{}

void BuildGrid::atPositionSetCellState(Position, bool) {
    _numberSet++;
}

bool BuildGrid::finished() const {
    return _numberSet == _size * _size;
}
