#include "BuildGrid.hpp"
#include "Cell.hpp"
using namespace ::ConwayGameOfLife;

#include <algorithm>

BuildGrid BuildGrid::OfSize(int size) {
    return BuildGrid(size);
}

BuildGrid::BuildGrid(int size) :
    _size(size),
    _numberSet(0),
    _gridData(new bool[size*size])
{
    reset();
}

void BuildGrid::atPositionSetCellState(Position position, bool state) {
    int index = position.inGridOfSize(_size).toScalar();
    _gridData[index] = state;
    _numberSet++;
}

void BuildGrid::reset() {
    std::fill_n(_gridData, _size*_size, false);
    _numberSet = 0;
}

bool BuildGrid::finished() const {
    return _numberSet == _size * _size;
}

Grid BuildGrid::build() const {
    std::vector<bool> blech;
    for (int i = 0; i < _size*_size; ++i) {
        blech.push_back(_gridData[i]);
    }
    return Grid(blech);
}
