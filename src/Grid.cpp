#include "Grid.hpp"
using namespace ::ConwayGameOfLife;
#include <cmath>

Grid::Grid() :
    _size(0),
    _numberOfCells(0),
    _gridData()
{
}

Grid::Grid(FixedLengthArray<bool> data) :
    _size(sqrt(data.length())),
    _numberOfCells(_size*_size),
    _gridData(_numberOfCells)
{
    for (auto i = 0; i < _numberOfCells; i++)
    {
        Cell cell;
        cell.isLiving = data[i];
        cell.position = Position::InGridOfSize(_size).fromScalar(i);
        _gridData[i] = cell;
    }
}

ArrayIterator<const Cell&, Grid> Grid::iterator() const
{
    return ArrayIterator<const Cell&, Grid>(*this);
}

const Cell& Grid::operator[](int i) const
{
    return _gridData[i];
}

bool Grid::operator==(const Grid& that) const {
    if (this->size() != that.size()) {
        return false;
    }

    for (int i = 0; i < numberOfCells(); ++i) {
        if ((*this)[i].isLiving != that[i].isLiving) {
            return false;
        }
    }

    return true;
}

Cell Grid::cellAt(Position position) const
{
    auto positionInGrid = position.inGridOfSize(_size);
    if (positionInGrid.isOutOfBounds())
    {
        Cell cell;
        cell.position = position;
        cell.isLiving = false;
        return cell;
    }
    return _gridData[positionInGrid.toScalar()];
}

bool Grid::operator!=(const Grid& that) const {
    return !(*this == that);
}

int Grid::size() const
{
    return _size;
}

int Grid::numberOfCells() const {
    return _numberOfCells;
}

int Grid::length() const
{
    return numberOfCells();
}
