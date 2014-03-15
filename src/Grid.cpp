#include "Grid.hpp"
#include "Cell.hpp"
using namespace ::ConwayGameOfLife;

Grid::Grid(std::vector<bool> data) :
    _gridData(data.size())
{
    auto length = _gridData.size();
    for (auto i = 0U; i < length; i++)
    {
        Cell cell(this);
        cell.isLiving = data[i];
        cell.position = Position(i % length, i / length);
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
