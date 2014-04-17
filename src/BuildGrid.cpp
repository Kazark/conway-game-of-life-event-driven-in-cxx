#include "BuildGrid.hpp"
#include "Cell.hpp"
using namespace ::ConwayGameOfLife;

#include <algorithm>

BuildGrid BuildGrid::OfSize(int size) {
    return BuildGrid(size);
}

BuildGrid::BuildGrid() :
    _size(0),
    _numberOfCells(0),
    _numberSet(0),
    _gridData()
{
}

BuildGrid::BuildGrid(int size) :
    _size(size),
    _numberOfCells(size*size),
    _numberSet(0),
    _gridData(_numberOfCells)
{
}

void BuildGrid::atPositionSetCellState(Position position, bool state) {
    int index = position.inGridOfSize(_size).toScalar();
    _gridData[index] = state;
    _numberSet++;
}

void BuildGrid::reset() {
    _gridData = FixedLengthArray<bool>(_numberOfCells);
    _numberSet = 0;
}

bool BuildGrid::finished() const {
    return _numberSet == _numberOfCells;
}

Grid BuildGrid::build() const {
    return _gridData;
}
