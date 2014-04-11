#include "Grid.hpp"
#include "Cell.hpp"
using namespace ::ConwayGameOfLife;
#include <cmath>

Grid::Grid(std::vector<bool> data) :
    _size(sqrt(data.size())),
    _numberOfCells(_size*_size),
    _gridData(_numberOfCells)
{
    for (auto i = 0; i < _numberOfCells; i++)
    {
        Cell cell(this);
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
