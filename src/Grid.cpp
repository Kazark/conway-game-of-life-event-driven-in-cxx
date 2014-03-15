#include "Grid.hpp"
#include "Cell.hpp"
using namespace ::ConwayGameOfLife;
#include <cmath>

Grid::Grid(std::vector<bool> data) :
    _size(sqrt(data.size())),
    _length(_size*_size),
    _gridData(_length)
{
    for (auto i = 0; i < _length; i++)
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

int Grid::length() const
{
    return (int)_gridData.size(); // TODO test-drive this contant out of here!
}
