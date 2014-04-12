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
    std::fill_n(_gridData, size*size, false);
}

void BuildGrid::atPositionSetCellState(Position position, bool state) {
    int index = position.inGridOfSize(_size).toScalar();
    _gridData[index] = state;
    _numberSet++;
}

bool BuildGrid::finished() const {
    return _numberSet == _size * _size;
}

Grid BuildGrid::build() {
    std::vector<bool> blech;
    for (int i = 0; i < _size*_size; ++i) {
        blech.push_back(_gridData[i]);
    }
    return Grid(blech);
}
