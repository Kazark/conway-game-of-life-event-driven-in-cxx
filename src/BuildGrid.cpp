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
    _gridData(nullptr)
{
}

BuildGrid::BuildGrid(int size) :
    _size(size),
    _numberOfCells(size*size),
    _numberSet(0),
    _gridData(new bool[_numberOfCells])
{
    reset();
}

BuildGrid::BuildGrid(BuildGrid&& that) :
    _size(that._size),
    _numberOfCells(that._numberOfCells),
    _numberSet(0),
    _gridData(that._gridData)
{
    that._gridData = nullptr;
}

BuildGrid& BuildGrid::operator=(BuildGrid&& that) {
    this->_size = that._size;
    this->_numberOfCells = that._numberOfCells;
    this->_numberSet = that._numberSet;
    this->_gridData = that._gridData;
    that._gridData = nullptr;
    return *this;
}

BuildGrid::~BuildGrid() {
    delete[] _gridData;
}

void BuildGrid::atPositionSetCellState(Position position, bool state) {
    int index = position.inGridOfSize(_size).toScalar();
    _gridData[index] = state;
    _numberSet++;
}

void BuildGrid::reset() {
    std::fill_n(_gridData, _numberOfCells, false);
    _numberSet = 0;
}

bool BuildGrid::finished() const {
    return _numberSet == _numberOfCells;
}

Grid BuildGrid::build() const {
    std::vector<bool> blech;
    for (int i = 0; i < _numberOfCells; ++i) {
        blech.push_back(_gridData[i]);
    }
    return Grid(blech);
}
